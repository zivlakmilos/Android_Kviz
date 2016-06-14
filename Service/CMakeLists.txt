cmake_minimum_required(VERSION 2.6)
project(AndroidKviz)
find_package(Qt4 COMPONENTS QtCore QtGui QtSql REQUIRED)

include_directories(${QT_INCLUDES} ${CMAKE_CURRENT_BINARY_DIR} include/)

INCLUDE(${QT_USE_FILE})

set(AndroidKviz_SRCS
    main.cpp
    src/MainWindow.cpp
    src/AdministrationWindow.cpp
    src/DQuizSelector.cpp
    src/Database.cpp
)

set(AndroidKviz_HEADERS
    include/MainWindow.h
    include/AdministrationWindow.h
    include/DQuizSelector.h
)

foreach(MOCheader ${AndroidKviz_HEADERS})
    QT4_WRAP_CPP(MOCsrc ${MOCheader})
endforeach(MOCheader)

add_executable(AndroidKviz ${AndroidKviz_SRCS} ${MOCsrc})
target_link_libraries(AndroidKviz ${QT_QTCORE_LIBRARY} ${QT_QTGUI_LIBRARY}
    ${QT_QTSQL_LIBRARY})
target_compile_features(AndroidKviz PRIVATE cxx_range_for)

install(TARGETS AndroidKviz RUNTIME DESTINATION bin)
add_subdirectory(include/data)