#include <iostream>
using namespace std;

int main() {
    int n, game=1;
    while (cin>>n && n!=0) {
        int A[100], B[100][100], idx=0, input;
        for (int i=0; i<n; i++) cin>>A[i];
        //inputB
        while (1) {
            for (int i=0; i<n; i++) {
                cin>>input;
                B[idx][i]=input;
            }
            if (B[idx][0]==0)
                break;
            idx++;
        }
        int idxptr=0;
        cout<<"Game "<<game<<":"<<endl;
        while (idxptr<idx) {
            int a=0, b=0, flagA[100]={0}, flagB[100][100]={0};
            //same
            for (int i=0; i<n; i++) {
                if (A[i]==B[idxptr][i]) {
                    a++;
                    flagA[i]=1;
                    flagB[idxptr][i]=1;
                }
            }
            //different
            for (int i=0; i<n; i++) {
                if (flagA[i]==0) {
                    for (int j=0; j<n; j++) {
                        if (flagB[idxptr][j]==0 && flagA[i]==0) {
                            if (A[i]==B[idxptr][j]) {
                                b++;
                                flagA[i]=1;
                                flagB[idxptr][j]=1;
                            }
                        }
                    }
                }
            }
            cout<<"    ("<<a<<","<<b<<")"<<endl;
            idxptr++;
        }
        game++;
    }
}
