#include <iostream>
using namespace std;

class container
{
private:
    int *box;
    int len;
    int index;
    static int count;
    bool reallocate(int size) {
        if (size==0)
            size++;
        int *_box=new int[size];
        if (_box==NULL)
            return false;
        for (int i=0; i<=index; i++) {
            _box[i]=box[i];
        }
        delete [] box;
        box=_box;
        len=size;
        return true;
    }
    static void increase() { 
        count++;
    }
    static void decrease() {
        count--;
    }
public:
    container(void): box(NULL), len(0), index(0) {}
    container(int _len) {
        box=new int[_len];
        increase();
        index=-1;
    }
    ~container() {
        delete [] box;
        decrease();
    }
    int getLen() {
        return len;
    }
    int getIndex() {
        return index;
    }
    void traversal() {
        if (index==-1)
            cout<<"empty";
        for (int i=0; i<=index; i++) {
            cout<<box[i]<<" ";
        }
        cout<<endl;
    }
    bool push(int data) {
        if (index==len-1) {
            if (reallocate(len*2)) {
                box[index]=data;
                index++;
                return true;
            }
        }
        else {
            box[index]=data;
            index++;
            return false;
        }
    }
    int pop() {
        if (index==-1)
            return 0;
        else {
            int first=box[0];
            for (int i=1; i<=index; i++) {
                box[i-1]=box[i];
            }
            index--;
            return first;
        }
    }
    static int getCount() {
        return count;
    }
};

int container::count=0;
