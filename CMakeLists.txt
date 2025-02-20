# CMakeList.txt: проект CMake для TestTaskC++; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

# Включение горячей перезагрузки для компиляторов MSVC, если поддерживается.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("TestTaskC++")

# Добавьте источник в исполняемый файл этого проекта.
add_executable (TestTaskC++ "main.cpp" "Figures/figures.cpp" )

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET TestTaskC++ PROPERTY CXX_STANDARD 20)
endif()

 set(BOOST_MIN_VERSION 1.8.0)

 #include_directories(Figures)
  
# Подключаем необходимые модули. Для примера подключим program_options
find_package(Boost 1.8 REQUIRED COMPONENTS thread system filesystem) 
  
# Если библиотека найдена, то
if (Boost_FOUND)
message(STATUS "Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
message(STATUS "Boost_LIBRARIES: ${Boost_LIBRARIES}")
    target_link_libraries (TestTaskC++ ${Boost_LIBRARIES}) # подключаем библиотеку
else()
    message(FATAL_ERROR "Boost not found!")
endif ()