#include <iostream>
using namespace std;

int main() {
    int t;
    cin>>t;
    int n, p;
    while (t--) {
        cin>>n>>p;
        int par[100], flag[3650]={0}, ans=0;
        for (int i=0; i<p ; i++)
            cin>>par[i];
        for (int i=0; i<p; i++) {
            for (int j=1; par[i]*j<=n; j++) {
                int idx=par[i]*j;
                flag[idx]=1;
            }
        }
        for (int i=1; i<=n; i++) {
            if ((i>=6) && ((i%7==0) || (i%7==6)))
                flag[i]=0;
        }
        for (int i=1; i<=n; i++) {
            if (flag[i])
                ans++;
        }
        cout<<ans<<endl;
    }
}
