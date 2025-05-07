#ifndef RUBY_ADAPTER_H
#define RUBY_ADAPTER_H
#include <string>
#include <stdexcept>
#include <functional>
#include "ruby_values.h"
#include <type_traits>

extern VALUE rb_eRGRAYError;

#define NUM2FLT(val) static_cast<float>(NUM2DBL(val))

namespace rb {
    template <typename T>
    struct log {
        static constexpr const char* classname = "Object";
    };

    namespace detail {
        template <typename...>
        using void_t = void;
    }

    template <typename T, typename = void>
    struct has_instance_method : std::false_type {};

    template <typename T>
    struct has_instance_method<T, detail::void_t<decltype(std::declval<T>().instance())>> : std::true_type {};

    using ErrorCallback = std::function<void(const std::string&)>;

    [[nodiscard]] inline bool is_disposed(VALUE self) {
        return RDATA(self)->data == nullptr;
    }

    template <typename T, bool Raise = true>
    [[nodiscard]] std::string check_disposed(VALUE self) {
        if (is_disposed(self)) {
            std::string error = "Disposed " + std::string(log<T>::classname) + ".";
            if constexpr (Raise) {
                rb_raise(rb_eRGRAYError, "%s", error.c_str());
            }
            return error;
        }
        return {};
    }

    template <typename T>
    [[nodiscard]] T* get_ptr(VALUE self) {
        T* ptr = nullptr;
        Data_Get_Struct(self, T, ptr);
        return ptr;
    }

    template <typename T>
    [[nodiscard]] T& get(VALUE self) {
        if (auto error = check_disposed<T>(self); !error.empty()) {
            throw std::runtime_error(error);
        }
        return *get_ptr<T>(self);
    }

    [[nodiscard]] inline bool type_mismatch(VALUE self, VALUE expected_type) {
        return rb_obj_is_kind_of(self, expected_type) != Qtrue;
    }

    template <typename T, bool Raise = true>
    [[nodiscard]] std::string check_type(VALUE self, VALUE expected_type) {
        if (type_mismatch(self, expected_type)) {
            std::string error = "Expected " + std::string(log<T>::classname) +
                                " got " + RSTRING_PTR(rb_class_name(CLASS_OF(self))) + ".";
            if constexpr (Raise) {
                rb_raise(rb_eTypeError, "%s", error.c_str());
            }
            return error;
        }
        return {};
    }

    template <class T>
    [[nodiscard]] T* get_safe(VALUE self, VALUE expected_type) {
        if (type_mismatch(self, expected_type)) {
            rb_raise(rb_eTypeError, "Type mismatch: expected an instance of %s, but got %s.",
                    RSTRING_PTR(rb_class_name(expected_type)),
                    RSTRING_PTR(rb_class_name(CLASS_OF(self))));
            return nullptr;
        }

        if (is_disposed(self)) {
            rb_raise(rb_eTypeError, "Invalid access: expected an active %s, but the object has been disposed.",
                    RSTRING_PTR(rb_class_name(expected_type)));
            return nullptr;
        }

        auto* result = get_ptr<T>(self);
        if constexpr (has_instance_method<T>::value) {
            if (!result || !result->instance()) {
                rb_raise(rb_eTypeError, "Uninitialized object: expected a properly initialized %s, but got an invalid instance.",
                        RSTRING_PTR(rb_class_name(expected_type)));
                return nullptr;
            }
        }

        return result;
    }

	template <class T>
	void free(void* data) {
		delete reinterpret_cast<T*>(data);
	}

	template <class T>
	void mark(T* data) {}

	// Allocates and wraps a new instance of T (default constructor)
	template <class T>
	VALUE alloc(VALUE klass) {
		return Data_Wrap_Struct(klass, mark<T>, free<T>, new T());
	}

    // Wraps an existing pointer to T (takes ownership)
    template <class T>
    VALUE alloc_ptr(VALUE klass, T* ptr) {
        return Data_Wrap_Struct(klass, mark<T>, free<T>, ptr);
    }

    // Copies a T value and wraps the new heap-allocated instance
    template <class T>
    VALUE alloc_copy(VALUE klass, const T& value) {
        return Data_Wrap_Struct(klass, mark<T>, free<T>, new T(value));
    }

    // Wraps a raw pointer in a Ruby object without taking ownership.
    // This ensures the Ruby GC does *not* attempt to free the memory.
    // Useful when the lifetime of the pointed-to object is managed elsewhere.
    //
    // Example: Wrapping an inner member (Texture2D) of a parent struct (RenderTexture2D),
    // where the parent is already managed by Ruby.
    //
    // struct RenderTexture2D {
    //     Texture2D texture;
    // };
    //
    // auto& wrapper = rb::get<RenderTexture2D>(self);
    // return rb::alloc_borrowed<Texture2D>(rb_cSprite, &wrapper.texture);
    //
    // In this case, `&wrapper.texture` remains valid as long as `wrapper` lives,
    // and Ruby will not double-free it.
    //
    // `klass` - Ruby class to wrap the pointer in.
    // `ptr`   - Raw pointer to the object (must outlive the Ruby wrapper).
    template <class T>
    VALUE alloc_borrowed(VALUE klass, T* ptr) {
        return Data_Wrap_Struct(klass, nullptr, nullptr, ptr);
    }

	template <class T>
	VALUE raw_dispose(VALUE self) {
        if (is_disposed(self)) {
            return Qnil;
        }
        delete get_ptr<T>(self);
        RDATA(self)->data = nullptr;
        return Qnil;
	}

	template <class T>
	VALUE dispose(VALUE self) {
		// Do not soft crash if we try to dispose an already disposed object (dispose tolerance)
        if (is_disposed(self)) {
            return Qnil;
        }
        auto& obj = get<T>(self);
        obj->detach();
        return raw_dispose<T>(self);
	}
}
#endif
