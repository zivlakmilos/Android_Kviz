#include <WBrziPrsti.h>

#include <QtGui>

WBrziPrsti::WBrziPrsti(BrziPrsti *pitanje, QWidget *parent)
    : QWidget(parent),
      m_pitanje(pitanje)
{
    setupGui();
    
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    setMinimumSize(500, 500);
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
    m_lblPitanje->setText(m_pitanje->getPitanje());
    m_lblA = new QLabel(this);
    m_lblA->setText("<b>A</b><br />" + m_pitanje->getA());
    m_lblB = new QLabel(this);
    m_lblB->setText("<b>B</b><br />" + m_pitanje->getB());
    m_lblC = new QLabel(this);
    m_lblC->setText("<b>C</b><br />" + m_pitanje->getC());
    m_lblD = new QLabel(this);
    m_lblD->setText("<b>D</b><br />" + m_pitanje->getD());
    m_pbVreme = new QProgressBar(this);
    m_pbVreme->setOrientation(Qt::Vertical);
    
    /*
     * Lay down components
     */
    
    m_layoutMain->addWidget(m_lblPitanje, 0, 0, 1, 2);
    m_layoutMain->addWidget(m_lblA, 1, 0);
    m_layoutMain->addWidget(m_lblB, 1, 1);
    m_layoutMain->addWidget(m_lblC, 2, 0);
    m_layoutMain->addWidget(m_lblD, 2, 1);
    m_layoutMain->addWidget(m_pbVreme, 0, 3, 5, 1);
}

void WBrziPrsti::setVreme(int vreme)
{
    m_pbVreme->setValue(vreme);
}

void WBrziPrsti::setMaxVreme(int maxVreme)
{
    m_pbVreme->setMaximum(maxVreme);
}