#include <iostream>
using namespace std;

int main() {
    int n;
    long s, d;
    cin>>n;
    while (n--) {
        cin>>s>>d;
        long x, y;
        if ((s-d)<0 || (s+d)%2!=0 || (s-d)%2!=0)
            cout<<"impossible"<<endl;
        else {
            x=(s+d)/2;
            y=(s-d)/2;
            if (y>x) {
                long tmp;
                tmp=x;
                x=y;
                y=tmp;
            }
            cout<<x<<" "<<y<<endl;
        }
    }
}
