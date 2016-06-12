#ifndef _MAIN_WINDOW_H_
#define _MAIN_WINDOW_H_

#include <QWidget>

class MainWindow : public QWidget
{
    Q_OBJECT
    
    public:
        MainWindow(QWidget *parent = 0);
        ~MainWindow(void);
    
    private:
};

#endif // _MAIN_WINDOW_H_