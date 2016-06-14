#include <DQuizSelector.h>

#include <QtGui>

#include <data/kviz.h>
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
    if(db.open())
    {
        m_kvizovi = db.preuzmiListuKvizova();
        for(Kviz kviz : m_kvizovi)
        {
            m_cbKvizovi->addItem(kviz.getNaziv());
        }
        m_cbKvizovi->addItem(tr("Dodaj novi kviz ..."));
    } else
    {
        QMessageBox::warning(this, tr("Android Kviz"),
                             tr("Nema konekcije na bazu podataka!"),
                             QMessageBox::Ok);
    }
    
    m_lblIzborKviza = new QLabel(this);
    m_lblIzborKviza->setText(tr("Izbor kviza:"));
    
    m_btnOk = new QPushButton(this);
    m_btnOk->setText(tr("&Ok"));
    connect(m_btnOk, SIGNAL(clicked()), this, SLOT(accept()));
    
    m_btnCancel = new QPushButton(this);
    m_btnCancel->setText(tr("&Cancel"));
    connect(m_btnCancel, SIGNAL(clicked()), this, SLOT(reject()));
    
    m_buttonsLayout = new QHBoxLayout();
    m_buttonsLayout->addWidget(m_btnOk);
    m_buttonsLayout->addWidget(m_btnCancel);
    
    m_mainLayout = new QVBoxLayout(this);
    m_mainLayout->addWidget(m_lblIzborKviza);
    m_mainLayout->addWidget(m_cbKvizovi);
    m_mainLayout->addLayout(m_buttonsLayout);
    
    setLayout(m_mainLayout);
}

QString DQuizSelector::getSelectedQuizId(void)
{
    m_kvizovi.at(m_cbKvizovi->currentIndex());
}