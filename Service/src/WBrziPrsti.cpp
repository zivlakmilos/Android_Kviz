#include <WBrziPrsti.h>

#include <QtGui>

WBrziPrsti::WBrziPrsti(QWidget *parent):
    QWidget(parent)
{
    setupGui();
}

WBrziPrsti::~WBrziPrsti(void)
{
}

void WBrziPrsti::setupGui(void)
{
    /*
     * Setup layous
     */
    
    m_layoutMain = new QGridLayout(this);
    setLayout(m_layoutMain);
    
    /*
     * Setup components
     */
    
    m_lblPitanje = new QLabel(this);
    m_lblA = new QLabel(this);
    m_lblB = new QLabel(this);
    m_lblC = new QLabel(this);
    m_lblD = new QLabel(this);
    
    /*
     * Lay down components
     */
    
    m_layoutMain->addWidget(m_lblPitanje, 0, 0, 1, 2);
    m_layoutMain->addWidget(m_lblA, 1, 0);
    m_layoutMain->addWidget(m_lblB, 1, 1);
    m_layoutMain->addWidget(m_lblC, 2, 0);
    m_layoutMain->addWidget(m_lblD, 2, 1);
}