#include <iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int ans=n;
    while (n/3>=1) {
        ans+=n/3;
        n=n/3+n%3;   
    }
    if (n==2)
        ans++;
    cout<<ans;
}
