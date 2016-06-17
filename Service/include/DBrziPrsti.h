#ifndef _D_BRZI_PRSTI_H_
#define _D_BRZI_PRSTI_H_

#include <QTableWidget>

class Kviz;

class DBrziPrsti : public QTableWidget
{
    Q_OBJECT
    
public:
    DBrziPrsti(Kviz *kviz, QWidget *parent = 0);
    virtual ~DBrziPrsti(void);
    
private:
    Kviz *m_kviz;
};

#endif // _D_BRZI_PRSTI_H_