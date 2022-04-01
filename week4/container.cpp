#include <iostream>
using namespace std;

class container
{
public:
  container(void): box(NULL), len(0), index(0){}
  int getLen() {
    return len;
  }
  int getIndex() {
    return index;
  }
private:
  int *box;
  int len;
  int index;
};
