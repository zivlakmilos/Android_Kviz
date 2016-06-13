cmake_minimum_required(VERSION 2.6)
project(AndroidKviz_TEST)

enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIR})

find_package(Qt4 COMPONENTS QtCore QtGui QtSql REQUIRED)
include_directories(${QT_INCLUDES} ${CMAKE_CURRENT_BINARY_DIR} ../include/)

INCLUDE(${QT_USE_FILE})

set(AndroidKviz_SRCS
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

set(AndroidKviz-test_SRCS
    DatabaseTest.cpp
)

add_executable(AndroidKviz-test
    main.cpp
    ${AndroidKviz_SRCS}
    ${MOCsrc}
    ${AndroidKviz-test_SRCS}
)

target_link_libraries(AndroidKviz-test gtest gtest_main
    ${QT_QTCORE_LIBRARY} ${QT_QTGUI_LIBRARY} ${QT_QTSQL_LIBRARY})

add_test (
    NAME AndroidKviz-test
    COMMAND AndroidKviz-test
)