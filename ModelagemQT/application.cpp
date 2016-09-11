#include "application.h"

Application::Application(int argc, char *argv[])
    : QApplication(argc, argv) {
  qputenv("QT_MESSAGE_PATTERN","(%{file}:%{line}) %{message}");
}
