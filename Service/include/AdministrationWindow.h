#ifndef _ADMINISTRATION_WINDOW_H_
#define _ADMINISTRATION_WINDOW_H_

#include <QMainWindow>

#include <data/kviz.h>

class QAction;
class QMdiArea;
class QMdiSubWindow;

class AdministrationWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    AdministrationWindow(QWidget* parent = 0);
    virtual ~AdministrationWindow(void);
    
private:
    void setupMenu(void);
    void setupStatusBar(void);
    
    void setKviz(Kviz kviz);
    
    QMenu *m_menuKviz;
    QMenu *m_menuPomoc;
    
    QToolBar *m_tbPitanja;
    QToolBar *m_tbPitanjaDodatni;
    
    QAction *m_actionNoviKviz;
    QAction *m_actionOtvoriKviz;
    QAction *m_actionIzmenaKvizova;
    QAction *m_actionBrziPrsti;
    QAction *m_actionKoZnaZna;
    QAction *m_actionAsocijacije;
    QAction *m_actionOProgramu;
    QAction *m_actionNovoPitanje;
    QAction *m_actionObrisiPitanje;
    
    QMdiArea *m_mdiArea;
    
    Kviz m_kviz;
    
protected:
    void closeEvent(QCloseEvent *event);
    
signals:
    void close();
    
private slots:
    void actionNoviKviz_click(void);
    void actionOtvoriKviz_click(void);
    void actionBrziPrsti_click(void);
    void actionNovoPitanje_click(void);
    void actionObrisiPitanje_click(void);
    void subWindowsActiveChanged(QMdiSubWindow *activeWindow);
};

#endif // _ADMINISTRATION_WINDOW_H_