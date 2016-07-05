#include <TcpClient.h>

#include <QTcpSocket>

TcpClient::TcpClient(int id, QObject* parent)
    : QThread(parent),
      m_id(id)
{
    m_socket = new QTcpSocket(this);
    if(!m_socket->setSocketDescriptor(id))
    {
        /*
         * TODO:
         *      Obrada greske
         */
        qDebug() << "Greska prilikoma otvaranja konecije sa klijentom";
        return;
    }
    
    connect(m_socket, SIGNAL(readyRead()),
            this, SLOT(readyRead()), Qt::DirectConnection);
    connect(m_socket, SIGNAL(disconnected()),
            this, SLOT(disconnected()));
}

TcpClient::~TcpClient(void)
{
}

void TcpClient::run(void)
{
    exec();
}

void TcpClient::readyRead(void)
{
    QByteArray data = m_socket->readAll();
    emit recivedData(m_id, data);
}

void TcpClient::disconnected(void)
{
    m_socket->deleteLater();
    exit(0);
}