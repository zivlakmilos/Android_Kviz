#ifndef _MAIN_WINDOW_H_
#define _MAIN_WINDOW_H_

#include <QWidget>

class QVBoxLayout;
class QPushButton;

class MainWindow : public QWidget
{
    Q_OBJECT
    
    public:
        MainWindow(QWidget *parent = 0);
        ~MainWindow(void);
    
    private:
        
        /* Gui: */
        QVBoxLayout *m_mainLayout;
        
        QPushButton *m_btnAndroidProjectorMode;
        QPushButton *m_btnAndroidMode;
        QPushButton *m_btnAdministration;
        
        void setupGui(void);
};

#endif // _MAIN_WINDOW_H_