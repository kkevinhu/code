#include <bits/stdc++.h>
using namespace std;

class Shape
{
public:
  virtual double getArea()=0;
};
class Circle : public Shape
{
public:
    Circle(double _r) {
        r=_r;
    }
    double getArea() {
        double area=3.14*r*r;
        return area;
    }
private:
    double r;
};
class Rectangle : public Shape
{
public:
    Rectangle(double _w, double _h) {
        w=_w;
        h=_h;
    }
    double getArea() {
        double area;
        area=w*h;
        return area;
    }

private:
    double w, h;
};

int main() {
  int a, b, c;
  std::cin >> a >> b >>c;
  Circle c1(a);
  Rectangle r(b, c);
  std::cout<<c1.getArea()<<std::endl;
  std::cout<<r.getArea()<<std::endl;
  return 0;
}
