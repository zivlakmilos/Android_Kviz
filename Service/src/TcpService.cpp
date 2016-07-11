#include <TcpService.h>

#include <QTcpServer>
#include <QTcpSocket>

#include <TcpClient.h>

TcpService::TcpService(QObject *parent)
    : QTcpServer(parent)
{
}

TcpService::~TcpService(void)
{
}

bool TcpService::start(void)
{
    return listen(QHostAddress::Any, Port);
}

void TcpService::stop(void)
{
}

void TcpService::incomingConnection(int socketDescriptor)
{
    TcpClient *tmp = new TcpClient(socketDescriptor, this);
    tmp->start();
    m_client.append(tmp);
    connect(tmp, SIGNAL(recivedData(int, QByteArray)),
            this, SLOT(reciveData(int, QByteArray)));
    emit clientConnected(socketDescriptor);
}

void TcpService::send(QString data)
{
    int i;
    QByteArray tmpData = data.toAscii();
    for(i = 0; i < m_client.size(); i++)
    {
        if(m_client.at(i) && m_client.at(i)->isRunning())
        {
            m_client.at(i)->send(tmpData);
        } else
        {
            m_client.removeAt(i);
        }
    }
}

void TcpService::reciveData(int id, QByteArray data)
{
    QString tmpData = QString::fromAscii(data);
    emit recivedData(id, data);
}