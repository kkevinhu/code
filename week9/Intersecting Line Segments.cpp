#include <iostream>
#include <cmath>
using namespace std;
//UVA 866
class Coordinate
{
public:
    double getX()
    {
        return x;
    }
    double getY()
    {
        return y;
    }
    void setx(double val)
    {
        x=val;
    }
    void sety(double val)
    {
        y=val;
    }
    Coordinate()
    {
        x=0;
        y=0;
    }
    Coordinate(const Coordinate &a)
    {
        x=a.x;
        y=a.y;
    }
    Coordinate(double X, double Y)
    {
        x=X;
        y=Y;
    }
    bool operator  ==(const Coordinate &obj)
    {
        if(obj.x==x && obj.y==y)
            return true;
        return false;
    }
    double x,y;
};

class Segment // using two Coordinate to represent a segment

{

public:

    Segment(Coordinate _a, Coordinate _b)

    {
        a=_a;//把傳進的值給segment裡的coordinate a
        b=_b;
    }
    Segment()
    {

    }
    void set(Coordinate &obj,Coordinate &obj1)
    {
        a.x=obj.x;
        a.y=obj.y;
        b.x=obj1.x;
        b.y=obj1.y;
    }
    double distance(Coordinate c1, Coordinate c2) {
        double dis;
        dis=sqrt(pow(c1.getX()-c2.getX(), 2)+pow(c1.getY()-c2.getY(), 2));
        return dis;
    }
    Coordinate *parallel(Coordinate myA, Coordinate myB, Coordinate sA, Coordinate sB) {
        Coordinate *newPoint=new Coordinate;
        if (distance(sA, myA)+distance(sB, myA)==distance(sA, sB))
            *newPoint=Coordinate(myA);
        else if (distance(sA, myB)+distance(sB, myB)==distance(sA, sB))
            *newPoint=Coordinate(myB);
        else if (distance(myA, sA)+distance(myB, sA)==distance(myA, myB))
            *newPoint=Coordinate(sA);
        else if (distance(myA, sB)+distance(myB, sB)==distance(myA, myB))
            *newPoint=Coordinate(sB);
        else
            return NULL;
        return newPoint;
    }

    Coordinate *getIntersection(Segment s)

