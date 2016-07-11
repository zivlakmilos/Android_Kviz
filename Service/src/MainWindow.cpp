#include <MainWindow.h>

#include <QtGui>

#include <Database.h>
#include <AdministrationWindow.h>
#include <DVideoBim.h>

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
    Database db;
    if(!db.open())
    {
        return;
    }
    
    QList<Kviz> kvizovi = db.preuzmiListuKvizova();
    QStringList items;
    bool ok;
    for(Kviz kviz : kvizovi)
    {
        items.append(kviz.getNaziv());
    }
    QString item = QInputDialog::getItem(this, tr("Android Kviz"),
                                         tr("Kviz:"), items, 0, false, &ok);
    if(!ok || items.isEmpty())
    {
        return;
    }
    int kvizId = 0;
    for(Kviz kviz : kvizovi)
    {
        if(kviz.getNaziv() == kviz.getNaziv())
        {
            kvizId = kviz.getId();
            break;
        }
    }
    
    DVideoBim *videoBim = new DVideoBim(kvizId, this);
    videoBim->setWindowFlags(Qt::Window);
    videoBim->show();
    connect(videoBim, SIGNAL(close()), this, SLOT(show()));
    hide();
}

void MainWindow::btnAndroidModeClick(void)
{
}