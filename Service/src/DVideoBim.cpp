#include <DVideoBim.h>

#include <QtGui>

#include <data/kviz.h>

#include <Database.h>
#include <TcpService.h>
#include <WQuizControl.h>
#include <WBrziPrsti.h>

DVideoBim::DVideoBim(int kvizId, QWidget *parent)
    : QWidget(parent),
      m_kvizId(kvizId),
      m_status(S_IDLE)
{
    setWindowTitle(tr("Android Kviz"));
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
            rbPitanja = qrand() % m_brziPrsti.size();
            BrziPrsti tmp = m_brziPrsti.at(rbPitanja);
            m_brziPrsti.removeAt(rbPitanja);
            m_wBrziPrsti = new WBrziPrsti(&tmp, this);
            m_splitter->addWidget(m_wBrziPrsti);
            m_splitter->setStretchFactor(1, 1);
            m_zadatoVreme = vreme;
            m_wBrziPrsti->setMaxVreme(vreme.second() + 60 * vreme.minute());
            m_trenutnoVreme.setHMS(0, 0, 0);
            m_timer->start();
            break;
    }
}

void DVideoBim::rekordi(void)
{
}

void DVideoBim::pitanjeTimeout(void)
{
    m_trenutnoVreme = m_trenutnoVreme.addSecs(1);
    m_wBrziPrsti->setVreme(m_trenutnoVreme.second() + 60 * m_trenutnoVreme.minute());
    if(m_trenutnoVreme >= m_zadatoVreme)
    {
        delete m_wBrziPrsti;
        m_wQuizControl->zavrsiPitanje();
        m_timer->stop();
    }
}

void DVideoBim::recivedData(int id, QString data)
{
    switch(m_status)
    {
        case S_Prijava:
            if(!m_rekordi.contains(id))
            {
                Takmicar takmicar(id, data);
                m_rekordi[id] = takmicar;
            }
            break;
    }
    qDebug() << m_rekordi[id].getIme();
}