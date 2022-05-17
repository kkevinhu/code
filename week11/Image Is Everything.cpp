#include <iostream>
#include <cmath>
using namespace std;

int n;
char arr[6][100][100], coord[100][100][100];

void get(int i, int j, int k, int p, int &x, int &y, int &z) {
    //k=> front, left, back, right, up, down
    if (k==0) {
        x=n-p-1; y=j; z=n-i-1;
    } else if (k==1) {
        x=j; y=p; z=n-i-1;
    } else if (k==2) {
        x=p; y=n-j-1; z=n-i-1;
    } else if (k==3) {
        x=n-j-1; y=n-p-1; z=n-i-1;
    } else if (k==4) {
        x=i; y=j; z=n-p-1;
    } else if (k==5) {
        x=n-i-1; y=j; z=p;
    }
    return;
}
int main() {
    while (cin>>n && n!=0) {
        for (int i=0; i<n; i++) {
            for (int j=0; j<6; j++) {
                string input;
                cin>>input;
                for (int k=0; k<n; k++) {
                    arr[j][i][k]=input[k];
                }
            }
        }
        for (int i=0; i<n; i++)
            for (int j=0; j<n; j++)
                for (int k=0; k<n; k++)
                    coord[i][j][k]='?';
        int x, y, z;
        for (int k=0; k<6; k++) {
            for (int i=0; i<n; i++) {
                for (int j=0; j<n; j++) {
                    if (arr[k][i][j]=='.') {
                        for (int p=0; p<n; p++) {
                            get(i, j, k, p, x, y, z);
                            coord[x][y][z]='.';
                        }
                    }
                }
            }
        }
        while (1) {
            int flag=1;
            for (int k=0; k<6; k++)
                for (int i=0; i<n; i++)
                    for (int j=0; j<n; j++) {
                        if (arr[k][i][j]!='.') {
                            for (int p=0; p<n; p++) {
                                get(i, j, k, p, x, y, z);
                                if (coord[x][y][z]=='?') {
                                    coord[x][y][z]=arr[k][i][j];
                                    break;
                                }
                                if (coord[x][y][z]==arr[k][i][j])
                                    break;
                                if (coord[x][y][z]=='.')
                                    continue;
                                coord[x][y][z]='.';
                                flag=0;
                            }
                        }
                    }
            if (flag) break;
        }
        int ans=0;
        for (int i=0; i<n; i++)
            for (int j=0; j<n; j++)
                for (int k=0; k<n; k++)
                    if (coord[i][j][k]!='.')
                        ans++;
        cout<<"Maximum weight: "<<ans<<" gram(s)"<<endl;
    }
}
