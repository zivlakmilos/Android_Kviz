#ifndef _ADMINISTRATION_WINDOW_H_
#define _ADMINISTRATION_WINDOW_H_

#include <QMainWindow>

class QAction;
class QMdiArea;

class AdministrationWindow : public QMainWindow
{
    public:
        AdministrationWindow(QWidget* parent = 0);
        virtual ~AdministrationWindow(void);
        
    private:
        void setupMenu(void);
        void setupToolBar(void);
        void setupStatudBar(void);
        
        QAction *m_actionBrziPrsti;
        QAction *m_actionKoZnaZna;
        QAction *m_actionAsocijacije;
        
        QMdiArea *m_mdiArea;
};

#endif // _ADMINISTRATION_WINDOW_H_