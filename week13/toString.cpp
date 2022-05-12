#include <iostream>
#include <sstream>
using namespace std;

class Point
{
public:
int x, y;
};

class Convert
{
public:
  static string toString(int n)
  {
      stringstream s1;
      s1<<n;
      string s=s1.str();
      return s;
  }
  static string toString(char c)
  {
      stringstream s2;
      s2<<c;
      string s=s2.str();
      return s;
  }
  static string toString(double d)
  {
      stringstream s3;
      s3<<d;
      string s=s3.str();
      return s;
  }
  static string toString(Point p)
  {
      stringstream s4, s5;
      s4<<p.x;
      s5<<p.y;
      string s="("+s4.str()+", "+s5.str()+")";
      return s;
  }
};
