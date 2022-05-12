class container
{
protected:
    int *box;
    int len;
    void copy(int *from, int *to, int l)
    {
        for(int i=0; i<l; i++)
            to[i] = from[i];
    }
public:
    container(): box(NULL), len(1) {}
    container(int l)
    {
        int *tmp = new int[l];
        this->len = l;
        this->box = tmp;
    }
    container(const container &a)
    {
        int *tmp = new int[a.len];
        copy(a.box, tmp, a.len);
        this->len = a.len;
    }
    bool reallocate(int l)
    {
        int *tmp = new int[l];
        if(!tmp)
            return false;
        copy(this->box, tmp, this->len);
        delete box;
        this->box = tmp;
        this->len = l;
        return true;
    }
};
//ans
class stack : private container
{
public:
    stack() {
        len=1;
        top=0;
        box=new int[len];
    }
    stack(int l) {
        len=l;
        top=0;
        box=new int[len];
    }
    stack(const stack &a) {
        this->len=a.len;
        this->top=a.top;
        box=new int[len];
        copy(a.box, this->box, len);
    }
    bool push(int data) {
        if (top==len)
            return false;
        else {
            top++;
            box[top]=data;
            return true;    
        }
    }
    int *pop() {
        if (top==0)
            return NULL;
        else {
            int *ans=new int;
            *ans=box[top];
            top--;
            return ans;
        }
    }
    bool increase() {
        return reallocate(len*2);
    }
    int getLen() {
        return len;
    }
private:
    int top;
};
