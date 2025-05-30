cmake_minimum_required (VERSION 3.16)
project(Timeline VERSION 1.0.0 LANGUAGES CXX C)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()
string(TIMESTAMP Timeline_Timestamp)

add_subdirectory(ext)
add_subdirectory(app)

set_property(TARGET Timeline PROPERTY CXX_STANDARD 20)
set_property(TARGET Timeline PROPERTY CXX_STANDARD_REQUIRED ON)