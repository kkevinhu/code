#include <iostream>
#include <string>
using namespace std;

int count, flagW, flagB;
void findPoints(char arr[10][10], int x, int y) {
    if (x<0 || y<0 || x>8 || y>8) return;
    if (arr[x][y]=='.') {
        count++;
        arr[x][y]='?';
    }
    else {
        if (arr[x][y]=='O') 
          flagW=1;
        if (arr[x][y]=='X') 
          flagB=1;
        return;
    }
    findPoints(arr, x-1, y);
    findPoints(arr, x+1, y);
    findPoints(arr, x, y-1);
    findPoints(arr, x, y+1);
}
int main() {
    int n;
    char arr[10][10];
    cin>>n;
    while (n--) {
        int white=0, black=0;
        for (int i=0; i<9; i++)
            for (int j=0; j<9; j++)
                cin>>arr[i][j];
        for (int i=0; i<9; i++) {
            for (int j=0; j<9; j++) {
                if (arr[i][j]=='O') white++;
                else if (arr[i][j]=='X') black++;
                else if (arr[i][j]=='.') {
                    flagW=0, flagB=0;
                    count=0;
                    findPoints(arr, i, j);
                    if (flagW==1 && flagB==1)
                        continue;
                    else if (flagW==1)
                        white+=count;
                    else if (flagB==1)
                        black+=count;
                }
                else
                    continue;
            }
        }
        cout<<"Black "<<black<<" White "<<white<<endl;
    }
}
