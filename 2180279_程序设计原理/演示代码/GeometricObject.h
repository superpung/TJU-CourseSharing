#ifndef GEOMETRICOBJECT_H
#define GEOMETRICOBJECT_H
#include <string>
using namespace std;

class GeometricObject
{
public:
  GeometricObject();
  GeometricObject(string color, bool filled);
  string getColor();
  void setColor(string color);
  bool isFilled();
  void setFilled(bool filled);
  string toString();

private:
  string color;
  bool filled;
}; // Must place semicolon here

#endif
