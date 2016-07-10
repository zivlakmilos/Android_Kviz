#ifndef _W_BRZI_PRISTI_
#define _W_BRZI_PRISTI_

#include <QWidget>

class QLabel;
class QGridLayout;

class WBrziPrsti : public QWidget
{
public:
    WBrziPrsti(QWidget *parent = 0);
    virtual ~WBrziPrsti(void);
    
private:
    void setupGui(void);
    
    QLabel *m_lblPitanje;
    QLabel *m_lblA;
    QLabel *m_lblB;
    QLabel *m_lblC;
    QLabel *m_lblD;
    
    QGridLayout *m_layoutMain;
};

#endif // _W_BRZI_PRISTI_