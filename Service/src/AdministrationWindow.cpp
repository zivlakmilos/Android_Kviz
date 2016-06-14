#include <AdministrationWindow.h>

#include <QtGui>

#include <DQuizSelector.h>

AdministrationWindow::AdministrationWindow(QWidget* parent)
    : QMainWindow(parent)
{
    setWindowTitle(tr("Android Kviz - Administracija"));
    
    m_mdiArea = new QMdiArea(this);
    setCentralWidget(m_mdiArea);
    
    setupMenu();
    
    DQuizSelector quizSelector;
    quizSelector.exec();
}

AdministrationWindow::~AdministrationWindow(void)
{
}

void AdministrationWindow::setupMenu(void)
{
    m_actionBrziPrsti = menuBar()->addAction(tr("&Brzi prsti"));
    
    m_actionKoZnaZna = menuBar()->addAction(tr("&Ko zna zna"));
    
    m_actionAsocijacije = menuBar()->addAction(tr("&Asocijacije"));
}