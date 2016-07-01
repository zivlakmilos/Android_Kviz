#include <DAsocijacije.h>

#include <QtGui>

#include <data/kviz.h>
#include <data/koznazna.h>
#include <data/MAsocijacije.h>

#include <Database.h>
#include <DAsocijacijeEdit.h>

DAsocijacije::DAsocijacije(Kviz* kviz, QWidget* parent)
    : QTableView(parent),
      m_kviz(kviz)
{
    setWindowTitle(tr("Ko zna zna: %1").arg(m_kviz->getNaziv()));
    
    Database db;
    if(db.open())
    {
        QList<Asocijacije> pitanja = db.preuzmiAsocijacije(m_kviz->getId());
        m_model = new MAsocijacije(pitanja, this);
        setModel(m_model);
    } else
    {
        QMessageBox::warning(this, tr("Android Kviz"),
                             tr("Problem u komunikacijom sa bazom podataka"),
                             QMessageBox::Ok);
    }
    
    setSelectionBehavior(QAbstractItemView::SelectRows);
    setSelectionMode(QAbstractItemView::SingleSelection);
    
    connect(this, SIGNAL(doubleClicked(QModelIndex)),
            this, SLOT(doubleClicked(QModelIndex)));
    
    m_popupKviz = new QMenu(this);
    setContextMenuPolicy(Qt::CustomContextMenu);
    connect(this, SIGNAL(customContextMenuRequested(QPoint)),
            this, SLOT(customMenuRequest(QPoint)));
}

DAsocijacije::~DAsocijacije(void)
{
}

void DAsocijacije::closeEvent(QCloseEvent* event)
{
    emit close(true);
    event->accept();
}

void DAsocijacije::novoPitanje(void)
{
    /*
    Asocijacije pitanje;
    DAsocijacijeEdit asocijacijeEditor(&pitanje, this);
    if(asocijacijeEditor.exec() == QDialog::Accepted)
    {
        Asocijacije pitanje = asocijacijeEditor.getPitanje();
        pitanje = snimiAsocijacije(pitanje);
        m_model->addData(pitanje);
    }
    */
}

void DAsocijacije::obrisiPitanje(void)
{
    QModelIndex index = currentIndex();
    if(index.row() < 0)
        return;
    
    Database db;
    
    if(db.open())
    {
        if(QMessageBox::critical(this, tr("Android Kviz"),
                                 tr("Da li ste sigurni da zelite da obrisete pitanje?"),
                                 QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes)
        {
            db.obrisiAsocijacije(m_model->getData()[index.row()].getId());
            m_model->removeData(index.row());
        }
    }
}

Asocijacije DAsocijacije::snimiAsocijacije(Asocijacije koZnaZna)
{
    Database db;
    if(db.open())
    {
        return db.snimiAsocijacije(koZnaZna, m_kviz->getId());
    }
}

void DAsocijacije::addAction(QAction* action)
{
    m_popupKviz->addAction(action);
}

void DAsocijacije::doubleClicked(QModelIndex index)
{
    /*
    QList<Asocijacije> pitanja = m_model->getData();
    DAsocijacijeEdit asocijacijeEditor(&pitanja[index.row()], this);
    if(asocijacijeEditor.exec() == QDialog::Accepted)
    {
        Asocijacije pitanje = asocijacijeEditor.getPitanje();
        snimiAsocijacije(pitanje);
        m_model->dataChange(index.row(), pitanje);
    }
    */
}

void DAsocijacije::customMenuRequest(QPoint pos)
{
    QModelIndex index = indexAt(pos);
    m_popupKviz->popup(this->viewport()->mapToGlobal(pos));
}