#ifndef _D_BRZI_PRSTI_H_
#define _D_BRZI_PRSTI_H_

#include <QTableView>

class Kviz;
class BrziPrsti;
class MBrziPrsti;

class DBrziPrsti : public QTableView
{
    Q_OBJECT
    
public:
    DBrziPrsti(Kviz *kviz, QWidget *parent = 0);
    virtual ~DBrziPrsti(void);
    
private:
    Kviz *m_kviz;
    QList<BrziPrsti> m_pitanja;
    MBrziPrsti *m_model;
};

#endif // _D_BRZI_PRSTI_H_