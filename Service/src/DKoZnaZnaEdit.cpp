#include <DKoZnaZnaEdit.h>

#include <QtGui>

#include <data/koznazna.h>

DKoZnaZnaEdit::DKoZnaZnaEdit(KoZnaZna* pitanje, QWidget* parent)
    : QDialog(parent),
      m_pitanje(pitanje)
{
    setupGui();
    
    connect(this, SIGNAL(accepted()),
            this, SLOT(prihvati()));
}

DKoZnaZnaEdit::~DKoZnaZnaEdit(void)
{
}

void DKoZnaZnaEdit::setupGui(void)
{
    /*
     * Setup layouts
     */
    
    m_layoutMain = new QVBoxLayout(this);
    setLayout(m_layoutMain);
    m_layoutButtons = new QHBoxLayout(this);
    
    /*
     * Create components
     */
    
    m_lblPitanje = new QLabel(tr("Pitanje:"), this);
    m_txtPitanje = new QTextEdit(this);
    m_txtPitanje->setText(m_pitanje->getPitanje());
    
    m_lblOdgovor = new QLabel(tr("Odgovor:"), this);
    m_txtOdgovor = new QLineEdit(this);
    m_txtOdgovor->setText(m_pitanje->getOdgovor());
    
    m_btnOk = new QPushButton(tr("&OK"), this);
    connect(m_btnOk, SIGNAL(clicked()), this, SLOT(accept()));
    
    m_btnCancel = new QPushButton(tr("&Cancel"), this);
    connect(m_btnCancel, SIGNAL(clicked()), this, SLOT(reject()));
    
    /*
     * Setup components
     */
    
    m_layoutButtons->addWidget(m_btnOk);
    m_layoutButtons->addWidget(m_btnCancel);
    
    m_layoutMain->addWidget(m_lblPitanje);
    m_layoutMain->addWidget(m_txtPitanje);
    m_layoutMain->addWidget(m_lblOdgovor);
    m_layoutMain->addWidget(m_txtOdgovor);
    m_layoutMain->addLayout(m_layoutButtons);
}

void DKoZnaZnaEdit::prihvati(void)
{
    m_pitanje->setPitanje(m_txtPitanje->toPlainText());
    m_pitanje->setOdgovor(m_txtOdgovor->text());
}