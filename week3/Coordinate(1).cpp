#include <iostream>
using namespace std;

class Coordinate
{
public:
    Coordinate()
    {
      x=0, y=0;
    }
  	Coordinate(int _x, int _y)
    {
      x=_x;
      y=_y;
    } 
  	Coordinate(Coordinate &c)
    {
        x = c.x;
        y = c.y;
    }
    int getX() {
        return x;
    }
    int getY() {
        return y;
    }
    void setX(int _x) {
        x=_x;
    }
    void setY(int _y) {
        y=_y;
    }
    void showCoordInfo() {
        cout<<"("<<x<<", "<<y<<")"<<endl;
    }
private:
  int x, y;
};
