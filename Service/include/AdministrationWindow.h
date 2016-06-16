#ifndef _ADMINISTRATION_WINDOW_H_
#define _ADMINISTRATION_WINDOW_H_

#include <QMainWindow>

#include <data/kviz.h>

class QAction;
class QMdiArea;

class AdministrationWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    AdministrationWindow(QWidget* parent = 0);
    virtual ~AdministrationWindow(void);
    
private:
    void setupMenu(void);
    void setupToolBar(void);
    void setupStatudBar(void);
    
    void setKviz(Kviz kviz);
    
    QMenu *m_menuKviz;
    QMenu *m_menuPomoc;
    
    QToolBar *m_tbPitanja;
    
    QAction *m_actionNoviKviz;
    QAction *m_actionOtvoriKviz;
    QAction *m_actionIzmenaKvizova;
    QAction *m_actionBrziPrsti;
    QAction *m_actionKoZnaZna;
    QAction *m_actionAsocijacije;
    QAction *m_actionOProgramu;
    
    QMdiArea *m_mdiArea;
    
    Kviz m_kviz;
    
private slots:
    void actionNoviKviz_click(void);
    void actionOtvoriKviz_click(void);
};

#endif // _ADMINISTRATION_WINDOW_H_