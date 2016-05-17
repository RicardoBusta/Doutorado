#include "mainwindow.h"
#include <QApplication>

#include <QDateTime>

void myMessageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg) {
  QByteArray localMsg = msg.toLocal8Bit();
  switch (type) {
    case QtDebugMsg:
      fprintf(stderr, "(%s:%u) %s\n", context.file, context.line, localMsg.constData());
      break;
    case QtInfoMsg:
      fprintf(stderr, "Info: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
      break;
    case QtWarningMsg:
      fprintf(stderr, "Warning: (%s:%u) %s\n", context.file, context.line, localMsg.constData());
      break;
    case QtCriticalMsg:
      fprintf(stderr, "Critical: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
      break;
    case QtFatalMsg:
      fprintf(stderr, "Fatal: %s (%s:%u, %s)\n", localMsg.constData(), context.file, context.line, context.function);
      abort();
  }
}

int main(int argc, char *argv[])
{
    qInstallMessageHandler(myMessageOutput);
    qsrand(QDateTime::currentMSecsSinceEpoch());
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
