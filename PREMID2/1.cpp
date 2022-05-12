#include <iostream>
#include <sstream>
using namespace std;

class Convert
{
public:
    string toString(int n) {
        stringstream s1;
        s1<<n;
        string s=s1.str();
        return s;
    }
    string toString(float f) {
        stringstream s2;
        s2<<f;
        string s=s2.str();
        return s;
    }
};

int main() {
  int num;
  float f;
  Convert c1,c2;
  cin>>num;
  cout<<c1.toString(num)<<endl;
  cin>>f;
  cout<<c2.toString(f);
  return 0;
}
