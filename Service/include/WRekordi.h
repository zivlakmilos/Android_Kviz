#ifndef _W_REKORDI_H_
#define _W_REKORDI_H_

#include <QWidget>

#include <data/takmicar.h>

class QTableView;
class MRekordi;

class WRekordi : public QWidget
{
public:
    WRekordi(QList<Takmicar> data, QWidget *parent = 0);
    virtual ~WRekordi(void);
    
private:
    void setupGui(void);
    
    QTableView *m_twRekordi;
    MRekordi *m_model;
};

#endif // _W_REKORDI_H_