#include <AdministrationWindow.h>

#include <QtGui>

#include <data/kviz.h>
#include <Database.h>

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
     * Tool Bars
     */
    
    m_tbPitanja = addToolBar(tr("Pitanja"));
    m_tbPitanja->hide();
    
    /*
     * Actions
     */
    
    m_actionNoviKviz = m_menuKviz->addAction(tr("&Novi kviz"));
    connect(m_actionNoviKviz, SIGNAL(triggered()),
            this, SLOT(actionNoviKviz_click()));
    
    m_actionOtvoriKviz = m_menuKviz->addAction(tr("&Otvori kviz"));
    connect(m_actionOtvoriKviz, SIGNAL(triggered()),
            this, SLOT(actionOtvoriKviz_click()));
    
    m_actionIzmenaKvizova = m_menuKviz->addAction(tr("&Izmena kvizova"));
    
    m_actionOProgramu = m_menuPomoc->addAction(tr("&O programu"));
    
    m_actionBrziPrsti = m_tbPitanja->addAction(tr("Brzi prsti"));
    m_actionBrziPrsti->setIcon(QIcon(tr(":img/brzi_prsti.jpg")));
    
    m_actionKoZnaZna = m_tbPitanja->addAction(tr("Ko zna zna"));
    m_actionKoZnaZna->setIcon(QIcon(tr(":img/ko_zna_zna.png")));
    
    m_actionAsocijacije = m_tbPitanja->addAction(tr("Asocijacije"));
    m_actionAsocijacije->setIcon(QIcon(tr(":img/asocijacije.jpg")));
}

void AdministrationWindow::actionNoviKviz_click(void)
{
}

void AdministrationWindow::actionOtvoriKviz_click(void)
{
    Database db;
    if(!db.open())
    {
        QMessageBox::warning(this, tr("Android Kviz"),
                             tr("Greska prilikom komunikacije sa bazom podataka"),
                             QMessageBox::Ok);
        return;
    }
    
    QList<Kviz> kvizovi= db.preuzmiListuKvizova();
    QStringList items;
    bool ok;
    for(Kviz kviz : kvizovi)
    {
        items.append(kviz.getNaziv());
    }
    QString item = QInputDialog::getItem(this, tr("Android Kviz"),
                                         tr("Izbor kviza:"),
                                         items, 0, false, &ok);
    
    if(ok && !item.isEmpty())
    {
        for(Kviz kviz : kvizovi)
        {
            if(item == kviz.getNaziv())
            {
                setKviz(kviz);
            }
        }
    }
}

void AdministrationWindow::setKviz(Kviz kviz)
{
    m_kviz = kviz;
    m_tbPitanja->show();
}

void AdministrationWindow::closeEvent(QCloseEvent* event)
{
    emit close();
    event->accept();
}