    {
        Coordinate *point2=parallel(this->a, this->b, s.a, s.b);
        if (point2!=NULL)
            return point2;
        double m1,m2,pointx,pointy;//m1 第一條線的斜率，m2第二條線的斜率，pointx 相交的x點、pointy 相交的y點
        int judge=1 ;//判斷是否有無垂直的線
        if(a.getX()-b.getX()==0 || (s.a.getX()-s.b.getX()==0))//如果任何一條斜率不存在
        {
            if(a.getX()-b.getX()==0 && s.a.getX()-s.b.getX()!=0)//如果第一條斜率不存在且第二條存在
            {
                pointx=a.getX();//相交的點一定為當下X的值
                m2=(s.b.getY()-s.a.getY())/(s.b.getX()-s.a.getX());//算出另一條不為垂直線的斜率
                pointy=s.a.getY()+m2*(pointx-s.a.getX());//找出兩"線"的交點
                judge=2;//代表說交點已經找到了，等等不用執行之後的東西
            }
            else if(s.a.getX()-s.b.getX()==0 && a.getX()-b.getX()!=0)//同上
            {
                pointx=s.b.getX();
                m1=(a.getY()-b.getY())/(a.getX()-b.getX());
                pointy=a.getY()+m1*(pointx-a.getX());
                judge=2;
            }
            else//兩個都垂直
            {
                pointx=s.a.getX();
                if(pointx != b.getX())//如果兩線段平行
                {
                    return NULL;
                }
                if(a.getY()==s.a.getY())//其中一個y點相交
                {
                    Coordinate *c=new Coordinate;
                    *c=Coordinate(pointx,a.getY());
                    return c;//宣告新的coordinate 並回傳
                }
                if(a.getY()==s.b.getY())
                {
                    Coordinate *c=new Coordinate;
                    *c=Coordinate(pointx,a.getY());
                    return c;
                }
                if(b.getY()==s.a.getY())
                {
                    Coordinate *c=new Coordinate;
                    *c=Coordinate(pointx,b.getY());
                    return c;
                }
                if(b.getY()==s.b.getY())
                {
                    Coordinate *c=new Coordinate;
                    *c=Coordinate(pointx,b.getY());
                    return c;
                }
            }
        }
        if(judge==1)//如果沒有任何一個垂直的線
        {
            m1=(a.getY()-b.getY())/(a.getX()-b.getX());//求兩線的斜率
            m2=(s.a.getY()-s.b.getY())/(s.a.getX()-s.b.getX());
            if(a.getX()==s.a.getX() && a.getY()==s.a.getY() )//兩者有任何相交的點
            {
                Coordinate *c=new Coordinate;
                *c=Coordinate(a.getX(),a.getY());
                return c;
            }
            else if(a.getX()==s.b.getX() && a.getY()==s.b.getY() )
            {
                Coordinate *c=new Coordinate;
                *c=Coordinate(a.getX(),a.getY());
                return c;
            }
            else if(b.getX()==s.b.getX() && b.getY()==s.b.getY() )
            {
                Coordinate *c=new Coordinate;
                *c=Coordinate(b.getX(),b.getY());
                return c;
            }
            else if(b.getX()==s.a.getX() && b.getY()==s.a.getY() )
            {
                Coordinate *c=new Coordinate;
                *c=Coordinate(b.getX(),b.getY());
                return c;
            }
            else if(m1==m2)//兩者平行沒有點相交
            {
                return NULL;
            }
            pointx=(m1*(a.getX())-m2*(s.a.getX())-(a.getY())+(s.a.getY()))/(m1-m2);//m1(x-x1)=y-y1解聯立方程式
            pointy=(a.getY())+m1*pointx-m1*(a.getX());//得到其中一個點就求y的點
        }
        if(sqrt(pow(((a.getX())-pointx),2)+pow(((a.getY())-pointy),2))<=length() &&
                sqrt(pow(((b.getX())-pointx),2)+pow(((b.getY())-pointy),2))<=length() &&
                sqrt(pow(((s.a.getX())-pointx),2)+pow(((s.a.getY())-pointy),2))<=s.length() &&
                sqrt(pow(((s.b.getX())-pointx),2)+pow(((s.b.getY())-pointy),2))<=s.length() )//判斷4個點與交點的距離是否小於等於本身長度
        {
            Coordinate *c=new Coordinate;
            *c=Coordinate(pointx,pointy);
            return c;
        }
        else
        {
            return NULL;
        }

    }

    double length() // return the length of segment

    {
        double len;
        len=sqrt(pow((a.getX()-b.getX()),2)+pow((a.getY()-b.getY()),2));//(x1-x2)的平方+(y1-y2)的平方
        return len;
    }

    Coordinate getCoordinateA()
    {
        return a;
    }

    Coordinate getCoordinateB()
    {
        return b;
    }

    Coordinate a, b;

};

int main()
{   
    int n;
    cin>>n;
    while (n--) {
        int t, cnt=0;
        cin>>t;
        double x1, y1, x2, y2;
        Segment s[1000];
        for (int i=0; i<t; i++) {
            cin>>x1>>y1>>x2>>y2;
            Coordinate c1=Coordinate(x1, y1);
            Coordinate c2=Coordinate(x2, y2);
            s[i]=Segment(c1, c2);
        }
        for (int i=0; i<t; i++) {
            int pointOnLine=2;
            for (int j=0; j<t; j++) {
                if (i!=j) {
                    if (s[i].getIntersection(s[j])!=NULL) {
                        pointOnLine++;
                    }
                }
            }
            cnt+=(pointOnLine-1);
        }
        cout<<cnt<<endl;
        cout<<endl;
    }
}
