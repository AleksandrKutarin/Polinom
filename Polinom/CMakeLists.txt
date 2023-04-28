# отключаем создание ZERO проекта при сборке CMake
set(CMAKE_SUPPRESS_REGENERATION true)

# указывайте последнюю доступную вам версию CMake
cmake_minimum_required(VERSION 3.6 FATAL_ERROR)

# название проекта
project(Laboratory_works)

# устанавливаем автоматическую инициализацию С++20
set(CMAKE_CXX_STANDARD 20)   

# затем следует список инструкций для подключения проектов из подкаталогов
include(LIBS/lib_cmake_funcs/function.cmake)    # подхватываем функции, реализованные в файле function.cmake

add_subdirectory(APPS/app_Polinom)
add_subdirectory(LIBS/lib_For_Polinom)



