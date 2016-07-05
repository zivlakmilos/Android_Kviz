#ifndef _TCP_CLIENT_H_
#define _TCP_CLIENT_H_

#include <QThread>

class QTcpSocket;

class TcpClient : public QThread
{
    Q_OBJECT
    
public:
    TcpClient(int id, QObject *parent = 0);
    virtual ~TcpClient(void);
    
    void run(void);
    
private:
    QTcpSocket *m_socket;
    int m_id;
    
private slots:
    void readyRead(void);
    void disconnected(void);
    
signals:
    void recivedData(int id, QByteArray data);
};

#endif // _TCP_CLIENT_H_