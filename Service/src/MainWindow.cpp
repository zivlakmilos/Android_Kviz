#include <MainWindow.h>

#include <QtGui>

#include <AdministrationWindow.h>
#include <TcpService.h>

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle(tr("Android Kviz"));
    
    setupGui();
}

MainWindow::~MainWindow(void)
{
}

void MainWindow::setupGui(void)
{
    m_mainLayout = new QVBoxLayout(this);
    setLayout(m_mainLayout);
    
    QFont font = this->font();
    font.setPointSize(25);
    
    m_btnAndroidProjectorMode = new QPushButton(this);
    m_btnAndroidProjectorMode->setText(tr("&Video bim"));
    m_btnAndroidProjectorMode->setFont(font);
    connect(m_btnAndroidProjectorMode, SIGNAL(clicked()),
            this, SLOT(btnAndroidProjectorModeClick()));
    
    m_btnAndroidMode = new QPushButton(this);
    m_btnAndroidMode->setText(tr("&Samo Android"));
    m_btnAndroidMode->setFont(font);
    connect(m_btnAndroidMode, SIGNAL(clicked()),
            this, SLOT(btnAndroidModeClick()));
    
    m_btnAdministration = new QPushButton(this);
    m_btnAdministration->setText(tr("&Administracija"));
    m_btnAdministration->setFont(font);
    connect(m_btnAdministration, SIGNAL(clicked()),
            this, SLOT(btnAdministrationClick()));
    
    m_mainLayout->addWidget(m_btnAndroidProjectorMode);
    m_mainLayout->addWidget(m_btnAndroidMode);
    m_mainLayout->addWidget(m_btnAdministration);
}

void MainWindow::btnAdministrationClick(void)
{
    AdministrationWindow *administrationWindow = new AdministrationWindow(this);
    administrationWindow->show();
    connect(administrationWindow, SIGNAL(close()), this, SLOT(show()));
    hide();
}

void MainWindow::btnAndroidProjectorModeClick(void)
{
    TcpService *test = new TcpService(this);
    test->start();
}

void MainWindow::btnAndroidModeClick(void)
{
}