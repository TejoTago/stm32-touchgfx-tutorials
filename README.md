# &nbsp;	stm32-touchgfx-tutorials

A collection of STM32F7 GUI projects built with TouchGFX Designer.



img src="imagesGitHub/TouchGFX-LAB-gitHub.jpg" alt="TouchGFX LAB" width="600"/



\## Project: Creating a Logo



\*\*Description\*\*

This demo showcases a dynamic logo animation using custom shapes and text elements. It includes animated transitions for multiple components, a scroll wheel for interaction, and layered visual styling with gradients and text overlays.



\*\*YouTube Link\*\*

\[Watch Demo](https://youtube.com/shorts/jWlQ3I2Wx9E)



\*\*Folder Path\*\*

\[Code](https://github.com/TejoTago/stm32-touchgfx-tutorials/tree/main/Dynamic\_random/TouchGFX/gui/src/screenlogo\_screen)

\[Code]([https://github.com/TejoTago/stm32-touchgfx-tutorials/blob/main/Dynamic\_random/TouchGFX/generated/gui\_generated/src/screenlogo\_screen/ScreenLogoViewBase.cpp](https://github.com/TejoTago/stm32-touchgfx-tutorials/blob/main/Dynamic\\_random/TouchGFX/generated/gui\\_generated/src/screenlogo\\_screen/ScreenLogoViewBase.cpp))



\*\*Features Used\*\*

\- C++: Callback functions, object initialization, animation control, inheritance

\- TouchGFX: CanvasWidgetRenderer, AbstractShape, ScalableImage, ScrollWheel, TypedText, MoveAnimation, custom painters



\## Project: Radio Buttons - Semaphore Control



\*\*Description\*\*

This demo simulates a traffic light system controlled by radio buttons. Users can select between OFF, SLOW, and FAST modes, which dynamically change the light sequence timing. The project demonstrates how to use radio buttons to control UI behavior and timed animations.



\*\*YouTube Link\*\*

\[Watch Demo](https://youtube.com/shorts/hwb7RelV4E8)



\*\*Folder Path\*\*

\[Code]([https://github.com/TejoTago/stm32-touchgfx-tutorials/blob/main/Dynamic\_random/TouchGFX/gui/src/radiobuttonsemaphorenew\_screen/RadioButtonSemaphoreNewView.cpp](https://github.com/TejoTago/stm32-touchgfx-tutorials/blob/main/Dynamic\\_random/TouchGFX/gui/src/radiobuttonsemaphorenew\\_screen/RadioButtonSemaphoreNewView.cpp))



\*\*Features Used\*\*

\- C++: Enum-based state management, tick event handling, conditional logic

\- TouchGFX: RadioButton widget, visibility toggling, invalidate(), handleTickEvent()



\## Project: WiFi Signal Simulation



\*\*Description\*\*

This demo simulates a dynamic WiFi signal icon using animated circular indicators. A toggle button activates the blinking sequence, and the signal strength animation accelerates over time. The project demonstrates timed visual feedback and user-controlled animation flow.



\*\*YouTube Link\*\*

\[Watch Demo](https://youtube.com/shorts/bgtlfiIu-bs)



\*\*Folder Path\*\*

\[Code]([https://github.com/TejoTago/stm32-touchgfx-tutorials/blob/main/Dynamic\_random/TouchGFX/gui/src/wirelessicon\_screen/WirelessIconView.cpp](https://github.com/TejoTago/stm32-touchgfx-tutorials/blob/main/Dynamic\\_random/TouchGFX/gui/src/wirelessicon\\_screen/WirelessIconView.cpp))



\*\*Features Used\*\*

\- C++: Timer-based animation, state control, modular indexing

\- TouchGFX: AbstractButton callback, visibility toggling, invalidate(), handleTickEvent(), registerTimerWidget()



\## Project: FlexButton - Star Rating Control



\*\*Description\*\*

This demo implements a star-based rating system using flexible buttons. Users can select a rating from 1 to 5 stars, and clicking the same rating again resets it. The logic ensures intuitive toggling and visual feedback based on user interaction.



\*\*YouTube Link\*\*

\[Watch Demo](https://youtube.com/shorts/WFgztTnqD00)



\*\*Folder Path\*\*

\[Code]([https://github.com/TejoTago/stm32-touchgfx-tutorials/blob/main/Dynamic\_random/TouchGFX/gui/src/starflexbuttonicon\_screen/StarFlexButtonIconView.cpp](https://github.com/TejoTago/stm32-touchgfx-tutorials/blob/main/Dynamic\\_random/TouchGFX/gui/src/starflexbuttonicon\\_screen/StarFlexButtonIconView.cpp))



\*\*Features Used\*\*

\- C++: Conditional logic, state tracking, dynamic UI updates

\- TouchGFX: Button widget, setPressed(), invalidate(), Unicode::snprintf(), typed text rendering



\## Project: Dynamic Shape Control — Live Blinking and Color Slider Demo



\*\*Description\*\*

This demo features a dynamic shape whose visibility, blinking behavior, and color can be controlled in real time. A toggle button activates the shape, a slider adjusts its hue using HSV-to-RGB conversion, and blinking speed is managed through multiple modes with visual indicators.



\*\*YouTube Link\*\*

\[Watch Demo](https://youtube.com/shorts/vAtf0sWdpos)



\*\*Folder Path\*\*

\[Code]([https://github.com/TejoTago/stm32-touchgfx-tutorials/blob/main/TouchGFX\_myTutorials/TouchGFX/gui/src/sliderblinkcontrol\_screen/SliderBlinkControlView.cpp](https://github.com/TejoTago/stm32-touchgfx-tutorials/blob/main/TouchGFX\\_myTutorials/TouchGFX/gui/src/sliderblinkcontrol\\_screen/SliderBlinkControlView.cpp))



\*\*Features Used\*\*

\- C++: HSV-to-RGB conversion, conditional logic, tick-based animation, modular control flow

\- TouchGFX: ToggleButton, Slider, AbstractShape, setVisible(), invalidate(), handleTickEvent()



\## Project: Move Widget



\*\*Description\*\*

This demo showcases coordinated widget animations using multiple colored circles. The movement sequence is triggered programmatically, with chained callbacks controlling the flow of animations. Each widget moves with distinct easing equations to demonstrate smooth transitions and visual variety.



\*\*YouTube Link\*\*

\[Watch Demo](https://youtube.com/shorts/aRsv1SDlm6c)



\*\*Folder Path\*\*

\[Code]([https://github.com/TejoTago/stm32-touchgfx-tutorials/blob/main/TouchGFX\_myTutorials/TouchGFX/gui/src/movewidgetwithmixin\_screen/MoveWidgetWithMixinView.cpp](https://github.com/TejoTago/stm32-touchgfx-tutorials/blob/main/TouchGFX\\_myTutorials/TouchGFX/gui/src/movewidgetwithmixin\\_screen/MoveWidgetWithMixinView.cpp))



\*\*Features Used\*\*

\- C++: Callback chaining, animation sequencing, event-driven logic

\- TouchGFX: MoveAnimator, setMoveAnimationEndedAction(), easing equations, invalidate()



\## Project: Scroll Wheel



\*\*Description\*\*

This demo features three scroll wheels that allow users to select indexed items. The combination of selected values controls the visibility of lock and unlock icons, simulating a simple code-based unlocking mechanism. It demonstrates how to use scroll wheels for multi-input logic and dynamic UI feedback.



\*\*YouTube Link\*\*

\[Watch Demo](https://youtube.com/shorts/V88QbttihVo)



\*\*Folder Path\*\*

\[Code]([https://github.com/TejoTago/stm32-touchgfx-tutorials/blob/main/TouchGFXmyTutorials/TouchGFX/gui/src/scrollwheel\_screen/ScrollWheelView.cpp](https://github.com/TejoTago/stm32-touchgfx-tutorials/blob/main/TouchGFX\\myTutorials/TouchGFX/gui/src/scrollwheel\\_screen/ScrollWheelView.cpp))



\*\*Features Used\*\*

\- C++: Indexed selection tracking, conditional logic, state evaluation

\- TouchGFX: ScrollWheel widget, updateItem callbacks, invalidate(), setVisible()



\## Project: Slider Control — Size and Scale of Custom Widget



\*\*Description\*\*

This demo allows users to dynamically adjust the size and proportions of a custom star-shaped widget using three sliders. One slider controls uniform scaling, while the other two independently adjust width and height. The project demonstrates real-time shape manipulation through user input.



\*\*YouTube Link\*\*

\[Watch Demo](https://youtube.com/shorts/uHCNtkeM5kg)



\*\*Folder Path\*\*

\[Code]([https://github.com/TejoTago/stm32-touchgfx-tutorials/blob/main/TouchGFX\_myTutorials/TouchGFX/gui/src/slidershapesize\_screen/SliderShapeSizeView.cpp](https://github.com/TejoTago/stm32-touchgfx-tutorials/blob/main/TouchGFX\\_myTutorials/TouchGFX/gui/src/slidershapesize\\_screen/SliderShapeSizeView.cpp))



\*\*Features Used\*\*

\- C++: Callback functions, scale factor mapping, float arithmetic

\- TouchGFX: Slider widget, setNewValueCallback(), updateScale()



\## Project: Move and Fade Widget



\*\*Description\*\*

This demo combines movement, fading, and drag interaction to create a responsive UI experience. A volume indicator moves and toggles visibility, while a screen element fades in based on tick timing. Dragging a control adjusts the alpha transparency of a light element, demonstrating smooth visual feedback.



\*\*YouTube Link\*\*

\[Watch Demo](https://youtube.com/shorts/ugH0k0zLaRw)



\*\*Folder Path\*\*

\[Code]([https://github.com/TejoTago/stm32-touchgfx-tutorials/blob/main/TouchGFX\_myTutorials/TouchGFX/gui/src/moveandfade\_screen/MoveAndFadeView.cpp](https://github.com/TejoTago/stm32-touchgfx-tutorials/blob/main/TouchGFX\\_myTutorials/TouchGFX/gui/src/moveandfade\\_screen/MoveAndFadeView.cpp))



\*\*Features Used\*\*

\- C++: Tick-based animation, drag event handling, alpha mapping

\- TouchGFX: MoveAnimator, setAlpha(), setVisible(), invalidate(), handleTickEvent(), handleDragEvent()



\## Project: Custom Slider — Export and Import Logic



\*\*Description\*\*

This demo implements a custom horizontal slider with confirmation logic based on drag position. When the slider reaches a threshold, it triggers a validation action and fades out instructional text while fading in confirmation feedback. The slider becomes inactive after confirmation, simulating a secure action trigger.



\*\*YouTube Link\*\*

\[Watch Demo](https://youtube.com/shorts/yN-RtJPEXI4)



\*\*Folder Path\*\*

\[Code]([https://github.com/TejoTago/stm32-touchgfx-tutorials/blob/main/myCustomWidgets/TouchGFX/gui/src/containers/mySlider.cpp](https://github.com/TejoTago/stm32-touchgfx-tutorials/blob/main/myCustomWidgets/TouchGFX/gui/src/containers/mySlider.cpp))



\*\*Features Used\*\*

\- C++: Custom widget class, drag and click event handling, alpha blending, state control

\- TouchGFX: handleClickEvent(), handleDragEvent(), setAlpha(), setXY(), invalidate(), setTouchable()



\## Project: Dynamic Graph, Slider, Y-Axis Control



\*\*Description\*\*

This demo features a dynamic line chart that updates in real time with randomized values. A slider allows users to adjust the Y-axis range, which automatically recalibrates the grid and label intervals. The project demonstrates interactive data visualization and adaptive chart scaling.



\*\*YouTube Link\*\*

\[Watch Demo](https://youtube.com/shorts/AqLHt7\_X9WE)



\*\*Folder Path\*\*

\[Code]([https://github.com/TejoTago/stm32-touchgfx-tutorials/blob/main/myCharts/TouchGFX/gui/src/linechartslideryaxis\_screen/LineChartSliderYAxisView.cpp](https://github.com/TejoTago/stm32-touchgfx-tutorials/blob/main/myCharts/TouchGFX/gui/src/linechartslideryaxis\\_screen/LineChartSliderYAxisView.cpp))



\*\*Features Used\*\*

\- C++: Random value generation, range clamping, tick-based updates

\- TouchGFX: LineChart widget, setGraphRangeY(), setInterval(), addDataPoint(), invalidate(), Unicode::snprintf()



\## Project: Dynamic Graph Slider Y — Slide Menu Customization



\*\*Description\*\*

This demo showcases a dynamic graph system enhanced by a slide-out menu that empowers users to customize the visual experience. Through toggle buttons, users can selectively show or hide graph lines, data point dots, gridlines, and background elements. The menu also includes a slider to adjust the Y-axis range, which automatically recalibrates grid and label intervals. This project highlights how intuitive UI controls can give users real-time control over data visualization.



\*\*YouTube Link\*\*

\[Watch Demo](https://youtube.com/shorts/WsffIVuCgzM)



\*\*Folder Path\*\*

\[Code]([https://github.com/TejoTago/stm32-touchgfx-tutorials/blob/main/Dynamic\_random/TouchGFX/gui/src/dynamicgraphslidery\_screen/DynamicGraphSliderYView.cpp](https://github.com/TejoTago/stm32-touchgfx-tutorials/blob/main/Dynamic\\_random/TouchGFX/gui/src/dynamicgraphslidery\\_screen/DynamicGraphSliderYView.cpp))



\*\*Features Used\*\*

\- C++: Callback binding, conditional rendering, dynamic value generation

\- TouchGFX: Slide menu, ToggleButton, Slider, GraphScroll, setGraphRangeY(), setAlpha(), setInterval(), invalidate()



\## Project: Shape Height Click — Interactive Drag-Based Resizing



\*\*Description\*\*

This demo allows users to interactively resize two custom shapes by clicking and dragging vertically. Each shape responds to touch events and adjusts its height dynamically within defined limits. The project simulates real-world variables like water pressure and temperature through visual height changes, offering an intuitive way to represent data-driven UI elements.



\*\*YouTube Link\*\*

\[Watch Demo](https://youtube.com/shorts/ET8eldr9ZxM)



\*\*Folder Path\*\*

\[Code]([https://github.com/TejoTago/stm32-touchgfx-tutorials/blob/main/myCustomWidgets/TouchGFX/gui/src/shapeheightclick\_screen/ShapeHeightClickView.cpp](https://github.com/TejoTago/stm32-touchgfx-tutorials/blob/main/myCustomWidgets/TouchGFX/gui/src/shapeheightclick\\_screen/ShapeHeightClickView.cpp))



\*\*Features Used\*\*

\- C++: Touch event handling, drag-based geometry manipulation, clamping logic

\- TouchGFX: AbstractShape, handleClickEvent(), handleDragEvent(), setShape(), invalidate()



\## Project: Animated Pie Chart — Interactive Slice Selection and Quarter Data



\*\*Description\*\*

This demo presents a fully animated pie chart with six data slices representing quarterly values. The chart is drawn in three phases: radius expansion, rotational alignment, and progressive slice rendering. Users can interact with individual slices to expand or collapse them and view percentage labels. Clicking the center toggles all slices simultaneously. Radio buttons allow switching between Q1–Q4 datasets, each with a unique distribution. Slice selection is calculated based on click position and angle, and each slice animates outward using trigonometric offset logic.



\*\*YouTube Link\*\*

\[Watch Demo](https://youtube.com/shorts/YushRx4lt5c)



\*\*Folder Path\*\*

\[Code]([https://github.com/TejoTago/stm32-touchgfx-tutorials/blob/main/myPieCharts/TouchGFX/gui/src/phase5\_screen/Phase5View.cpp](https://github.com/TejoTago/stm32-touchgfx-tutorials/blob/main/myPieCharts/TouchGFX/gui/src/phase5\\_screen/Phase5View.cpp))



\*\*Features Used\*\*

\- C++: Angle-based hit detection, trigonometric offset calculation, animation state machine, percentage-to-angle conversion

\- TouchGFX: Pie chart rendering, setArc(), setRadius(), setCenter(), invalidate(), Unicode::snprintf(), ClickEvent handling, radio button selection, animated drawing phases

