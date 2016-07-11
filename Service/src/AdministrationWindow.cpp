#include <AdministrationWindow.h>

#include <QtGui>

#include <data/kviz.h>
#include <Database.h>
#include <DPitanje.h>
#include <DBrziPrsti.h>
#include <DKoZnaZna.h>
#include <DAsocijacije.h>

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
    connect(m_actionOProgramu, SIGNAL(triggered()),
            this, SLOT(actionOProgramu_click()));
    
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
    connect(m_actionKoZnaZna, SIGNAL(triggered()),
            this, SLOT(actionKoZnaZna_click()));
    
    m_actionAsocijacije = m_tbPitanja->addAction(tr("Asocijacije"));
    m_actionAsocijacije->setIcon(QIcon(tr(":img/asocijacije.jpg")));
    m_actionAsocijacije->setToolTip(tr("Izmena, dodavanja i brisanje asocijacija"));
    m_actionAsocijacije->setStatusTip(tr("Izmena, dodavanje i brisanje asocijacija"));
    connect(m_actionAsocijacije, SIGNAL(triggered()),
            this, SLOT(actionAsocijacije_click()));
    
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
    bool ok;
    QString naziv = QInputDialog::getText(this, tr("Android Kviz"),
                                          tr("Naziv kviza:"), QLineEdit::Normal,
                                          "", &ok);
    if(ok && !naziv.isEmpty())
    {
        Database db;
        if(db.open())
        {
            Kviz kviz(naziv);
            kviz = db.snimiKviz(kviz);
            setKviz(kviz);
        }
    }
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
    
    QList<Kviz> kvizovi = db.preuzmiListuKvizova();
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

void AdministrationWindow::actionKoZnaZna_click(void)
{
    DKoZnaZna *koZnaZna = new DKoZnaZna(&m_kviz, this);
    QMdiSubWindow *subWindow = m_mdiArea->addSubWindow(koZnaZna);
    
    koZnaZna->addAction(m_actionNovoPitanje);
    koZnaZna->addAction(m_actionObrisiPitanje);
    
    m_actionKoZnaZna->setEnabled(false);
    subWindow->show();
    
    connect(koZnaZna, SIGNAL(close(bool)),
            m_actionKoZnaZna, SLOT(setEnabled(bool)));
}

void AdministrationWindow::actionAsocijacije_click(void)
{
    DAsocijacije *asocijacije = new DAsocijacije(&m_kviz, this);
    QMdiSubWindow *subWindow = m_mdiArea->addSubWindow(asocijacije);
    
    asocijacije->addAction(m_actionNovoPitanje);
    asocijacije->addAction(m_actionObrisiPitanje);
    
    m_actionAsocijacije->setEnabled(false);
    subWindow->show();
    
    connect(asocijacije, SIGNAL(close(bool)),
            m_actionAsocijacije, SLOT(setEnabled(bool)));
}

void AdministrationWindow::actionOProgramu_click(void)
{
    QMessageBox::about(this, tr("Android Kviz"),
                       tr("<div align=\"center\"><b>Milos Zivlak</b> <br /></div>"
                          "email1: zivlakmilos@gmail.com <br />"
                          "email2: zivlakmilos2@gmail.com <br />"
                          "email3: zi@zivlakmilos.ddns.net <br />"
                          "sajt:   <a href=\"http://zivlakmilos.ddns.net\">http://zivlakmilos.ddns.net</a> <br />"
                          "github: <a href=\"https://github.com/zivlakmilos\">https://github.com/zivlakmilos</a> <br />"));
}