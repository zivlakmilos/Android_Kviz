#include <DVideoBim.h>

#include <QtGui>

#include <data/kviz.h>

#include <Database.h>
#include <TcpService.h>
#include <WQuizControl.h>
#include <WBrziPrsti.h>
#include <WRekordi.h>

DVideoBim::DVideoBim(int kvizId, QWidget *parent)
    : QWidget(parent),
      m_kvizId(kvizId),
      m_status(S_IDLE),
      m_wRekordi(nullptr)
{
    setupGui();
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    
    Database db;
    if(db.open())
    {
        m_brziPrsti = db.preuzmiBrzePrste(m_kvizId);
    }
    
    m_wQuizControl->setBrojBrzihPrstiju(m_brziPrsti.size());
    
    m_timer = new QTimer(this);
    m_timer->setInterval(1000);
    connect(m_timer, SIGNAL(timeout()),
            this, SLOT(pitanjeTimeout()));
    
    m_service = new TcpService(this);
    if(!m_service->start())
    {
        QMessageBox::warning(this, tr("Android Kviz"),
                             tr("Nije moguce pokrenuti servis!"),
                             QMessageBox::QMessageBox::Ok);
        close();
    } else
    {
        connect(m_service, SIGNAL(recivedData(int, QString)),
                this, SLOT(recivedData(int, QString)));
        m_status = S_Prijava;
        QProgressDialog *prijava = new QProgressDialog(this);
        prijava->setLabelText(tr("Prijava takmicara"));
        prijava->setCancelButtonText(tr("Zavrsi prijavu"));
        prijava->setRange(0, 0);
        prijava->setValue(0);
        prijava->exec();
        m_status = S_IDLE;
    }
}

DVideoBim::~DVideoBim(void)
{
    m_service->close();
    delete m_service;
}

void DVideoBim::setupGui(void)
{
    m_layoutMain = new QVBoxLayout(this);
    setLayout(m_layoutMain);
    
    m_splitter = new QSplitter(Qt::Horizontal, this);
    
    m_wQuizControl = new WQuizControl(this);
    connect(m_wQuizControl, SIGNAL(sledecePitanje(int, QTime)),
            this, SLOT(sledecePitanje(int, QTime)));
    connect(m_wQuizControl, SIGNAL(rekordi()),
            this, SLOT(rekordi()));
    
    m_splitter->addWidget(m_wQuizControl);
    
    m_splitter->setStretchFactor(1, 1);
    m_layoutMain->addWidget(m_splitter);
}

void DVideoBim::closeEvent(QCloseEvent* event)
{
    emit close();
    event->accept();
}

void DVideoBim::sledecePitanje(int tip, QTime vreme)
{
    int rbPitanja;
    switch(tip)
    {
        case Kviz::BrziPrsti:
            if(m_wRekordi)
            {
                delete m_wRekordi;
                m_wRekordi = nullptr;
            }
            rbPitanja = qrand() % m_brziPrsti.size();
            BrziPrsti tmp = m_brziPrsti.at(rbPitanja);
            m_wBrziPrsti = new WBrziPrsti(&tmp, this);
            m_splitter->addWidget(m_wBrziPrsti);
            m_splitter->setStretchFactor(1, 1);
            m_zadatoVreme = vreme;
            m_wBrziPrsti->setMaxVreme(vreme.second() + 60 * vreme.minute());
            m_trenutnoVreme.setHMS(0, 0, 0);
            m_bodovi = m_rekordi.size();
            m_rbPitanja = rbPitanja;
            m_status = S_BrziPrsti;
            m_timer->start();
            break;
    }
}

void DVideoBim::rekordi(void)
{
    if(m_wRekordi)
        return;
    
    QList<Takmicar> rekordi;
    for(auto id : m_rekordi.keys())
    {
        Takmicar takmicar = m_rekordi[id];
        int i;
        for(i = 0; i < rekordi.size(); i++)
        {
            if(takmicar.getBodoviUkupno() > rekordi[i].getBodoviUkupno())
            {
                rekordi.insert(i, takmicar);
                break;
            }
        }
        if(i == rekordi.size())
        {
            rekordi.append(takmicar);
        }
    }
    
    m_wRekordi = new WRekordi(rekordi, this);
    m_splitter->addWidget(m_wRekordi);
    m_splitter->setStretchFactor(1, 1);
}

void DVideoBim::pitanjeTimeout(void)
{
    m_trenutnoVreme = m_trenutnoVreme.addSecs(1);
    m_wBrziPrsti->setVreme(m_trenutnoVreme.second() + 60 * m_trenutnoVreme.minute());
    if(m_trenutnoVreme >= m_zadatoVreme)
    {
        delete m_wBrziPrsti;
        m_wQuizControl->zavrsiPitanje();
        m_status = S_IDLE;
        m_timer->stop();
        m_brziPrsti.removeAt(m_rbPitanja);
    }
}

void DVideoBim::recivedData(int id, QString data)
{
    if(data.isEmpty())
        return;
    
    data = data.remove(data.size() - 1, 1);     // Zbog testiranja, kasnije mozda ukloniti
    switch(m_status)
    {
        case S_Prijava:
            if(!m_rekordi.contains(id))
            {
                Takmicar takmicar(id, data);
                m_rekordi[id] = takmicar;
            }
            break;
        case S_BrziPrsti:
            if(m_rekordi.contains(id))
            {
                if(data[0].toUpper() ==
                    m_brziPrsti.at(m_rbPitanja).getOdgovor().toUpper())
                {
                    m_rekordi[id].addBodoviBrziPrsti(m_bodovi);
                    m_bodovi--;
                }
            }
            break;
    }
}