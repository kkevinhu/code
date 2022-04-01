#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    getline(cin, s);
    int len=s.length(), ans=0, i, j;
    if (len==1) cout<<1;
    for (int i=0, j=1; j<len;) {
        if (s[i]==s[j]) {
            i++;
            j++;
        }
        else {
            for (int idx=i; idx<j; idx++) {
                if (s[idx]==s[j]) {
                    i=idx+1;
                }
            }
            j++;
        }
        if (ans<j-i)
            ans=j-i;
    }
    cout<<ans;
}
