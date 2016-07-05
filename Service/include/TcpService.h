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
    
    enum { Port = 5001 };
    
private:
    QList<TcpClient *> m_client;
    
protected:
    void incomingConnection(int socketDescriptor);
};

#endif // _TCP_SERVICE_H_