#include <iostream>
#include <string>
#include <map>
#include <list>
#include <algorithm>
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
    string getTagName()
    {
        return tagName;
    }
    string getContent()
    {
        return content;
    }
    string tagName, content;
};
//ans

class HTMLElementWithAttributes : public HTMLElement
{
public:
    HTMLElementWithAttributes(string s) : HTMLElement(s)
    {
        string tagName=getTagName();
        for (int i=tagName.length()+1; s[i]!='>'; i++) {
            string *key=new string;
            string *value=new string;
            for (i+=1; s[i+1]!='"'; i++) {//key
                *key+=s[i];
            }
            tmp.push_back(*key);
            for (i+=2; s[i]!='"'; i++) {//value
                *value+=s[i];
            }
            attributes[*key]=*value;
            tmp.sort();
            delete key;
            delete value;
        }
    }
    string operator [](string key) {
        return attributes[key];
    }
    list<string> getAttributes() {
        return tmp;
    }
private:
    map<string, string> attributes;
    list<string> tmp;
};
int main() {
  string str;
  getline(cin,str);
  HTMLElementWithAttributes html(str);
  cout<<html.getTagName()<<endl;
  list<string> key = html.getAttributes();
  for(string k : key)
    cout<<html[k]<<endl;
  return 0;
}
