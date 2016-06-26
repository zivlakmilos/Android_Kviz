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
        m_pitanja = db.preuzmiBrzePrste(m_kviz->getId());
    }
    
    m_model = new MBrziPrsti(m_pitanja, this);
    setModel(m_model);
    
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
    DBrziPrstiEdit brziPrstiEditor(&m_pitanja[index.row()], this);
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
    Database db;
    
    if(db.open())
    {
        db.obrisiBrzePrste(m_pitanja[index.row()].getId());
        m_pitanja.removeAt(index.row());
    }
}