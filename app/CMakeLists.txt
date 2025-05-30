find_package(Qt6 REQUIRED COMPONENTS Core Widgets)

qt_standard_project_setup()

set(Timeline_Sources
	Timeline.cpp
	MainWindow.cpp)

set(Timeline_Headers
	Timeline.h
	MainWindow.h)

qt_add_executable(Timeline ${Timeline_Sources} ${Timeline_Headers})
target_link_libraries(Timeline PRIVATE Qt6::Core Qt6::Widgets)
target_compile_definitions(Timeline PUBLIC OCS_TIMELINE_TIMESTAMP="${Timeline_Timestamp}")

set_target_properties(Timeline PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)