#include <WQuizControl.h>

#include <QtGui>

#include <data/kviz.h>

WQuizControl::WQuizControl(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle(tr("Kontrola kviza"));
    
    setupGui();
}

WQuizControl::~WQuizControl(void)
{
}

void WQuizControl::setupGui(void)
{
    int i;
    
    m_layoutMian = new QVBoxLayout(this);
    setLayout(m_layoutMian);
    
    for(i = 0; i < BrojTipova; i++)
    {
        m_layoutSubMain[i] = new QVBoxLayout(this);
        m_layoutVreme[i] = new QHBoxLayout(this);
        m_layoutBrojPitanja[i] = new QHBoxLayout(this);
        
        m_gbOpcije[i] = new QGroupBox(m_labels[i], this);
        
        m_lblBrojPitanja[i] = new QLabel(tr("Broj pitanja: "), this);
        m_lblVreme[i] = new QLabel(tr("Vreme: "), this);
        
        m_sbBrojPitanja[i] = new QSpinBox(this);
        m_sliderBrojPitanja[i] = new QSlider(Qt::Horizontal, this);
        
        m_sbVreme[i] = new QSpinBox(this);
        m_sbVreme[i]->setMaximum(120);
        m_sliderVreme[i] = new QSlider(Qt::Horizontal, this);
        m_sliderVreme[i]->setMaximum(120);
        
        m_layoutBrojPitanja[i]->addWidget(m_sliderBrojPitanja[i]);
        m_layoutBrojPitanja[i]->addWidget(m_sbBrojPitanja[i]);
        m_layoutVreme[i]->addWidget(m_sliderVreme[i]);
        m_layoutVreme[i]->addWidget(m_sbVreme[i]);
        
        m_layoutSubMain[i]->addWidget(m_lblBrojPitanja[i]);
        m_layoutSubMain[i]->addLayout(m_layoutBrojPitanja[i]);
        m_layoutSubMain[i]->addWidget(m_lblVreme[i]);
        m_layoutSubMain[i]->addLayout(m_layoutVreme[i]);
        
        m_gbOpcije[i]->setLayout(m_layoutSubMain[i]);
        m_layoutMian->addWidget(m_gbOpcije[i]);
        
        connect(m_sbBrojPitanja[i], SIGNAL(valueChanged(int)),
                m_sliderBrojPitanja[i], SLOT(setValue(int)));
        connect(m_sliderBrojPitanja[i], SIGNAL(valueChanged(int)),
                m_sbBrojPitanja[i], SLOT(setValue(int)));
        connect(m_sbVreme[i], SIGNAL(valueChanged(int)),
                m_sliderVreme[i], SLOT(setValue(int)));
        connect(m_sliderVreme[i], SIGNAL(valueChanged(int)),
                m_sbVreme[i], SLOT(setValue(int)));
    }
    
    m_btnSledecePitanje = new QPushButton(tr("&Sledece pitanje"), this);
    connect(m_btnSledecePitanje, SIGNAL(clicked()),
            this, SLOT(btnSledecePitanje_click()));
    
    m_btnRekordi = new QPushButton(tr("&Rekordi"), this);
    connect(m_btnRekordi, SIGNAL(clicked()),
            this, SLOT(btnRekordi_click()));
    
    m_layoutMian->addWidget(m_btnSledecePitanje);
    m_layoutMian->addWidget(m_btnRekordi);
}

void WQuizControl::btnSledecePitanje_click(void)
{
    int brziPrsti = m_sbBrojPitanja[BrziPrsti]->value();
    if(brziPrsti > 0)
    {
        int min, sec;
        min = m_sbVreme[BrziPrsti]->value() / 60;
        sec = m_sbVreme[BrziPrsti]->value() - min * 60;
        QTime vreme;
        vreme.setHMS(0, min, sec);
        m_sbBrojPitanja[BrziPrsti]->setValue(m_sbBrojPitanja[BrziPrsti]->value() - 1);
        m_sbBrojPitanja[BrziPrsti]->setMaximum(m_sbBrojPitanja[BrziPrsti]->maximum() - 1);
        m_sliderBrojPitanja[BrziPrsti]->setMaximum(m_sliderBrojPitanja[BrziPrsti]->maximum() - 1);
        m_btnSledecePitanje->setEnabled(false);
        emit sledecePitanje(Kviz::BrziPrsti, vreme);
    }
}

void WQuizControl::btnRekordi_click(void)
{
    emit rekordi();
}

void WQuizControl::setBrojBrzihPrstiju(int brojBrzihPrstiju)
{
    m_sbBrojPitanja[BrziPrsti]->setMaximum(brojBrzihPrstiju);
    m_sliderBrojPitanja[BrziPrsti]->setMaximum(brojBrzihPrstiju);
}

void WQuizControl::zavrsiPitanje(void)
{
    m_btnSledecePitanje->setEnabled(true);
}