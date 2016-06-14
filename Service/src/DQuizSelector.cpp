#include <DQuizSelector.h>

#include <QtGui>

#include <Database.h>

DQuizSelector::DQuizSelector(QWidget* parent)
    : QDialog(parent)
{
    setWindowTitle("Android Kviz");
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
    
    m_lblIzborKviza = new QLabel(this);
    m_lblIzborKviza->setText(tr("Izbor kviza:"));
    
    m_btnOk = new QPushButton(this);
    m_btnOk->setText(tr("&Ok"));
    
    m_btnCancel = new QPushButton(this);
    m_btnCancel->setText(tr("&Cancel"));
    
    m_buttonsLayout = new QHBoxLayout();
    m_buttonsLayout->addWidget(m_btnOk);
    m_buttonsLayout->addWidget(m_btnCancel);
    
    m_mainLayout = new QVBoxLayout(this);
    m_mainLayout->addWidget(m_lblIzborKviza);
    m_mainLayout->addWidget(m_cbKvizovi);
    m_mainLayout->addLayout(m_buttonsLayout);
    
    setLayout(m_mainLayout);
}