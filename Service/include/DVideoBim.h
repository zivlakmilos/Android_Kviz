#ifndef _D_VIDEO_BIM_
#define _D_VIDEO_BIM_

#include <QWidget>
#include <QTime>
#include <QMap>

#include <data/takmicar.h>

class QSplitter;
class QVBoxLayout;
class QTimer;

class BrziPrsti;
class WQuizControl;
class WBrziPrsti;
class TcpService;
class WRekordi;

class DVideoBim : public QWidget
{
    Q_OBJECT
    
public:
    DVideoBim(int kvizId, QWidget *parent = 0);
    ~DVideoBim(void);
    
    enum { S_IDLE = 0,
           S_Prijava,
           S_BrziPrsti,
           S_KoZnaZna,
           S_Asocijacije };
    
private:
    void setupGui(void);
    
    int m_kvizId;
    QList<BrziPrsti> m_brziPrsti;
    QTime m_zadatoVreme;
    QTime m_trenutnoVreme;
    int m_status;
    QMap<int, Takmicar> m_rekordi;
    int m_bodovi;
    int m_rbPitanja;
    
    TcpService *m_service;
    
    QVBoxLayout *m_layoutMain;
    QSplitter *m_splitter;
    WQuizControl *m_wQuizControl;
    WBrziPrsti *m_wBrziPrsti;
    WRekordi *m_wRekordi;
    
    QTimer *m_timer;
    
protected:
    virtual void closeEvent(QCloseEvent *event);
    
private slots:
    void sledecePitanje(int tip, QTime vreme);
    void rekordi(void);
    void pitanjeTimeout(void);
    void recivedData(int id, QString data);
    
signals:
    void close(void);
};

#endif // _D_VIDEO_BIM_