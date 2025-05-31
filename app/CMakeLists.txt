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
target_link_libraries(Timeline PRIVATE ads::qtadvanceddocking-qt6)
target_compile_definitions(Timeline PUBLIC OCS_TIMELINE_TIMESTAMP="${Timeline_Timestamp}")
target_include_directories(Timeline PRIVATE "${CMAKE_SOURCE_DIR}/ext/")

set_target_properties(Timeline PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)
set_property(TARGET Timeline PROPERTY CXX_STANDARD 20)
set_property(TARGET Timeline PROPERTY CXX_STANDARD_REQUIRED ON)