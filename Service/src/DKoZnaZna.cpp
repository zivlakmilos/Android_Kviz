#include <DKoZnaZna.h>

#include <QtGui>

#include <data/kviz.h>
#include <data/koznazna.h>
#include <data/MKoZnaZna.h>

#include <Database.h>
#include <DKoZnaZnaEdit.h>

DKoZnaZna::DKoZnaZna(Kviz* kviz, QWidget* parent)
    : QTableView(parent),
      m_kviz(kviz)
{
    setWindowTitle(tr("Ko zna zna: %1").arg(m_kviz->getNaziv()));
    
    Database db;
    if(db.open())
    {
        QList<KoZnaZna> pitanja = db.preuzmiKoZnaZna(m_kviz->getId());
        m_model = new MKoZnaZna(pitanja, this);
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

DKoZnaZna::~DKoZnaZna(void)
{
}

void DKoZnaZna::closeEvent(QCloseEvent* event)
{
    emit close(true);
    event->accept();
}

void DKoZnaZna::novoPitanje(void)
{
    KoZnaZna pitanje;
    DKoZnaZnaEdit koZnaZnaEditor(&pitanje, this);
    if(koZnaZnaEditor.exec() == QDialog::Accepted)
    {
        KoZnaZna pitanje = koZnaZnaEditor.getPitanje();
        pitanje = snimiKoZnaZna(pitanje);
        m_model->addData(pitanje);
    }
}

void DKoZnaZna::obrisiPitanje(void)
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
            db.obrisiKoZnaZna(m_model->getData()[index.row()].getId());
            m_model->removeData(index.row());
        }
    }
}

KoZnaZna DKoZnaZna::snimiKoZnaZna(KoZnaZna koZnaZna)
{
    Database db;
    if(db.open())
    {
        return db.snimiKoZnaZna(koZnaZna, m_kviz->getId());
    }
}

void DKoZnaZna::addAction(QAction* action)
{
    m_popupKviz->addAction(action);
}

void DKoZnaZna::doubleClicked(QModelIndex index)
{
    QList<KoZnaZna> pitanja = m_model->getData();
    DKoZnaZnaEdit koZnaZnaEditor(&pitanja[index.row()], this);
    if(koZnaZnaEditor.exec() == QDialog::Accepted)
    {
        KoZnaZna pitanje = koZnaZnaEditor.getPitanje();
        snimiKoZnaZna(pitanje);
        m_model->dataChange(index.row(), pitanje);
    }
}

void DKoZnaZna::customMenuRequest(QPoint pos)
{
    QModelIndex index = indexAt(pos);
    m_popupKviz->popup(this->viewport()->mapToGlobal(pos));
}