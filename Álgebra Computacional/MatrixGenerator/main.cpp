#include <QCoreApplication>

#include "common.h"
#include "create.h"

int main(int argc, char *argv[]) {
  QCoreApplication a(argc, argv);

  QTextStream out(stdout);

  QCommandLineParser parser;

  //parser.addPositionalArgument("command", "comando que sera executado");

  parser.addHelpOption();
  parser.addVersionOption();

  parser.parse(QCoreApplication::arguments());


  QStringList args = parser.positionalArguments();
  QString command = args.isEmpty() ? QString() : args.first();

  if(command=="create"){
    Create(parser,out);
  }else{
    out << "Comando precisa ser definido.\n";
    out << parser.helpText() << "\n";
    return CommandLineError;
  }

  return CommandLineOk;
}
