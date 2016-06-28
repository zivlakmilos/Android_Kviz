#include <DBrziPrsti.h>

#include <QtGui>

#include <data/kviz.h>
#include <data/brziprsti.h>
#include <data/MBrziPrsti.h>
#include <Database.h>
#include <DBrziPrstiEdit.h>

DBrziPrsti::DBrziPrsti(Kviz *kviz, QWidget *parent)
    : QTableView(parent),
      m_kviz(kviz)
{
    setWindowTitle("Brzi prsti: " + kviz->getNaziv());
    
    Database db;
    if(db.open())
    {
        QList<BrziPrsti> pitanja = db.preuzmiBrzePrste(m_kviz->getId());
        m_model = new MBrziPrsti(pitanja, this);
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

DBrziPrsti::~DBrziPrsti(void)
{
}

void DBrziPrsti::doubleClicked(QModelIndex index)
{
    QList<BrziPrsti> pitanja = m_model->getData();
    DBrziPrstiEdit brziPrstiEditor(&pitanja[index.row()], this);
    if(brziPrstiEditor.exec() == QDialog::Accepted)
    {
        snimiBrzePrste(brziPrstiEditor.getPitanje());
        m_model->dataChange(index.row(), brziPrstiEditor.getPitanje());
    }
}

void DBrziPrsti::novoPitanje(void)
{
    BrziPrsti pitanje;
    DBrziPrstiEdit brziPrstiEditor(&pitanje, this);
    if(brziPrstiEditor.exec() == QDialog::Accepted)
    {
        pitanje = snimiBrzePrste(brziPrstiEditor.getPitanje());
        m_model->addData(pitanje);
    }
}

BrziPrsti DBrziPrsti::snimiBrzePrste(BrziPrsti brziPrsti)
{
    Database db;
    if(db.open())
    {
        return db.snimiBrzePrste(brziPrsti, m_kviz->getId());
    }
}

void DBrziPrsti::closeEvent(QCloseEvent *event)
{
    emit close(true);
    event->accept();
}

void DBrziPrsti::addAction(QAction *action)
{
    m_popupKviz->addAction(action);
}

void DBrziPrsti::customMenuRequest(QPoint pos)
{
    QModelIndex index = indexAt(pos);
    m_popupKviz->popup(this->viewport()->mapToGlobal(pos));
}

void DBrziPrsti::obrisiPitanje(void)
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
            db.obrisiBrzePrste(m_model->getData()[index.row()].getId());
            m_model->removeData(index.row());
        }
    }
}