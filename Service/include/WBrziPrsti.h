#ifndef _W_BRZI_PRISTI_
#define _W_BRZI_PRISTI_

#include <QWidget>

#include <data/brziprsti.h>

class QLabel;
class QGridLayout;
class QProgressBar;

class WBrziPrsti : public QWidget
{
    Q_OBJECT
    
public:
    WBrziPrsti(BrziPrsti *pitanje, QWidget *parent = 0);
    virtual ~WBrziPrsti(void);
    
    void setMaxVreme(int maxVreme);
    void setVreme(int vreme);
    
private:
    void setupGui(void);
    
    BrziPrsti *m_pitanje;
    
    QLabel *m_lblPitanje;
    QLabel *m_lblA;
    QLabel *m_lblB;
    QLabel *m_lblC;
    QLabel *m_lblD;
    QProgressBar *m_pbVreme;
    
    QGridLayout *m_layoutMain;
};

#endif // _W_BRZI_PRISTI_