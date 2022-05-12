#include <bits/stdc++.h>
using namespace std;
//UVA 142
class Point
{
public:
    Point(){}
    Point(int _x, int _y) {
        x=_x;
        y=_y;
    }
    int getX() {
        return x;
    }
    int getY() {
        return y;
    }
    void set(int _x) {
        x=_x;
    }
    double distance(Point p1) {
        double dis;
        dis=sqrt(pow(p1.x-x, 2)+pow(p1.y-y, 2));
        return dis;
    }
private:
    int x, y;
};

class Region
{
public:
    Region(){}
    Region(Point _a, Point _b) {
        a=_a;
        b=_b;
    }
    bool inRegion(Point &c) {
        if ((c.getX()>=a.getX() && c.getY()>=a.getY()) && (c.getX()<=b.getX() && c.getY()<=b.getY()))
            return true;
        else if ((c.getX()>=b.getX() && c.getY()>=b.getY()) && (c.getX()<=a.getX() && c.getY()<=a.getY()))
            return true;
        return false;
    }
private:
    Point a, b;
};


int main() {
    char type;
    int idxPoint=0, idxRegion=0;
    Point point[100];
    Region region[100];
    while (cin>>type && type!='#') {
        if (type=='I') {
            int x, y;
            cin>>x>>y;
            point[idxPoint]=Point(x, y);
            idxPoint++;
        }
        else if (type=='R') {
            int p[4];
            for (int i=0; i<4; i++) cin>>p[i];
            Point p1=Point(p[0], p[1]);
            Point p2=Point(p[2], p[3]);
            region[idxRegion]=Region(p1, p2);
            idxRegion++;
        }
        else if (type=='M') {
            int x, y, flag=1;
            cin>>x>>y;
            Point click=Point(x, y);
            for (int i=idxRegion-1; i>=0; i--) {
                if (region[i].inRegion(click)) {
                    char a=i+'A';
                    flag=0;
                    printf("%c\n", a);
                    break;
                }
            }
            if (flag) {
                double min=10000, dis[1000];
                bool iconInRegion=0;
                for (int i=0; i<idxPoint; i++) {
                    for (int j=0; j<idxRegion; j++) {
                        if (region[j].inRegion(point[i])) {
                            point[i].set(point[i].getX()+10000);
                            point[i].set(point[i].getY()+10000);
                        }
                    }
                }
                for (int i=0; i<idxPoint; i++) {
                    dis[i]=point[i].distance(click);
                    if (min>dis[i])
                        min=dis[i];
                }
                for (int i=0; i<idxPoint; i++) {
                    if (dis[i]==min) {
                        for (int j=0; j<idxRegion; j++) {
                            iconInRegion=0;
                            if (region[j].inRegion(point[i])) {
                                iconInRegion=1;
                            }
                        }
                        if (!iconInRegion)
                            cout << setw(3) << i+1;
                    }
                }
                cout<<endl;
            }
        }
    }
}
