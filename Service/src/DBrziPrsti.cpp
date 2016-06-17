#include <DBrziPrsti.h>

#include <QtGui>

#include <data/brziprsti.h>
#include <Database.h>

DBrziPrsti::DBrziPrsti(QWidget *parent)
    : QTableWidget(parent)
{
    /*
     * TODO: Umesto naziv_kviza stavi stvarni naziv otvorenig kviza
     */
    setWindowTitle("Brzi prsti: naziv_kviza");
    
    Database db;
    if(db.open())
    {
        QList<BrziPrsti> pitanja = db.preuzmiBrzePrste(1);
        for(BrziPrsti pitanje : pitanja)
        {
        }
    }
}

DBrziPrsti::~DBrziPrsti(void)
{
}