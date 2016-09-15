#ifndef GLOBALOPTIONS_H
#define GLOBALOPTIONS_H

class GlobalOptions
{
public:
  static GlobalOptions * Instance();

  enum Shape{
    Sphere,
    Cylinder
  };

  enum Shape shape;
private:
  GlobalOptions();
};

#endif // GLOBALOPTIONS_H
