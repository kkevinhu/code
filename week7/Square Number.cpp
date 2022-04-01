#include <iostream>
#include <cmath>
using namespace std;

bool check(int x) {
    for (int i=1; i<=sqrt(x); i++) {
        if (x==i*i)
            return true;
    }
    return false;
}
int main() {
    int a, b;
    while (cin>>a>>b) {
        if (a==0 && b==0)
            break;
        int ans=0;
        if (a==b) {
            if (check(a)) {
                ans=1;
            }
            else
                ans=0;
        }
        else {
            int _a=sqrt(a);
            int _b=sqrt(b);
            ans=_b-_a;
            if (check(a))
                ans++;
        }
        cout<<ans<<endl;
    }
}
