#include "globaloptions.h"

static GlobalOptions *instance_ = nullptr;

GlobalOptions *GlobalOptions::Instance() {
  if (instance_ == nullptr) {
    instance_ = new GlobalOptions();
  }

  return instance_;
}

GlobalOptions::GlobalOptions():
  shape(Sphere)
{
}
