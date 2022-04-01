#include <iostream>
#include <cmath>
using namespace std;

class Point
{
public:
	float x, y;
};

class Segment
{
public:
	Segment()
	{
	}
	Segment(Point _a, Point _b)
	{
		a = _a;
		b = _b;
	}
	Point getPointA() const
	{
		return a;
	}
	Point getPointB() const
	{
		return b;
	}
	void setPoint(Point _a, Point _b) //const
	{          
		a = _a;
		b = _b;
	}
	float getLength() const
	{
		return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
	}
	float getDistance(const Point &p) const //點到直線的距離-比例
    {
        float ptoa=sqrt(pow(p.x-a.x, 2)+pow(p.y-a.y, 2));
        float ptob=sqrt(pow(p.x-b.x, 2)+pow(p.y-b.y, 2));
        float atob=sqrt(pow(a.x-b.x, 2)+pow(a.y-b.y, 2));
        float atoc=(ptoa*atob)/(ptoa+ptob);
        float dis=sqrt(ptoa*ptoa-atoc*atoc);
        return dis;
    }
private:
	Point a, b;
};

class Triangle
public:
	Triangle(Segment s1, Segment s2, Segment s3)
	{
		seg1 = s1;
		seg2 = s2;
		seg3 = s3;
	}
{
	static bool isTriangle(Segment s1, Segment s2, Segment s3) //to determine if three segment can construct a triangle. they must overlap at the endpoint to construct a triangle.
    {
        float s1DelX=s1.getPointA().x-s1.getPointB().x;
        float s1DelY=s1.getPointA().y-s1.getPointB().y;
        float s2DelX=s2.getPointA().x-s2.getPointB().x;
        float s2DelY=s2.getPointA().y-s2.getPointB().y;
        if (s1DelY*s2DelX==s1DelX*s2DelY) return false;
        Point s1to2, s2to3, s1to3;
        if (s1.getPointA().x==s2.getPointA().x && s1.getPointA().y==s2.getPointA().y) {
            s1to2.x=s1.getPointA().x;
            s1to2.y=s1.getPointA().y;
        }
        else if (s1.getPointA().x==s2.getPointB().x && s1.getPointA().y==s2.getPointB().y) {
            s1to2.x=s1.getPointA().x;
            s1to2.y=s1.getPointA().y;
        }
        else if (s1.getPointB().x==s2.getPointA().x && s1.getPointB().y==s2.getPointA().y) {
            s1to2.x=s1.getPointB().x;
            s1to2.y=s1.getPointB().y;
        }
        else if (s1.getPointB().x==s2.getPointB().x && s1.getPointB().y==s2.getPointB().y) {
            s1to2.x=s1.getPointB().x;
            s1to2.y=s1.getPointB().y;
        }
        if (s1.getPointA().x==s3.getPointA().x && s1.getPointA().y==s3.getPointA().y) {
            s1to3.x=s1.getPointA().x;
            s1to3.y=s1.getPointA().y;
        }
        else if (s1.getPointA().x==s3.getPointB().x && s1.getPointA().y==s3.getPointB().y) {
            s1to3.x=s1.getPointA().x;
            s1to3.y=s1.getPointA().y;
        }
        else if (s1.getPointB().x==s3.getPointA().x && s1.getPointB().y==s3.getPointA().y) {
            s1to3.x=s1.getPointB().x;
            s1to3.y=s1.getPointB().y;
        }
        else if (s1.getPointB().x==s3.getPointB().x && s1.getPointB().y==s3.getPointB().y) {
            s1to3.x=s1.getPointB().x;
            s1to3.y=s1.getPointB().y;
        }
        if (s2.getPointA().x==s3.getPointA().x && s2.getPointA().y==s3.getPointA().y) {
            s2to3.x=s2.getPointA().x;
            s2to3.y=s2.getPointA().y;
        }
        else if (s2.getPointA().x==s3.getPointB().x && s2.getPointA().y==s3.getPointB().y) {
            s2to3.x=s2.getPointA().x;
            s2to3.y=s2.getPointA().y;
        }
        else if (s2.getPointB().x==s3.getPointA().x && s2.getPointB().y==s3.getPointA().y) {
            s2to3.x=s2.getPointB().x;
            s2to3.y=s2.getPointB().y;
        }
        else if (s2.getPointB().x==s3.getPointB().x && s2.getPointB().y==s3.getPointB().y) {
            s2to3.x=s2.getPointB().x;
            s2to3.y=s2.getPointB().y;
        }
        if ((s1to2.x==s1to3.x && s1to2.y==s1to3.y) || (s1to2.x==s2to3.x && s1to2.y==s2to3.y) || (s1to3.x==s2to3.x && s1to3.y==s2to3.y))
            return false;
        else 
            return true;
    }
	float getArea() const //return the area of triangle
    {
		float area;
        float a=seg1.getLength(), b=seg2.getLength(), c=seg3.getLength();
        float s=(a+b+c)/2;
        area=sqrt(s*(s-a)*(s-b)*(s-c));
        return area;
    }	
private:
	Segment seg1, seg2, seg3;
};
