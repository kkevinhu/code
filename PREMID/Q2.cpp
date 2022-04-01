#include <iostream>
using namespace std;

class F
{
public:
    F(int _a, int _b) {
        a=_a;
        b=_b;
    }
    F operator +(const F &c) {
        F val=F(this->a+c.a, this->b+c.b);
        return val;
    }
    F operator -(const F &c) {
        F val=F(this->a-c.a, this->b-c.b);
        return val;
    }
    int S(int x) {
        int ans1=0;
        for (int n=0; n<=x; n++) {
            ans1=ans1+a*n+b;
        }
        return ans1;
    }
    int G(int x, int y) {
        int ans2=0;
        for (int n=x; n<=y; n++) {
            ans2=ans2+a*n+b;
        }
        return ans2;
    }
private:
    int a, b;
};
