#include "mainwindow.h"
#include "application.h"
#include "globaloptions.h"

int main(int argc, char *argv[]) {
  GlobalOptions::Instance();
  Application a(argc, argv);
  MainWindow w;
  w.show();

  return a.exec();
}
