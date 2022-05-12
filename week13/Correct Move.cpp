#include <iostream>
using namespace std;

int main() {
    int king, queen, pos;
    while (cin>>king>>queen>>pos) {
        if (king==queen)
            cout<<"Illegal state"<<endl;
        else if (queen==pos || king==pos) {
            cout<<"Illegal move"<<endl;
        }
        else if ((king==0 && pos==9) || (king==7 && pos==14) || (king==56 && pos==49) || (king==63 && pos==54)) {
            cout<<"Stop"<<endl;
        }
        else if ((queen%8!=pos%8) && (queen/8!=pos/8))//pos not at queen UDLR
            cout<<"Illegal move"<<endl;
        else {
            if (king/8==queen/8 && queen/8==pos/8) {//horizontal
                if ((pos<king && king<queen) || (queen<king && king<pos)) {//(p k q) or (q k p)
                    cout<<"Illegal move"<<endl;
                }
                else if ((king+1==pos) || (king-1==pos) || (king+8==pos) || (king-8==pos)) {//p在k上下左右
                    cout<<"Move not allowed"<<endl;
                }
                else 
                    cout<<"Continue"<<endl;
            }
            else if (king%8==queen%8 && queen%8==pos%8) {//vertical
                if ((pos<king && king<queen) || (queen<king && king<pos)) {
                    cout<<"Illegal move"<<endl;
                }
                else if ((king+1==pos) || (king-1==pos) || (king+8==pos) || (king-8==pos)) {//p在k上下左右
                    cout<<"Move not allowed"<<endl;
                }
                else   
                    cout<<"Continue"<<endl;
            }
            else {
                if ((king+1==pos && king/8==pos/8) || (king-1==pos && king/8==pos/8)) {
                    cout<<"Move not allowed"<<endl;
                }
                else if ((king-8==pos && king%8==pos%8) || (king+8==pos && king%8==pos%8)) {
                    cout<<"Move not allowed"<<endl;
                }
                else 
                    cout<<"Continue"<<endl;
            }
        }
    }
}
