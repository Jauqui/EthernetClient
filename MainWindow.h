#ifndef MAINWINDOW_H
  #define MAINWINDOW_H

  #include <QMainWindow>

  #include "ethernetClient.h"
  #include "ui_MainWindow.h"


  class MainWindow : public QMainWindow
  {
    Q_OBJECT


    public:
      explicit MainWindow(QWidget* parent = 0);


    signals:


    public slots:
      void OnMessageFromClient(QString message);

      void OnSendMessage();

      void OnServerChanged(QString server);
      void OnPortChanged(int port);


    private:
      Client* m_Client;

    #ifdef __ANDROID__
      Ui_MainWindow ui;
    //#elif _WIN32

    #endif

  };

#endif // MAINWINDOW_H
