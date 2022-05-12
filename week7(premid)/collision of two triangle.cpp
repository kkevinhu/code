#include<iostream>
#include <cmath>

using namespace std;

class Point
{
public:
    Point()
    {
        x = 0;
        y = 0;
    }
    Point(double _x, double _y)
    {
        x = _x;
        y = _y;
    }
    double x, y;
};

class Triangle
{
public:
    Triangle(Point a, Point b, Point c)
    {
        point[0] = a;
        point[1] = b;
        point[2] = c;
    }
    double getLength(const Point &p1, const Point &p2) {
        double len;
        len=sqrt(pow(p1.x-p2.x, 2)+pow(p1.y-p2.y, 2));
        return len;
    }
    double getArea(const Point &p, const Point &p1, const Point &p2) {
        double area;
        double a=getLength(p, p1), b=getLength(p1, p2), c=getLength(p, p2);
        double s=(a+b+c)/2;
        area=sqrt(s*(s-a)*(s-b)*(s-c));
        return area;
    }
    bool operator*(const Triangle &t) {
        double area=0;
        double myArea=getArea(point[0], point[1], point[2]);
        double tArea=getArea(t.point[0], t.point[1], t.point[2]);
        for (int i=0; i<3; i++) {
            area=0;
            area+=getArea(t.point[i], point[0], point[1]);
            area+=getArea(t.point[i], point[1], point[2]);
            area+=getArea(t.point[i], point[0], point[2]);
            if (area==myArea) {
                return true;
            }
        }
        for (int i=0; i<3; i++) {
            area=0;
            area+=getArea(point[i], t.point[0], t.point[1]);
            area+=getArea(point[i], t.point[1], t.point[2]);
            area+=getArea(point[i], t.point[0], t.point[2]);
            if (area==tArea) {
                return  true;
            }
        }
        return false;
    }
private:
    Point point[3];
};

int main()
{
    double x1, y1, x2, y2, x3, y3;
    std::cin>>x1>>y1>>x2>>y2>>x3>>y3;
    Point a(x1, y1), b(x2, y2), c(x3, y3);
    std::cin>>x1>>y1>>x2>>y2>>x3>>y3;
    Point a2(x1, y1), b2(x2, y2), c2(x3, y3);
    Triangle t1(a, b, c), t2(a2, b2, c2);
    std::cout<<t1 * t2<<std::endl;
}
