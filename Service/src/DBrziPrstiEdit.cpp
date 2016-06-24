#include <DBrziPrstiEdit.h>

#include <QtGui>

#include <data/brziprsti.h>

DBrziPrstiEdit::DBrziPrstiEdit(BrziPrsti *pitanje, QWidget *parent)
    : QDialog(parent),
      m_pitanje(pitanje)
{
    setupGui();
}

DBrziPrstiEdit::~DBrziPrstiEdit(void)
{
}

void DBrziPrstiEdit::setupGui(void)
{
    m_layoutMain = new QVBoxLayout(this);
    setLayout(m_layoutMain);
    m_layoutOdgovor = new QHBoxLayout(this);
    m_layoutButtons = new QHBoxLayout(this);
    
    m_lblPitanje = new QLabel(tr("Pitanje:"), this);
    m_txtPitanje = new QLineEdit(this);
    m_txtPitanje->setText(m_pitanje->getPitanje());
    
    m_lblA = new QLabel(tr("A:"), this);
    m_txtA = new QLineEdit(this);
    m_txtA->setText(m_pitanje->getA());
    
    m_lblB = new QLabel(tr("B:"), this);
    m_txtB = new QLineEdit(this);
    m_txtB->setText(m_pitanje->getB());
    
    m_lblC = new QLabel(tr("C:"), this);
    m_txtC = new QLineEdit(this); 
    m_txtC->setText(m_pitanje->getC());
    
    m_lblD = new QLabel(tr("D:"), this);
    m_txtD = new QLineEdit(this);
    m_txtD->setText(m_pitanje->getD());
    
    m_lblOdgovor = new QLabel(tr("Odgovor:"), this);
    m_cbOdgovor = new QComboBox(this);
    for(char i = 'A'; i <= 'D'; i++)
    {
        m_cbOdgovor->addItem(QString(i));
        if(m_pitanje->getOdgovor().toCaseFolded() == QChar(i).toCaseFolded())
        {
            m_cbOdgovor->setCurrentIndex(i - 'A');
        }
    }
    
    m_btnOk = new QPushButton(tr("&Ok"), this);
    connect(m_btnOk, SIGNAL(clicked()), this, SLOT(accept()));
    
    m_btnCancel = new QPushButton(tr("&Cancel"), this);
    connect(m_btnCancel, SIGNAL(clicked()), this, SLOT(reject()));
   
    m_layoutOdgovor->addWidget(m_lblOdgovor);
    m_layoutOdgovor->addWidget(m_cbOdgovor);
    
    m_layoutButtons->addWidget(m_btnOk);
    m_layoutButtons->addWidget(m_btnCancel);
  
    m_layoutMain->addWidget(m_lblPitanje);
    m_layoutMain->addWidget(m_txtPitanje);
    m_layoutMain->addWidget(m_lblA);
    m_layoutMain->addWidget(m_txtA);
    m_layoutMain->addWidget(m_lblB);
    m_layoutMain->addWidget(m_txtB);
    m_layoutMain->addWidget(m_lblC);
    m_layoutMain->addWidget(m_txtC);
    m_layoutMain->addWidget(m_lblD);
    m_layoutMain->addWidget(m_txtD);
    m_layoutMain->addLayout(m_layoutOdgovor);
    m_layoutMain->addLayout(m_layoutButtons);
    
    connect(this, SIGNAL(accepted()), this, SLOT(prihvati()));
}

void DBrziPrstiEdit::prihvati(void)
{
    m_pitanje->setPitanje(m_txtPitanje->text());
    m_pitanje->setA(m_txtA->text());
    m_pitanje->setB(m_txtB->text());
    m_pitanje->setC(m_txtC->text());
    m_pitanje->setD(m_txtD->text());
    m_pitanje->setOdgovor(m_cbOdgovor->currentText().at(0));
}