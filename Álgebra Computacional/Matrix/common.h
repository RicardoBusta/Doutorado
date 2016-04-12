#ifndef COMMON_H
#define COMMON_H

#include <QCommandLineParser>
#include <QDebug>
#include <QTextStream>

enum CommandLineParseResult {
  CommandLineOk = 0,
  CommandLineError = -1,
  CommandLineHelpRequested = 1
};

#endif // COMMON_H

