cmake_minimum_required(VERSION 2.6)
project(AndroidKviz)
find_package(Qt4 COMPONENTS QtCore QtGui QtSql QtNetwork REQUIRED)

set (CMAKE_AUTORCC on)

include_directories(${QT_INCLUDES} ${CMAKE_CURRENT_BINARY_DIR} include/)

INCLUDE(${QT_USE_FILE})

set(AndroidKviz_SRCS
    main.cpp
    src/MainWindow.cpp
    src/AdministrationWindow.cpp
    src/Database.cpp
    src/DBrziPrsti.cpp
    src/data/MBrziPrsti.cpp
    src/DBrziPrstiEdit.cpp
    src/DKoZnaZna.cpp
    src/data/MKoZnaZna.cpp
    src/DKoZnaZnaEdit.cpp
    src/DAsocijacije.cpp
    src/data/MAsocijacije.cpp
    src/DAsocijacijeEdit.cpp
    src/WAsocijacijePreview.cpp
    src/TcpService.cpp
    src/TcpClient.cpp
    src/DAndroidProjector.cpp
    src/WQuizControl.cpp
    src/WBrziPrsti.cpp
)

set(AndroidKviz_HEADERS
    include/MainWindow.h
    include/AdministrationWindow.h
    include/DBrziPrsti.h
    include/data/MBrziPrsti.h
    include/DBrziPrstiEdit.h
    include/DKoZnaZna.h
    include/data/MKoZnaZna.h
    include/DKoZnaZnaEdit.h
    include/DAsocijacije.h
    include/data/MAsocijacije.h
    include/DAsocijacijeEdit.h
    include/WAsocijacijePreview.h
    include/TcpService.h
    include/TcpClient.h
    include/DAndroidProjector.h
    include/WQuizControl.h
    include/WBrziPrsti.h
)

set(AndroidKviz_RESOURCES
    resources/resources.qrc
)

foreach(MOCheader ${AndroidKviz_HEADERS})
    QT4_WRAP_CPP(MOCsrc ${MOCheader})
endforeach(MOCheader)

add_executable(AndroidKviz ${AndroidKviz_SRCS} ${MOCsrc} ${AndroidKviz_RESOURCES})
target_link_libraries(AndroidKviz ${QT_QTCORE_LIBRARY} ${QT_QTGUI_LIBRARY}
    ${QT_QTSQL_LIBRARY} ${QT_QTNETWORK_LIBRARY})
target_compile_features(AndroidKviz PRIVATE cxx_range_for)

install(TARGETS AndroidKviz RUNTIME DESTINATION bin)