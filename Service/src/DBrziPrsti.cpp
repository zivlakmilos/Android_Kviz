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
        m_model->dataChanged(index.row(), brziPrstiEditor.getPitanje());
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