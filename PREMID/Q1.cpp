#include <iostream>
using namespace std;

class F
{
public:
    F(int _a, int _b) {
        a=_a;
        b=_b;
    }
    int S(int x) {
        int ans1=0;
        for (int n=0; n<=x; n++) {
            ans1=ans1+a*n+b;
        }
        return ans1;
    }
    int G(int x, int y) {
        int ans2=0;
        for (int n=x; n<=y; n++) {
            ans2=ans2+a*n+b;
        }
        return ans2;
    }
private:
    int a, b;
};
int main() {
  int a, b, j;
  std::cin>>a>>b;
  F f(a, b);
  for(j = 0;j < 10;j ++)
  {
    int x, y;
    std::cin>>x>>y;
    std::cout<<f.S(x)<<std::endl;
    std::cout<<f.G(x, y)<<std::endl;
  }
  return 0;
}
