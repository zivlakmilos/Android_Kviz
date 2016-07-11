#ifndef _D_VIDEO_BIM_
#define _D_VIDEO_BIM_

#include <QWidget>
#include <QTime>

class QSplitter;
class QVBoxLayout;
class QTimer;

class BrziPrsti;
class WQuizControl;
class WBrziPrsti;

class DVideoBim : public QWidget
{
    Q_OBJECT
    
public:
    DVideoBim(int kvizId, QWidget *parent = 0);
    ~DVideoBim(void);
    
private:
    void setupGui(void);
    
    int m_kvizId;
    QList<BrziPrsti> m_brziPrsti;
    QTime m_zadatoVreme;
    QTime m_trenutnoVreme;
    
    QVBoxLayout *m_layoutMain;
    QSplitter *m_splitter;
    WQuizControl *m_wQuizControl;
    WBrziPrsti *m_wBrziPrsti;
    
    QTimer *m_timer;
    
protected:
    virtual void closeEvent(QCloseEvent *event);
    
private slots:
    void sledecePitanje(int tip, QTime vreme);
    void rekordi(void);
    void pitanjeTimeout(void);
    
signals:
    void close(void);
};

#endif // _D_VIDEO_BIM_