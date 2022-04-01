#include <iostream>
using namespace std;
void fun() {
 	char a;
  	cin>>a;
  	if (a!='.') {
     	fun(); 
    }
  	if (a!='.') {
     	cout<<a; 
    }
}
int main() {
  	fun();
}
