cmake_minimum_required(VERSION 2.6)
project(AndroidKviz)
find_package(Qt4 REQUIRED)

include_directories(${QT_INCLUDES} ${CMAKE_CURRENT_BINARY_DIR} include/)

set(Android_Kviz_SRCS
    main.cpp
)

qt4_automoc(${Android_Kviz_SRCS})
add_executable(AndroidKviz ${Android_Kviz_SRCS})
target_link_libraries(AndroidKviz ${QT_QTCORE_LIBRARY} ${QT_QTGUI_LIBRARY})

install(TARGETS AndroidKviz RUNTIME DESTINATION bin)
