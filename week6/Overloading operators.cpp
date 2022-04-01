using namespace std;
class Coordinate
{
public:
    Coordinate() {
        x=0;
        y=0;
    }
    Coordinate(const Coordinate &p) {
        x=p.x;
        y=p.y;
    }
    Coordinate(int _x, int _y) {
        x=_x;
        y=_y;
    }
    int operator>(const Coordinate &p) {
        return (this->x>p.x & this->y>p.y);
    }
    int operator<(const Coordinate &p) {
        return (this->x<p.x & this->y<p.y);
    }
    Coordinate operator+(const Coordinate &p) {
        Coordinate *point=new Coordinate(this->x+p.x, this->y+p.y);
        return *point;
    }
    Coordinate operator-(const Coordinate &p) {
        Coordinate *point=new Coordinate(this->x-p.x, this->y-p.y);
        return *point;
    }
    Coordinate operator=(const Coordinate &p) {
        this->x=p.x;
        this->y=p.y;
        return *this;
    }
    int getX() {
        return x;
    }
    int getY() {
        return y;
    }
    void setX(int val) {
        x=val;
    }
    void setY(int val) {
        y=val;
    }
    void showCoordInfo() {
        cout<<"("<<x<<", "<<y<<")"<<endl;
    }
private:
    int x, y;
};
