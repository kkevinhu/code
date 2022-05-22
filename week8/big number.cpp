#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class BigNumber
{
public:
    BigNumber(string _n) {
        n=_n;
        flag=1;
    }
    void findPoint() {
        for (int i=0; i<n.length(); i++) {
            if (n[i]=='.') {
                point=i;
                return;
            }
        }
        point=-1;
    }
    void check() {
        if (n[0]=='-') {
            flag=0;
            n.erase(0, 1); //n的第0個開始刪除1個字元'-'
        }
    }
    void operator<<(BigNumber &bn) {
        cout<<bn.n;
    }
    void match(BigNumber &bn) {
        if (bn.point==-1 && point!=-1) {
            bn.n+='.';
            for (int i=0; i<n.length()-1; i++)
                bn.n+='0';
        }
        else if (bn.point!=-1 && point==-1) {
            n+='.';
            for (int i=0; i<bn.n.length()-1; i++)
                n+='0';
        }
        else if (bn.point!=-1 && point!=-1) {
            if (bn.point>point) {
                for (int i=0; i<bn.point-point; i++)
                    n='0'+n;
            }
            else if (bn.point<point) {
                for (int i=0; i<point-bn.point; i++)
                    bn.n='0'+bn.n;
            }
        }
        else if (bn.point==-1 && point==-1) {
            if (bn.n.length()>n.length()) {
                for (int i=0; i<bn.n.length()-n.length(); )
                    n='0'+n;
            }
            else if (bn.n.length()<n.length()) {
                for (int i=0; i<n.length()-bn.n.length(); )
                    bn.n='0'+bn.n;
            }
        }
        if (bn.n.length()>n.length()) {
            for (int i=0; i<bn.n.length()-n.length(); )
                n+='0';
        }
        else if (bn.n.length()<n.length()) {
            for (int i=0; i<n.length()-bn.n.length(); ) 
                bn.n+='0';
        }   
    }
    string operator+(BigNumber &bn) {
        bool twoNeg=0, isCarry=0;
        if (flag=0 || bn.flag==0) {
            if (flag==0 && bn.flag==0)
                twoNeg=1;
            else if (flag==0) {
                string tmp=n;
                BigNumber mytmp=BigNumber(tmp);
                return bn-mytmp;
            }
            else if (bn.flag==0) {
                string tmp=bn.n;
                BigNumber bntmp=BigNumber(tmp);
                return *this-bntmp;
            }
        }
        for (int i=n.length(); i>=0; i--) {
            if (n[i]=='.') continue;
            int tmp=n[i]-'0'+bn.n[i]-'0';
            if (tmp>=10) {
                if (i==0) isCarry=1;
                else {
                    tmp-=10;
                    if (n[i-1]=='.') 
                        n[i-2]++;
                    //else 
                        n[i-1]++;
                }
                n[i]=tmp+'0';
            }
        }
        if (isCarry) {
            n='1'+n;
        }
        if (twoNeg) {
            n='-'+n;
        }
        return n;
    }
    string operator-(BigNumber &bn) {
        if (flag==0 || bn.flag==0) {
            if (flag==0 && bn.flag==0) {
                string tmp=n;
                BigNumber ntmp=BigNumber(n);
                return bn-ntmp;
            }
            else if (flag==0) {
                string tmp=n;
                BigNumber ntmp=BigNumber(n);
                bn.flag=0;
                return bn+ntmp;
            }
            else if (bn.flag==0) {
                string tmp=bn.n;
                BigNumber bntmp=BigNumber(tmp);
                return *this+bntmp;
            }
            if (n<bn.n) {
                string ans;
                BigNumber ntmp=BigNumber(n);
                ans=bn-ntmp;
                ans='-'+ans;
                return ans;
            }
            else if (n==bn.n) 
                return "0";
            else {
                for (int i=n.length(); i>=0; i--) {
                    if (n[i]=='.')
                        continue;
                    int tmp=(n[i]-'0')-(bn.n[i]-'0');
                    if (tmp<0) {
                        tmp+=10;
                        if (n[i-1]=='.')
                            n[i-2]--;
                        else 
                            n[i-1]--;
                    }
                    n[i]=tmp+'0';
                }
                return n;
            }
        }
    }
private:
    string n;
    int point;
    bool flag;//+ or -
};

int main() {
    string a, b;
    cin>>a>>b;
    BigNumber b1=BigNumber(a);
    BigNumber b2=BigNumber(b);
    b1.check();
    b1.findPoint();
    b2.check();
    b2.findPoint();
    b1.match(b2);
    cout<<b1+b2<<endl<<b1-b2<<endl;
}
