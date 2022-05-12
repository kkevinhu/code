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
class queue : private container
{
public:
    queue()
    {
        len=1;
        index=0;
        box=new int[len];
    }
    queue(int l) : container(l)
    {
        index=0;
    }
    queue(const queue &a)
    {
        this->len=a.len;
        this->index=a.index;
        box=new int[len];
        copy(a.box, this->box, len);
    }
    bool enqueue(int data) {
        if (len==index)
            return false;
        else {
            box[index]=data;
            index++;
            return true;
        }
    }
    int *dequeue() {
        if (index==0) 
            return NULL;
        else {
            int *ans=new int;
            *ans=box[0];
            for (int i=1; i<index; i++) 
                box[i-1]=box[i];
            index--;
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
    int index;
};
