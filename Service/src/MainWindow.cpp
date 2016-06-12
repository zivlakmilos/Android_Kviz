#include <MainWindow.h>

#include <QtGui>

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    setupGui();
}

MainWindow::~MainWindow(void)
{
}

void MainWindow::setupGui(void)
{
    setWindowTitle(tr("Android Kviz"));
    
    m_mainLayout = new QVBoxLayout(this);
    setLayout(m_mainLayout);
    
    QFont font = this->font();
    font.setPointSize(25);
    
    m_btnAndroidProjectorMode = new QPushButton(this);
    m_btnAndroidProjectorMode->setText(tr("&Video bim"));
    m_btnAndroidProjectorMode->setFont(font);
    
    m_btnAndroidMode = new QPushButton(this);
    m_btnAndroidMode->setText(tr("&Samo Android"));
    m_btnAndroidMode->setFont(font);
    
    m_btnAdministration = new QPushButton(this);
    m_btnAdministration->setText(tr("&Administracija"));
    m_btnAdministration->setFont(font);
    
    m_mainLayout->addWidget(m_btnAndroidProjectorMode);
    m_mainLayout->addWidget(m_btnAndroidMode);
    m_mainLayout->addWidget(m_btnAdministration);
}