#include <DQuizSelector.h>

#include <QtGui>

#include <Database.h>

DQuizSelector::DQuizSelector(QWidget* parent)
    : QWidget(parent)
{
    setupGui();
}

DQuizSelector::~DQuizSelector(void)
{
}

void DQuizSelector::setupGui(void)
{
    Database db;
    
    m_cbKvizovi = new QComboBox(this);
    QList<QString> kvizovi;
    for(int i = 0; i < kvizovi.length(); i++)
    {
        m_cbKvizovi->addItem(kvizovi.at(i));
    }
}