#include <DBrziPrsti.h>

#include <QtGui>

#include <data/kviz.h>
#include <data/brziprsti.h>
#include <data/MBrziPrsti.h>
#include <Database.h>

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
}

DBrziPrsti::~DBrziPrsti(void)
{
}