#include <DBrziPrsti.h>

#include <QtGui>

#include <data/kviz.h>
#include <data/brziprsti.h>
#include <Database.h>

DBrziPrsti::DBrziPrsti(Kviz *kviz, QWidget *parent)
    : QTableWidget(parent),
      m_kviz(kviz)
{
    /*
     * TODO: Umesto naziv_kviza stavi stvarni naziv otvorenig kviza
     */
    setWindowTitle("Brzi prsti: naziv_kviza");
    
    Database db;
    if(db.open())
    {
        QList<BrziPrsti> pitanja = db.preuzmiBrzePrste(m_kviz->getId());
        for(BrziPrsti pitanje : pitanja)
        {
        }
    }
}

DBrziPrsti::~DBrziPrsti(void)
{
}