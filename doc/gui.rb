# @!method enable
#   Enable gui controls (global state)
#   @param void [void]
#   @return [void]

# @!method disable
#   Disable gui controls (global state)
#   @param void [void]
#   @return [void]

# @!method lock
#   Lock gui controls (global state)
#   @param void [void]
#   @return [void]

# @!method unlock
#   Unlock gui controls (global state)
#   @param void [void]
#   @return [void]

# @!method locked?
#   Check if gui is locked (global state)
#   @param void [void]
#   @return [Boolean]

# @!method alpha=
#   Set gui controls alpha (global state), alpha goes from 0.0f to 1.0f
#   @param alpha [Float]
#   @return [void]

# @!method state=
#   Set gui state (global state)
#   @param state [Integer]
#   @return [void]

# @!method state
#   Get gui state (global state)
#   @param void [void]
#   @return [Integer]

# @!method set_style
#   Set one style property
#   @param control [Integer]
#   @param property [Integer]
#   @param value [Integer]
#   @return [void]

# @!method style
#   Get one style property
#   @param control [Integer]
#   @param property [Integer]
#   @return [Integer]

# @!method load_style
#   Load style file over global style variable (.rgs)
#   @param fileName [String]
#   @return [void]

# @!method load_default_style
#   Load style default over global style
#   @param void [void]
#   @return [void]

# @!method enable_tooltip
#   Enable gui tooltips (global state)
#   @param void [void]
#   @return [void]

# @!method disable_tooltip
#   Disable gui tooltips (global state)
#   @param void [void]
#   @return [void]

# @!method tooltip=
#   Set tooltip string
#   @param tooltip [String]
#   @return [void]

# @!method window_box
#   Window Box control, shows a window that can be closed
#   @param bounds [Rect]
#   @param title [String]
#   @return [Integer]

# @!method group_box
#   Group Box control with text name
#   @param bounds [Rect]
#   @param text [String]
#   @return [Integer]

# @!method line
#   Line separator control, could contain text
#   @param bounds [Rect]
#   @param text [String]
#   @return [Integer]

# @!method panel
#   Panel control, useful to group controls
#   @param bounds [Rect]
#   @param text [String]
#   @return [Integer]

# @!method tab_bar
#   Tab Bar control, returns TAB to be closed or -1
#   @param bounds [Rect]
#   @param *text [String]
#   @param count [Integer]
#   @param active [Integer]
#   @return [Integer]

# @!method scroll_panel
#   Scroll Panel control
#   @param bounds [Rect]
#   @param text [String]
#   @param content [Rect]
#   @param scroll [Array]
#   @param view [Array]
#   @return [Integer]

# @!method label
#   Label control
#   @param bounds [Rect]
#   @param text [String]
#   @return [Integer]

# @!method button
#   Button control, returns true when clicked
#   @param bounds [Rect]
#   @param text [String]
#   @return [Integer]

# @!method label_button
#   Label button control, returns true when clicked
#   @param bounds [Rect]
#   @param text [String]
#   @return [Integer]

# @!method toogle
#   Toggle Button control
#   @param bounds [Rect]
#   @param text [String]
#   @param active [Boolean]
#   @return [Integer]

# @!method toogle_group
#   Toggle Group control
#   @param bounds [Rect]
#   @param text [String]
#   @param active [Integer]
#   @return [Integer]

# @!method toogle_slider
#   Toggle Slider control
#   @param bounds [Rect]
#   @param text [String]
#   @param active [Integer]
#   @return [Integer]

# @!method check_box
#   Check Box control, returns true when active
#   @param bounds [Rect]
#   @param text [String]
#   @param checked [Boolean]
#   @return [Integer]

# @!method combo_box
#   Combo Box control
#   @param bounds [Rect]
#   @param text [String]
#   @param active [Integer]
#   @return [Integer]

# @!method dropdown_box
#   Dropdown Box control
#   @param bounds [Rect]
#   @param text [String]
#   @param active [Integer]
#   @param editMode [Boolean]
#   @return [Integer]

