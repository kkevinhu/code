#include <iostream>
using namespace std;

string countAndSay(int n) {
    if (n==1) 
        return "1";
    if (n==2)
        return "11";
    string say="11";
    for (int i=3; i<=n; i++) {
        say+="#";
        string s;
        int count=1;    
        for (int j=1; j<say.length(); j++) {
            if (say[j]==say[j-1])
                count++;
            else if (say[j]!=say[j-1]) {
                s+=to_string(count);
                s+=say[j-1];
                count=1;
            }
        }
        say=s;
    }
    return say;
}

int main() {
    int n;
    while (cin>>n) {
        string s=countAndSay(n);
        cout<<s<<endl;
    }
}
