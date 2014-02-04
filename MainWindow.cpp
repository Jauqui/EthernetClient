#include "MainWindow.h"


MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  m_Client(0)
{
  ui.setupUi(this);

  //connect(ui.connectPushButton, SIGNAL(clicked()), this, SLOT(OnConnectToServer()));

  QString ip   = ui.addressLineEdit->text();
  int     port = ui.portSpinBox->value();

  m_Client = new Client(ip, port);
  connect(m_Client, SIGNAL(signalIncomingMessage(QString)), this, SLOT(OnMessageFromClient(QString)));

  connect(ui.addressLineEdit, SIGNAL(textChanged(QString)), this, SLOT(OnServerChanged(QString)));
  connect(ui.portSpinBox, SIGNAL(valueChanged(int)), this, SLOT(OnPortChanged(int)));
  connect(ui.messagePushButton, SIGNAL(clicked()), this, SLOT(OnSendMessage()));
}


void MainWindow::OnServerChanged(QString server)
{
  m_Client->SetServer(server);
}


void MainWindow::OnPortChanged(int port)
{
  m_Client->SetPort(port);
}


void MainWindow::OnMessageFromClient(QString message)
{
  ui.messageLabel->setText(message);
}


void MainWindow::OnSendMessage()
{
  QString message = ui.messageLineEdit->text();

  m_Client->SendMessage(message);
}
