#include <WAsocijacijePreview.h>

#include <QtGui>

#include <data/asocijacije.h>

WAsocijacijePreview::WAsocijacijePreview(QWidget *parent)
    : QWidget(parent)
{
    setupGui();
    
    setWindowFlags(Qt::Popup | Qt::FramelessWindowHint);
}

WAsocijacijePreview::~WAsocijacijePreview(void)
{
}

void WAsocijacijePreview::setupGui(void)
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
    
    /*
     * Setup components
     */
    
    m_lblKonacnoResenje = new QLabel(this);
    
    m_lblA = new QLabel(this);
    m_lblB = new QLabel(this);
    m_lblC = new QLabel(this);
    m_lblD = new QLabel(this);
    
    m_lblA1 = new QLabel(this);
    m_lblA2 = new QLabel(this);
    m_lblA3 = new QLabel(this);
    m_lblA4 = new QLabel(this);
    
    m_lblB1 = new QLabel(this);
    m_lblB2 = new QLabel(this);
    m_lblB3 = new QLabel(this);
    m_lblB4 = new QLabel(this);
    
    m_lblC1 = new QLabel(this);
    m_lblC2 = new QLabel(this);
    m_lblC3 = new QLabel(this);
    m_lblC4 = new QLabel(this);
    
    m_lblD1 = new QLabel(this);
    m_lblD2 = new QLabel(this);
    m_lblD3 = new QLabel(this);
    m_lblD4 = new QLabel(this);
    
    /*
     * Lay down components and layouts
     */
    
    m_layoutAB4->addWidget(m_lblA4);
    m_layoutAB4->addSpacerItem(new QSpacerItem(160, m_lblA->height()));
    m_layoutAB4->addWidget(m_lblB4);
    
    m_layoutAB3->addSpacerItem(new QSpacerItem(20, m_lblA->height()));
    m_layoutAB3->addWidget(m_lblA3);
    m_layoutAB3->addSpacerItem(new QSpacerItem(120, m_lblA->height()));
    m_layoutAB3->addWidget(m_lblB3);
    m_layoutAB3->addSpacerItem(new QSpacerItem(20, m_lblA->height()));
    
    m_layoutAB2->addSpacerItem(new QSpacerItem(40, m_lblA->height()));
    m_layoutAB2->addWidget(m_lblA2);
    m_layoutAB2->addSpacerItem(new QSpacerItem(80, m_lblA->height()));
    m_layoutAB2->addWidget(m_lblB2);
    m_layoutAB2->addSpacerItem(new QSpacerItem(40, m_lblA->height()));
    
    m_layoutAB1->addSpacerItem(new QSpacerItem(60, m_lblA->height()));
    m_layoutAB1->addWidget(m_lblA1);
    m_layoutAB1->addSpacerItem(new QSpacerItem(40, m_lblA->height()));
    m_layoutAB1->addWidget(m_lblB1);
    m_layoutAB1->addSpacerItem(new QSpacerItem(60, m_lblA->height()));
    
    m_layoutAB->addSpacerItem(new QSpacerItem(80, m_lblA->height()));
    m_layoutAB->addWidget(m_lblA);
    m_layoutAB->addWidget(m_lblB);
    m_layoutAB->addSpacerItem(new QSpacerItem(80, m_lblA->height()));
    
    m_layoutKonacnoResenje->addSpacerItem(new QSpacerItem(80, m_lblKonacnoResenje->height()));
    m_layoutKonacnoResenje->addWidget(m_lblKonacnoResenje);
    m_layoutKonacnoResenje->addSpacerItem(new QSpacerItem(80, m_lblKonacnoResenje->height()));
    
    m_layoutCD->addSpacerItem(new QSpacerItem(80, m_lblC->height()));
    m_layoutCD->addWidget(m_lblC);
    m_layoutCD->addWidget(m_lblD);
    m_layoutCD->addSpacerItem(new QSpacerItem(80, m_lblC->height()));
     
    m_layoutCD1->addSpacerItem(new QSpacerItem(60, m_lblC->height()));
    m_layoutCD1->addWidget(m_lblC1);
    m_layoutCD1->addSpacerItem(new QSpacerItem(40, m_lblC->height()));
    m_layoutCD1->addWidget(m_lblD1);
    m_layoutCD1->addSpacerItem(new QSpacerItem(60, m_lblC->height()));
    
    m_layoutCD2->addSpacerItem(new QSpacerItem(40, m_lblC->height()));
    m_layoutCD2->addWidget(m_lblC2);
    m_layoutCD2->addSpacerItem(new QSpacerItem(80, m_lblC->height()));
    m_layoutCD2->addWidget(m_lblD2);
    m_layoutCD2->addSpacerItem(new QSpacerItem(40, m_lblC->height()));
    
    m_layoutCD3->addSpacerItem(new QSpacerItem(20, m_lblC->height()));
    m_layoutCD3->addWidget(m_lblC3);
    m_layoutCD3->addSpacerItem(new QSpacerItem(120, m_lblC->height()));
    m_layoutCD3->addWidget(m_lblD3);
    m_layoutCD3->addSpacerItem(new QSpacerItem(20, m_lblC->height()));
    
    m_layoutCD4->addWidget(m_lblC4);
    m_layoutCD4->addSpacerItem(new QSpacerItem(160, m_lblC->height()));
    m_layoutCD4->addWidget(m_lblD4);
    
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
}

void WAsocijacijePreview::setData(Asocijacije* pitanje)
{
    m_lblKonacnoResenje->setText(pitanje->getKonacnoResenje());
    m_lblA->setText(pitanje->getA());
    m_lblB->setText(pitanje->getB());
    m_lblC->setText(pitanje->getC());
    m_lblD->setText(pitanje->getD());
    m_lblA1->setText(pitanje->getA1());
    m_lblA2->setText(pitanje->getA2());
    m_lblA3->setText(pitanje->getA3());
    m_lblA4->setText(pitanje->getA4());
    m_lblB1->setText(pitanje->getB1());
    m_lblB2->setText(pitanje->getB2());
    m_lblB3->setText(pitanje->getB3());
    m_lblB4->setText(pitanje->getB4());
    m_lblC1->setText(pitanje->getC1());
    m_lblC2->setText(pitanje->getC2());
    m_lblC3->setText(pitanje->getC3());
    m_lblC4->setText(pitanje->getC4());
    m_lblD1->setText(pitanje->getD1());
    m_lblD2->setText(pitanje->getD2());
    m_lblD3->setText(pitanje->getD3());
    m_lblD4->setText(pitanje->getD4());
}