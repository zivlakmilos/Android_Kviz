#ifndef _TCP_SERVICE_H_
#define _TCP_SERVICE_H_

#include <QTcpServer>

class TcpClient;

class TcpService : public QTcpServer
{
    Q_OBJECT
    
public:
    TcpService(QObject *parent = 0);
    virtual ~TcpService(void);
    
    bool start(void);
    void stop(void);
    void send(QString data);
    
    enum { Port = 5001 };
    
private:
    QList<TcpClient *> m_client;
    
protected:
    void incomingConnection(int socketDescriptor);
    
private slots:
    void reciveData(int id, QByteArray data);
    
signals:
    void clientConnected(int id);
    void recivedData(int id, QString data);
};

#endif // _TCP_SERVICE_H_