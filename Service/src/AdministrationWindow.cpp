#include <AdministrationWindow.h>

#include <QtGui>

#include <data/kviz.h>
#include <DQuizSelector.h>

AdministrationWindow::AdministrationWindow(QWidget* parent)
    : QMainWindow(parent)
{
    setWindowTitle(tr("Android Kviz - Administracija"));
    
    m_mdiArea = new QMdiArea(this);
    setCentralWidget(m_mdiArea);
    
    setupMenu();
}

AdministrationWindow::~AdministrationWindow(void)
{
}

void AdministrationWindow::setupMenu(void)
{
    /*
     * Menus
     */
    
    m_menuKviz = new QMenu(this);
    m_menuKviz->setTitle(tr("&Kviz"));
    menuBar()->addMenu(m_menuKviz);
    
    m_menuPomoc = new QMenu(this);
    m_menuPomoc->setTitle(tr("&Pomoc"));
    menuBar()->addMenu(m_menuPomoc);
    
    /*
     * Actions
     */
    
    m_actionNoviKviz = m_menuKviz->addAction(tr("&Novi kviz"));
    
    m_actionOtvoriKviz = m_menuKviz->addAction(tr("&Otvori kviz"));
    
    m_actionIzmenaKvizova = m_menuKviz->addAction(tr("&Izmena kvizova"));
    
    m_actionOProgramu = m_menuPomoc->addAction(tr("&O programu"));
}