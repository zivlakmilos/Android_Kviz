#include <DAsocijacijeEdit.h>

#include <QtGui>

#include <data/asocijacije.h>

DAsocijacijeEdit::DAsocijacijeEdit(Asocijacije *pitanje, QWidget *parent)
    : QDialog(parent),
      m_pitanje(pitanje)
{
    setupGui();
    
    connect(this, SIGNAL(accepted()), this, SLOT(prihvati()));
}

DAsocijacijeEdit::~DAsocijacijeEdit(void)
{
}

void DAsocijacijeEdit::setupGui(void)
{
    /*
     * Create layouts
     */
    
    m_layoutMain = new QVBoxLayout(this);
    this->setLayout(m_layoutMain);
    m_layoutKonacnoResenje = new QHBoxLayout(this);
    m_layoutAB = new QHBoxLayout(this);
    m_layoutAB1 = new QHBoxLayout(this);
    m_layoutAB2 = new QHBoxLayout(this);
    m_layoutAB3 = new QHBoxLayout(this);
    m_layoutAB4 = new QHBoxLayout(this);
    m_layoutCD = new QHBoxLayout(this);
    m_layoutCD1 = new QHBoxLayout(this);
    m_layoutCD2 = new QHBoxLayout(this);
    m_layoutCD3 = new QHBoxLayout(this);
    m_layoutCD4 = new QHBoxLayout(this);
    m_layoutButtons = new QHBoxLayout(this);
    
    /*
     * Setup components
     */
    
    m_txtKonacnoResenje = new QLineEdit(m_pitanje->getKonacnoResenje(), this);
    
    m_txtA = new QLineEdit(m_pitanje->getA(), this);
    m_txtB = new QLineEdit(m_pitanje->getB(), this);
    m_txtC = new QLineEdit(m_pitanje->getC(), this);
    m_txtD = new QLineEdit(m_pitanje->getD(), this);
    
    m_txtA1 = new QLineEdit(m_pitanje->getA1(), this);
    m_txtA2 = new QLineEdit(m_pitanje->getA2(), this);
    m_txtA3 = new QLineEdit(m_pitanje->getA3(), this);
    m_txtA4 = new QLineEdit(m_pitanje->getA4(), this);
    
    m_txtB1 = new QLineEdit(m_pitanje->getB1(), this);
    m_txtB2 = new QLineEdit(m_pitanje->getB2(), this);
    m_txtB3 = new QLineEdit(m_pitanje->getB3(), this);
    m_txtB4 = new QLineEdit(m_pitanje->getB4(), this);
    
    m_txtC1 = new QLineEdit(m_pitanje->getC1(), this);
    m_txtC2 = new QLineEdit(m_pitanje->getC2(), this);
    m_txtC3 = new QLineEdit(m_pitanje->getC3(), this);
    m_txtC4 = new QLineEdit(m_pitanje->getC4(), this);
    
    m_txtD1 = new QLineEdit(m_pitanje->getD1(), this);
    m_txtD2 = new QLineEdit(m_pitanje->getD2(), this);
    m_txtD3 = new QLineEdit(m_pitanje->getD3(), this);
    m_txtD4 = new QLineEdit(m_pitanje->getD4(), this);
    
    m_btnOk = new QPushButton(tr("&Ok"), this);
    connect(m_btnOk, SIGNAL(clicked()), this, SLOT(accept()));
    
    m_btnCancel = new QPushButton(tr("&Cancel"), this);
    connect(m_btnCancel, SIGNAL(clicked()), this, SLOT(reject()));
    
    /*
     * Lay down components and layouts
     */
    
    m_layoutAB4->addWidget(m_txtA4);
    m_layoutAB4->addSpacerItem(new QSpacerItem(160, m_txtA->height()));
    m_layoutAB4->addWidget(m_txtB4);
    
    m_layoutAB3->addSpacerItem(new QSpacerItem(20, m_txtA->height()));
    m_layoutAB3->addWidget(m_txtA3);
    m_layoutAB3->addSpacerItem(new QSpacerItem(120, m_txtA->height()));
    m_layoutAB3->addWidget(m_txtB3);
    m_layoutAB3->addSpacerItem(new QSpacerItem(20, m_txtA->height()));
    
    m_layoutAB2->addSpacerItem(new QSpacerItem(40, m_txtA->height()));
    m_layoutAB2->addWidget(m_txtA2);
    m_layoutAB2->addSpacerItem(new QSpacerItem(80, m_txtA->height()));
    m_layoutAB2->addWidget(m_txtB2);
    m_layoutAB2->addSpacerItem(new QSpacerItem(40, m_txtA->height()));
    
    m_layoutAB1->addSpacerItem(new QSpacerItem(60, m_txtA->height()));
    m_layoutAB1->addWidget(m_txtA1);
    m_layoutAB1->addSpacerItem(new QSpacerItem(40, m_txtA->height()));
    m_layoutAB1->addWidget(m_txtB1);
    m_layoutAB1->addSpacerItem(new QSpacerItem(60, m_txtA->height()));
    
    m_layoutAB->addSpacerItem(new QSpacerItem(80, m_txtA->height()));
    m_layoutAB->addWidget(m_txtA);
    m_layoutAB->addWidget(m_txtB);
    m_layoutAB->addSpacerItem(new QSpacerItem(80, m_txtA->height()));
    
    m_layoutKonacnoResenje->addSpacerItem(new QSpacerItem(80, m_txtKonacnoResenje->height()));
    m_layoutKonacnoResenje->addWidget(m_txtKonacnoResenje);
    m_layoutKonacnoResenje->addSpacerItem(new QSpacerItem(80, m_txtKonacnoResenje->height()));
    
    m_layoutCD->addSpacerItem(new QSpacerItem(80, m_txtC->height()));
    m_layoutCD->addWidget(m_txtC);
    m_layoutCD->addWidget(m_txtD);
    m_layoutCD->addSpacerItem(new QSpacerItem(80, m_txtC->height()));
     
    m_layoutCD1->addSpacerItem(new QSpacerItem(60, m_txtC->height()));
    m_layoutCD1->addWidget(m_txtC1);
    m_layoutCD1->addSpacerItem(new QSpacerItem(40, m_txtC->height()));
    m_layoutCD1->addWidget(m_txtD1);
    m_layoutCD1->addSpacerItem(new QSpacerItem(60, m_txtC->height()));
    
    m_layoutCD2->addSpacerItem(new QSpacerItem(40, m_txtC->height()));
    m_layoutCD2->addWidget(m_txtC2);
    m_layoutCD2->addSpacerItem(new QSpacerItem(80, m_txtC->height()));
    m_layoutCD2->addWidget(m_txtD2);
    m_layoutCD2->addSpacerItem(new QSpacerItem(40, m_txtC->height()));
    
    m_layoutCD3->addSpacerItem(new QSpacerItem(20, m_txtC->height()));
    m_layoutCD3->addWidget(m_txtC3);
    m_layoutCD3->addSpacerItem(new QSpacerItem(120, m_txtC->height()));
    m_layoutCD3->addWidget(m_txtD3);
    m_layoutCD3->addSpacerItem(new QSpacerItem(20, m_txtC->height()));
    
    m_layoutCD4->addWidget(m_txtC4);
    m_layoutCD4->addSpacerItem(new QSpacerItem(160, m_txtC->height()));
    m_layoutCD4->addWidget(m_txtD4);
    
    m_layoutButtons->addWidget(m_btnOk);
    m_layoutButtons->addWidget(m_btnCancel);
    
    m_layoutMain->addLayout(m_layoutAB4);
    m_layoutMain->addLayout(m_layoutAB3);
    m_layoutMain->addLayout(m_layoutAB2);
    m_layoutMain->addLayout(m_layoutAB1);
    m_layoutMain->addLayout(m_layoutAB);
    m_layoutMain->addLayout(m_layoutKonacnoResenje);
    m_layoutMain->addLayout(m_layoutCD);
    m_layoutMain->addLayout(m_layoutCD1);
    m_layoutMain->addLayout(m_layoutCD2);
    m_layoutMain->addLayout(m_layoutCD3);
    m_layoutMain->addLayout(m_layoutCD4);
    m_layoutMain->addLayout(m_layoutButtons);
}

void DAsocijacijeEdit::prihvati(void)
{
    m_pitanje->setKonacnoResenje(m_txtKonacnoResenje->text());
    m_pitanje->setA(m_txtA->text());
    m_pitanje->setB(m_txtB->text());
    m_pitanje->setC(m_txtC->text());
    m_pitanje->setD(m_txtD->text());
    m_pitanje->setA1(m_txtA1->text());
    m_pitanje->setA2(m_txtA2->text());
    m_pitanje->setA3(m_txtA3->text());
    m_pitanje->setA4(m_txtA4->text());
    m_pitanje->setB1(m_txtB1->text());
    m_pitanje->setB2(m_txtB2->text());
    m_pitanje->setB3(m_txtB3->text());
    m_pitanje->setB4(m_txtB4->text());
    m_pitanje->setC1(m_txtC1->text());
    m_pitanje->setC2(m_txtC2->text());
    m_pitanje->setC3(m_txtC3->text());
    m_pitanje->setC4(m_txtC4->text());
    m_pitanje->setD1(m_txtD1->text());
    m_pitanje->setD2(m_txtD2->text());
    m_pitanje->setD3(m_txtD3->text());
    m_pitanje->setD4(m_txtD4->text());
}