# @!method spinner
#   Spinner control
#   @param bounds [Rect]
#   @param text [String]
#   @param value [Integer]
#   @param minValue [Integer]
#   @param maxValue [Integer]
#   @param editMode [Boolean]
#   @return [Integer]

# @!method value_box
#   Value Box control, updates input text with numbers
#   @param bounds [Rect]
#   @param text [String]
#   @param value [Integer]
#   @param minValue [Integer]
#   @param maxValue [Integer]
#   @param editMode [Boolean]
#   @return [Integer]

# @!method value_box_float
#   Value box control for float values
#   @param bounds [Rect]
#   @param text [String]
#   @param textValue [String]
#   @param value [Float]
#   @param editMode [Boolean]
#   @return [Integer]

# @!method text_box
#   Text Box control, updates input text
#   @param bounds [Rect]
#   @param text [String]
#   @param textSize [Integer]
#   @param editMode [Boolean]
#   @return [Integer]

# @!method status_bar
#   Status Bar control, shows info text
#   @param bounds [Rect]
#   @param text [String]
#   @return [Integer]

# @!method dummy_rec
#   Dummy control for placeholders
#   @param bounds [Rect]
#   @param text [String]
#   @return [Integer]

# @!method grid
#   Grid control
#   @param bounds [Rect]
#   @param text [String]
#   @param spacing [Float]
#   @param subdivs [Integer]
#   @param mouseCell [Array]
#   @return [Integer]

# @!method list_view
#   List View control
#   @param bounds [Rect]
#   @param text [String]
#   @param scrollIndex [Integer]
#   @param active [Integer]
#   @return [Integer]

# @!method message_box
#   Message Box control, displays a message
#   @param bounds [Rect]
#   @param title [String]
#   @param message [String]
#   @param buttons [String]
#   @return [Integer]

# @!method text_input_box
#   Text Input Box control, ask for text, supports secret
#   @param bounds [Rect]
#   @param title [String]
#   @param message [String]
#   @param buttons [String]
#   @param text [String]
#   @param textMaxSize [Integer]
#   @param secretViewActive [Boolean]
#   @return [Integer]

# @!method color_picker
#   Color Picker control (multiple color controls)
#   @param bounds [Rect]
#   @param text [String]
#   @param color [Array]
#   @return [Integer]

# @!parse STATE_NORMAL = INT2NUM(STATE_NORMAL
#   @return [Integer]

# @!parse STATE_FOCUSED = INT2NUM(STATE_FOCUSED
#   @return [Integer]

# @!parse STATE_PRESSED = INT2NUM(STATE_PRESSED
#   @return [Integer]

# @!parse STATE_DISABLED = INT2NUM(STATE_DISABLED
#   @return [Integer]

# @!parse TEXT_ALIGN_LEFT = INT2NUM(TEXT_ALIGN_LEFT
#   @return [Integer]

# @!parse TEXT_ALIGN_CENTER = INT2NUM(TEXT_ALIGN_CENTER
#   @return [Integer]

# @!parse TEXT_ALIGN_RIGHT = INT2NUM(TEXT_ALIGN_RIGHT
#   @return [Integer]

# @!parse TEXT_ALIGN_TOP = INT2NUM(TEXT_ALIGN_TOP
#   @return [Integer]

# @!parse TEXT_ALIGN_MIDDLE = INT2NUM(TEXT_ALIGN_MIDDLE
#   @return [Integer]

# @!parse TEXT_ALIGN_BOTTOM = INT2NUM(TEXT_ALIGN_BOTTOM
#   @return [Integer]

# @!parse TEXT_WRAP_NONE = INT2NUM(TEXT_WRAP_NONE
#   @return [Integer]

# @!parse TEXT_WRAP_CHAR = INT2NUM(TEXT_WRAP_CHAR
#   @return [Integer]

