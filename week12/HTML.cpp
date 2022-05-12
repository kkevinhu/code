#include <iostream>
#include <string>
using namespace std;

class HTMLElement
{
public:
    HTMLElement(string s) {
        int left=0, len=s.length(), right=len-1;
        while (s[left]!='>')
            left++;
        while (s[right]!='<')
            right--;
        for (int i=1; i<left; i++)
            tagName+=s[i];
        for (int i=left+1; i<right; i++)
            content+=s[i];
    }
    string tagName, content;
    string getTagName()
    {
        return tagName;
    }
    string getContent()
    {
        return content;
    }
};
int main() {
  std::string str;
  getline(cin, str);
  HTMLElement html(str);
  std::cout<<html.getTagName()<<std::endl;
  std::cout<<html.getContent()<<std::endl;
  return 0;
}
