#include <QApplication>
#include <ctime>

#include <MainWindow.h>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    
    qsrand(time(NULL));
    
    MainWindow mainWindow;
    mainWindow.show();
    
    return app.exec();
}