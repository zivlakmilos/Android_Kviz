#include <WQuizControl.h>

#include <QtGui>

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
        m_sliderVreme[i] = new QSlider(Qt::Horizontal, this);
        
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
    m_btnRekordi = new QPushButton(tr("&Rekordi"), this);
    
    m_layoutMian->addWidget(m_btnSledecePitanje);
    m_layoutMian->addWidget(m_btnRekordi);
}