# @!parse TEXT_WRAP_WORD = INT2NUM(TEXT_WRAP_WORD
#   @return [Integer]

# @!parse DEFAULT = INT2NUM(DEFAULT
#   @return [Integer]

# @!parse LABEL = INT2NUM(LABEL
#   @return [Integer]

# @!parse BUTTON = INT2NUM(BUTTON
#   @return [Integer]

# @!parse TOGGLE = INT2NUM(TOGGLE
#   @return [Integer]

# @!parse SLIDER = INT2NUM(SLIDER
#   @return [Integer]

# @!parse PROGRESSBAR = INT2NUM(PROGRESSBAR
#   @return [Integer]

# @!parse CHECKBOX = INT2NUM(CHECKBOX
#   @return [Integer]

# @!parse COMBOBOX = INT2NUM(COMBOBOX
#   @return [Integer]

# @!parse DROPDOWNBOX = INT2NUM(DROPDOWNBOX
#   @return [Integer]

# @!parse TEXTBOX = INT2NUM(TEXTBOX
#   @return [Integer]

# @!parse VALUEBOX = INT2NUM(VALUEBOX
#   @return [Integer]

# @!parse CONTROL11 = INT2NUM(CONTROL11
#   @return [Integer]

# @!parse LISTVIEW = INT2NUM(LISTVIEW
#   @return [Integer]

# @!parse COLORPICKER = INT2NUM(COLORPICKER
#   @return [Integer]

# @!parse SCROLLBAR = INT2NUM(SCROLLBAR
#   @return [Integer]

# @!parse STATUSBAR = INT2NUM(STATUSBAR
#   @return [Integer]

# @!parse BORDER_COLOR_NORMAL = INT2NUM(BORDER_COLOR_NORMAL
#   @return [Integer]

# @!parse BASE_COLOR_NORMAL = INT2NUM(BASE_COLOR_NORMAL
#   @return [Integer]

# @!parse TEXT_COLOR_NORMAL = INT2NUM(TEXT_COLOR_NORMAL
#   @return [Integer]

# @!parse BORDER_COLOR_FOCUSED = INT2NUM(BORDER_COLOR_FOCUSED
#   @return [Integer]

# @!parse BASE_COLOR_FOCUSED = INT2NUM(BASE_COLOR_FOCUSED
#   @return [Integer]

# @!parse TEXT_COLOR_FOCUSED = INT2NUM(TEXT_COLOR_FOCUSED
#   @return [Integer]

# @!parse BORDER_COLOR_PRESSED = INT2NUM(BORDER_COLOR_PRESSED
#   @return [Integer]

# @!parse BASE_COLOR_PRESSED = INT2NUM(BASE_COLOR_PRESSED
#   @return [Integer]

# @!parse TEXT_COLOR_PRESSED = INT2NUM(TEXT_COLOR_PRESSED
#   @return [Integer]

# @!parse BORDER_COLOR_DISABLED = INT2NUM(BORDER_COLOR_DISABLED
#   @return [Integer]

# @!parse BASE_COLOR_DISABLED = INT2NUM(BASE_COLOR_DISABLED
#   @return [Integer]

# @!parse TEXT_COLOR_DISABLED = INT2NUM(TEXT_COLOR_DISABLED
#   @return [Integer]

# @!parse BORDER_WIDTH = INT2NUM(BORDER_WIDTH
#   @return [Integer]

# @!parse TEXT_PADDING = INT2NUM(TEXT_PADDING
#   @return [Integer]

# @!parse TEXT_ALIGNMENT = INT2NUM(TEXT_ALIGNMENT
#   @return [Integer]

# @!parse TEXT_SIZE = INT2NUM(TEXT_SIZE
#   @return [Integer]

# @!parse TEXT_SPACING = INT2NUM(TEXT_SPACING
#   @return [Integer]

# @!parse LINE_COLOR = INT2NUM(LINE_COLOR
#   @return [Integer]

