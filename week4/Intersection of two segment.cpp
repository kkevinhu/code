Segment(Coordinate _a, Coordinate _b)
{
    a=_a;
    b=_b;
}

Coordinate *samePoint(Coordinate myA, Coordinate myB, Coordinate sA, Coordinate sB) {
    Coordinate *newPoint=new Coordinate;
    if (sA.getX()==myA.getX() && sA.getY()==myA.getY())
        *newPoint=Coordinate(sA);
    else if (sA.getX()==myB.getX() && sA.getY()==myB.getY())
        *newPoint=Coordinate(sA); 
    else if (sB.getX()==myA.getX() && sB.getY()==myA.getY())
        *newPoint=Coordinate(sB);
    else if (sB.getX()==myB.getX() && sB.getY()==myB.getY())
        *newPoint=Coordinate(sB);
    else
        return NULL;
    return newPoint;
}

Coordinate *getIntersection(Segment s) 
{
    float sDelX=s.a.getX()-s.b.getX();
    float sDelY=s.a.getY()-s.b.getY();
    float myDelX=this->a.getX()-this->b.getX();
    float myDelY=this->a.getY()-this->b.getY();

    //samepoint?
    Coordinate *point=samePoint(this->a, this->b, s.a, s.b);
    if (point!=NULL)
        return point;
    //same slope
    if (sDelY*myDelX==myDelY*sDelX)
        return NULL;
    else {
        //find intersection
        float slope, b;
        float intersectionX, intersectionY;
        if (sDelX==0 && myDelY==0) {
            intersectionX=s.a.getX();
            intersectionY=this->a.getY();
        }
        else if (sDelY==0 && myDelX==0) {
            intersectionX=this->a.getX();
            intersectionY=s.a.getY();
        }
        else if (sDelY==0) {//s=> y=s.y . my=> y=mx+b => x=(y-b)/m  b=y-mx
            slope=myDelY/myDelX;
            b=this->a.getY()-slope*this->a.getX();
            intersectionY=s.a.getY();
            intersectionX=(intersectionY-b)/slope;
        }
        else if (myDelY==0) {//my=> y=my.y  . s=> y=mx+b => x=(y-b)/m   b=y-mx
            slope=sDelY/sDelX;
            b=s.a.getY()-slope*s.a.getX();
            intersectionY=this->a.getY();
            intersectionX=(intersectionY-b)/slope;
        }
        else if (sDelX==0) {// s=> x=s.x  .  my=> y=mx+b => b=y-mx
            slope=myDelY/myDelX;
            b=this->a.getY()-slope*this->a.getX();
            intersectionX=s.a.getX();
            intersectionY=slope*intersectionX+b;
        }
        else if (myDelX==0) {// my=> x=my.x  .  s=>y=mx+b => b=y-mx
            slope=sDelY/sDelX;
            b=s.a.getY()-slope*s.a.getX();
            intersectionX=this->a.getX(); 
            intersectionY=slope*intersectionX+b;
        }
        else {// s=> y = sSlope * s.x + sb, my=> y = mySlope * my.x + myb
            float sSlope=sDelY/sDelX, mySlope=myDelY/myDelX;
            float sb=s.a.getY()-sSlope*s.a.getX(), myb=this->a.getY()-mySlope*this->a.getX();
            intersectionX=-1*(sb-myb)/(sSlope-mySlope);
            intersectionY=sSlope*intersectionX+sb;
        }
        Coordinate *ans=new Coordinate;
        *ans=Coordinate(intersectionX, intersectionY);
        //check intersection is on line?
        float disSumS=sqrt(pow(intersectionX-s.a.getX(), 2)+pow(intersectionY-s.a.getY(), 2))+
                        sqrt(pow(intersectionX-s.b.getX(), 2)+pow(intersectionY-s.b.getY(), 2));
        float disSumMy=sqrt(pow(intersectionX-this->a.getX(), 2)+pow(intersectionY-this->a.getY(), 2))+
                        sqrt(pow(intersectionX-this->b.getX(), 2)+pow(intersectionY-this->b.getY(), 2));
        if (disSumS==s.length() && disSumMy==this->length()) {
            return ans;
        }
        else 
            return NULL;
    }
}
float length()
{
    float delX, delY, len;
    delX=a.getX()-b.getX();
    delY=a.getY()-b.getY();
    len=sqrt(delX*delX + delY*delY);
    return len;
}
