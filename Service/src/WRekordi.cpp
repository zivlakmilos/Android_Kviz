#include <WRekordi.h>

#include <QtGui>

#include <data/MRekordi.h>

WRekordi::WRekordi(QList<Takmicar> data, QWidget *parent)
    : QWidget(parent)
{
    m_model = new MRekordi(data, this);
    m_twRekordi = new QTableView(this);
    m_twRekordi->setModel(m_model);
    
    setupGui();
}

WRekordi::~WRekordi(void)
{
}

void WRekordi::setupGui(void)
{
    QVBoxLayout *layoutMain = new QVBoxLayout(this);
    setLayout(layoutMain);
    
    layoutMain->addWidget(m_twRekordi);
}