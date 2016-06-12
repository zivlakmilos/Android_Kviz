cmake_minimum_required(VERSION 2.6)
project(AndroidKviz)
find_package(Qt4 REQUIRED)

include_directories(${QT_INCLUDES} ${CMAKE_CURRENT_BINARY_DIR} include/)

INCLUDE(${QT_USE_FILE})

set(AndroidKviz_SRCS
    main.cpp
    src/MainWindow.cpp
)

set(AndroidKviz_HEADERS
    include/MainWindow.h
)

foreach(MOCheader ${AndroidKviz_HEADERS})
    QT4_WRAP_CPP(MOCsrc ${MOCheader})
endforeach(MOCheader)

add_executable(AndroidKviz ${AndroidKviz_SRCS} ${MOCsrc})
target_link_libraries(AndroidKviz ${QT_QTCORE_LIBRARY} ${QT_QTGUI_LIBRARY})

install(TARGETS AndroidKviz RUNTIME DESTINATION bin)