# @!parse BACKGROUND_COLOR = INT2NUM(BACKGROUND_COLOR
#   @return [Integer]

# @!parse TEXT_LINE_SPACING = INT2NUM(TEXT_LINE_SPACING
#   @return [Integer]

# @!parse TEXT_ALIGNMENT_VERTICAL = INT2NUM(TEXT_ALIGNMENT_VERTICAL
#   @return [Integer]

# @!parse TEXT_WRAP_MODE = INT2NUM(TEXT_WRAP_MODE
#   @return [Integer]

# @!parse GROUP_PADDING = INT2NUM(GROUP_PADDING
#   @return [Integer]

# @!parse SLIDER_WIDTH = INT2NUM(SLIDER_WIDTH
#   @return [Integer]

# @!parse SLIDER_PADDING = INT2NUM(SLIDER_PADDING
#   @return [Integer]

# @!parse PROGRESS_PADDING = INT2NUM(PROGRESS_PADDING
#   @return [Integer]

# @!parse ARROWS_SIZE = INT2NUM(ARROWS_SIZE
#   @return [Integer]

# @!parse ARROWS_VISIBLE = INT2NUM(ARROWS_VISIBLE
#   @return [Integer]

# @!parse SCROLL_SLIDER_PADDING = INT2NUM(SCROLL_SLIDER_PADDING
#   @return [Integer]

# @!parse SCROLL_SLIDER_SIZE = INT2NUM(SCROLL_SLIDER_SIZE
#   @return [Integer]

# @!parse SCROLL_PADDING = INT2NUM(SCROLL_PADDING
#   @return [Integer]

# @!parse SCROLL_SPEED = INT2NUM(SCROLL_SPEED
#   @return [Integer]

# @!parse CHECK_PADDING = INT2NUM(CHECK_PADDING
#   @return [Integer]

# @!parse COMBO_BUTTON_WIDTH = INT2NUM(COMBO_BUTTON_WIDTH
#   @return [Integer]

# @!parse COMBO_BUTTON_SPACING = INT2NUM(COMBO_BUTTON_SPACING
#   @return [Integer]

# @!parse ARROW_PADDING = INT2NUM(ARROW_PADDING
#   @return [Integer]

# @!parse DROPDOWN_ITEMS_SPACING = INT2NUM(DROPDOWN_ITEMS_SPACING
#   @return [Integer]

# @!parse TEXT_READONLY = INT2NUM(TEXT_READONLY
#   @return [Integer]

# @!parse SPINNER_BUTTON_WIDTH = INT2NUM(SPINNER_BUTTON_WIDTH
#   @return [Integer]

# @!parse SPINNER_BUTTON_SPACING = INT2NUM(SPINNER_BUTTON_SPACING
#   @return [Integer]

# @!parse LIST_ITEMS_HEIGHT = INT2NUM(LIST_ITEMS_HEIGHT
#   @return [Integer]

# @!parse LIST_ITEMS_SPACING = INT2NUM(LIST_ITEMS_SPACING
#   @return [Integer]

# @!parse SCROLLBAR_WIDTH = INT2NUM(SCROLLBAR_WIDTH
#   @return [Integer]

# @!parse SCROLLBAR_SIDE = INT2NUM(SCROLLBAR_SIDE
#   @return [Integer]

# @!parse COLOR_SELECTOR_SIZE = INT2NUM(COLOR_SELECTOR_SIZE
#   @return [Integer]

# @!parse HUEBAR_WIDTH = INT2NUM(HUEBAR_WIDTH
#   @return [Integer]

# @!parse HUEBAR_PADDING = INT2NUM(HUEBAR_PADDING
#   @return [Integer]

# @!parse HUEBAR_SELECTOR_HEIGHT = INT2NUM(HUEBAR_SELECTOR_HEIGHT
#   @return [Integer]

# @!parse HUEBAR_SELECTOR_OVERFLOW = INT2NUM(HUEBAR_SELECTOR_OVERFLOW
#   @return [Integer]
