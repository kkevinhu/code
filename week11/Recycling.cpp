#include <iostream>
using namespace std;
///UVA 102
int color(char c) {
    if (c=='r') return 0;
    if (c=='o') return 1;
    if (c=='y') return 2;
    if (c=='g') return 3;
    if (c=='b') return 4;
}
int waste(char w) {
    if (w=='P') return 0;
    if (w=='G') return 1;
    if (w=='A') return 2;
    if (w=='S') return 3;
    if (w=='N') return 4;
}
int main() {
    string type;
    int reprent[100][5], idx=0;
    while (cin>>type && type!="#") {
        if (type[0]!='e') {
            for (int i=0; i<5; i++) {
                reprent[idx][color(type[i*4])]=waste(type[i*4+2]);
            }
            idx++;
        }
        else {
            int min=100000, ans, n;
            for (int i=0; i<idx; i++) {
                n=0;
                for (int j=0; j<idx; j++) {
                    for (int k=0; k<5; k++) {
                        if (reprent[i][k]!=reprent[j][k])
                            n++;
                    }
                }
                if (n<min) {
                    min=n;
                    ans=i+1;
                }
            }
            idx=0;
            cout<<ans<<endl;
        }
    }
}
