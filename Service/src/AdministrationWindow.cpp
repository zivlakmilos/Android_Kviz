#include <AdministrationWindow.h>

#include <QtGui>

#include <data/kviz.h>
#include <Database.h>
#include <DPitanje.h>
#include <DBrziPrsti.h>

AdministrationWindow::AdministrationWindow(QWidget* parent)
    : QMainWindow(parent)
{
    setWindowTitle(tr("Android Kviz - Administracija"));
    
    m_mdiArea = new QMdiArea(this);
    setCentralWidget(m_mdiArea);
    connect(m_mdiArea, SIGNAL(subWindowActivated(QMdiSubWindow*)),
            this, SLOT(subWindowsActiveChanged(QMdiSubWindow*)));
    
    setupMenu();
    setupStatusBar();
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
    m_menuPomoc->setIcon(QIcon(tr(":img/help.png")));
    menuBar()->addMenu(m_menuPomoc);
    
    /*
     * Tool Bars
     */
    
    m_tbPitanja = addToolBar(tr("Pitanja"));
    m_tbPitanja->hide();
    
    m_tbPitanjaDodatni = addToolBar(tr("Pitanja Dodatni"));
    m_tbPitanjaDodatni->hide();
    
    /*
     * Actions
     */
    
    m_actionNoviKviz = m_menuKviz->addAction(tr("&Novi kviz"));
    m_actionNoviKviz->setIcon(QIcon(tr(":img/new_kviz.png")));
    m_actionNoviKviz->setToolTip(tr("Kreiranje novog kviza"));
    m_actionNoviKviz->setStatusTip(tr("Kreiranje novok kviza"));
    connect(m_actionNoviKviz, SIGNAL(triggered()),
            this, SLOT(actionNoviKviz_click()));
    
    m_actionOtvoriKviz = m_menuKviz->addAction(tr("&Otvori kviz"));
    m_actionOtvoriKviz->setToolTip(tr("Otvaranje kviza za administraciju"));
    m_actionOtvoriKviz->setStatusTip(tr("Otvaranje kviza za administraciju"));
    connect(m_actionOtvoriKviz, SIGNAL(triggered()),
            this, SLOT(actionOtvoriKviz_click()));
    
    m_actionIzmenaKvizova = m_menuKviz->addAction(tr("&Izmena kvizova"));
    m_actionIzmenaKvizova->setToolTip(tr("Izmena i brisanje kvizova"));
    m_actionIzmenaKvizova->setStatusTip(tr("Izmena i brisanje kvizova"));
    
    m_actionOProgramu = m_menuPomoc->addAction(tr("&O programu"));
    
    m_actionBrziPrsti = m_tbPitanja->addAction(tr("Brzi prsti"));
    m_actionBrziPrsti->setIcon(QIcon(tr(":img/brzi_prsti.jpg")));
    m_actionBrziPrsti->setToolTip(tr("Izmena, dodavanje i brisanje pitanja za brze prste"));
    m_actionBrziPrsti->setStatusTip(tr("Izmena, dodavanje i brisanje pitanja za brze prste"));
    connect(m_actionBrziPrsti, SIGNAL(triggered()),
            this, SLOT(actionBrziPrsti_click()));
    
    m_actionKoZnaZna = m_tbPitanja->addAction(tr("Ko zna zna"));
    m_actionKoZnaZna->setIcon(QIcon(tr(":img/ko_zna_zna.png")));
    m_actionKoZnaZna->setToolTip(tr("Izmena, dodatavanje i brisanje pitanja za ko zna zna"));
    m_actionKoZnaZna->setStatusTip(tr("Izmena, dodatavanje i brisanje pitanja za ko zna zna"));
    
    m_actionAsocijacije = m_tbPitanja->addAction(tr("Asocijacije"));
    m_actionAsocijacije->setIcon(QIcon(tr(":img/asocijacije.jpg")));
    m_actionAsocijacije->setToolTip(tr("Izmena, dodavanja i brisanje asocijacija"));
    m_actionAsocijacije->setStatusTip(tr("Izmena, dodavanje i brisanje asocijacija"));
    
    m_actionNovoPitanje = m_tbPitanjaDodatni->addAction(tr("Novo pitanje"));
    m_actionNovoPitanje->setIcon(QIcon(tr(":img/new_question")));
    m_actionNovoPitanje->setToolTip(tr("Kreiranje novog pitanja"));
    m_actionNovoPitanje->setStatusTip(tr("Kreiranje novog pitanja"));
    connect(m_actionNovoPitanje, SIGNAL(triggered()),
            this, SLOT(actionNovoPitanje_click()));
    
    m_actionObrisiPitanje = m_tbPitanjaDodatni->addAction(tr("Obrisi pitanje"));
    m_actionObrisiPitanje->setIcon(QIcon(tr(":img/delete_question")));
    m_actionObrisiPitanje->setToolTip(tr("Brisanje selektovanog pitanja"));
    m_actionObrisiPitanje->setStatusTip(tr("Brisanje selektovanog pitanja"));
    connect(m_actionObrisiPitanje, SIGNAL(triggered()),
            this, SLOT(actionObrisiPitanje_click()));
}

void AdministrationWindow::setupStatusBar(void)
{
    statusBar();
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

void AdministrationWindow::closeEvent(QCloseEvent *event)
{
    emit close();
    event->accept();
}

void AdministrationWindow::actionBrziPrsti_click(void)
{
    DBrziPrsti *brziPrsti = new DBrziPrsti(&m_kviz, this);
    QMdiSubWindow *subWindow = m_mdiArea->addSubWindow(brziPrsti);
    
    brziPrsti->addAction(m_actionNovoPitanje);
    brziPrsti->addAction(m_actionObrisiPitanje);
    
    m_actionBrziPrsti->setEnabled(false);
    subWindow->show();
    
    connect(brziPrsti, SIGNAL(close(bool)),
            m_actionBrziPrsti, SLOT(setEnabled(bool)));
}

void AdministrationWindow::actionNovoPitanje_click(void)
{
    QMdiSubWindow *activeWindow = m_mdiArea->activeSubWindow();
    
    if(DPitanje *pitanje = dynamic_cast<DPitanje*>(activeWindow->widget()))
    {
        pitanje->novoPitanje();
    }
}

void AdministrationWindow::actionObrisiPitanje_click(void)
{
    QMdiSubWindow *activeWindow = m_mdiArea->activeSubWindow();
    
    if(DPitanje *pitanje = dynamic_cast<DPitanje*>(activeWindow->widget()))
    {
        pitanje->obrisiPitanje();
    }
}

void AdministrationWindow::subWindowsActiveChanged(QMdiSubWindow* activeWindow)
{
    if(!activeWindow)
    {
        m_tbPitanjaDodatni->hide();
    } else
    {
        m_tbPitanjaDodatni->show();
    }
}