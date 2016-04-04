#include "create.h"

CommandLineParseResult Create(QCommandLineParser &parser, QTextStream &out)
{
  out << "Executando comando Create\n";
  // Parameters
  int row = 0;
  int col = 0;
  int part_row = 0;
  int part_col = 0;
  QString name = "A";

  parser.addOptions({{{"n", "name"}, "nome da matriz", "nome"},
                     {{"r", "row"}, "numero de linhas da matriz", "n de linhas"},
                     {{"c", "column"}, "numero de colunas da matriz", "n de colunas"},
                     {{"x", "part_row"}, "numero de linhas da particao da matriz", "n de linhas"},
                     {{"y", "part_column"}, "numero de colunas da particao da matriz", "n de colunas"}});

  parser.process(*qApp);

  // Check necessary parameters
  if (!parser.isSet("r") || !parser.isSet("c")) {
    out << "Parametros 'r' e 'c' precisam ser definidos."
        << "\n";
    out << parser.helpText() << "\n";
    return CommandLineError;
  }

  // Print Help
  if (parser.isSet("h")) {
    out << parser.helpText();
    return CommandLineHelpRequested;
  }
  bool ok = true;
  if(parser.isSet("n")){
    name = parser.value("n");
  }

  row = parser.value("r").toInt(&ok);
  if (!ok) {
    out << "parametro 'r' precisa ser um inteiro." << parser.value("r") << "\n";
    out << parser.helpText() << "\n";
    return CommandLineError;
  }
  col = parser.value("c").toInt(&ok);
  if (!ok) {
    out << "parametro 'c' precisa ser um inteiro." << parser.value("c") << "\n";
    out << parser.helpText() << "\n";
    return CommandLineError;
  }
  if (parser.isSet("x")) {
    part_row = parser.value("x").toInt(&ok);
    if (!ok) {
      out << "parametro 'x' precisa ser um inteiro." << parser.value("x") << "\n";
      out << parser.helpText() << "\n";
      return CommandLineError;
    }
  }
  if (parser.isSet("y")) {
    part_row = parser.value("y").toInt(&ok);
    if (!ok) {
      out << "parametro 'y' precisa ser um inteiro." << parser.value("y") << "\n";
      out << parser.helpText() << "\n";
      return CommandLineError;
    }
  }
  out << "Matriz criada\n";
}
