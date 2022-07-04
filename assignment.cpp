#include <iostream>

using namespace std;

class Rectangle {
  private:
    float w;
    float h;
  public:
    void setH(float ht);
    void setW(float wd);
    float getH();
    float getW();
    float getArea();
};

void Rectangle::setH(float ht)
{
  h = ht;
}
void Rectangle::setW(float wd)
{
  w = wd;
}

float Rectangle::getH()
{
  return h;
}

float Rectangle::getW()
{
  return w;
}

float Rectangle::getArea()
{
  float area = w * h;
  return area ;
}

int main ()
{
  Rectangle p1, p2;
  p1.setH(15);
  p1.setW(70);

  p2.setH(20);
  p2.setW(30);

  if (p2.getArea() > p1.getArea())
  {
    cout << p2.getArea() << endl;
  }
  else
  {
    cout << p1.getArea() << endl;
  }
  return 0;
}


