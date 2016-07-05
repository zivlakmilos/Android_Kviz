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
}