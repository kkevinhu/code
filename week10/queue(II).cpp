class container
{
protected:
    int *box;
    int len;
    void copy(int *from, int *to, int l)
    {
        for (int i = 0; i < l; i++)
            to[i] = from[i];
    }

public:
    container() : box(NULL), len(1) {}
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
    int getLen() const
    {
        return this->len;
    }
    virtual bool put_in(int obj) = 0;
    virtual int *take_out(void) = 0;
};

//ans
class queue : public container
{
public:
    queue() {
        len=1;
        index=0;
        box=new int[len];
    }
    queue(int l) {
        len=l;
        index=0;
        box=new int[len];
    }
    queue(const queue &a) {
        this->len=a.len;
        this->index=a.index;
        box=new int[len];
        copy(a.box, this->box, len);
    }
    virtual bool put_in(int obj) {
        if (len==index)
            return false;
        else {
            box[index++]=obj;
            return true;
        }
    }
    virtual int *take_out() {
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
    int getLen() {
        return len;
    }
    int index;
};

class priority_queue : public queue
{
public:
    bool order;
    priority_queue(int _len, bool f) {
        len=_len;
        index=0;
        order=f;
        box=new int[len];
    }
    virtual int *take_out() {
        int *ans=new int; 
        if (index==0 || box==NULL)
            return NULL;
        else if (order){
            int maxIdx=0;
            for (int i=1; i<index; i++) {
                if (box[i]>box[maxIdx]) {
                    maxIdx=i;
                }
            }
            *ans=box[maxIdx];
            for (int i=maxIdx; i<index-1; i++) {
                box[i]=box[i+1];
            }
            index--;
            return ans;
        }
        else {//smallest
            int minIdx=0;
            for (int i=1; i<index; i++) {
                if (box[i]<box[minIdx]) {
                    minIdx=i;
                }
            }
            *ans=box[minIdx];
            for (int i=minIdx; i<index-1; i++) {
                box[i]=box[i+1];
            }
            index--;
            return ans;
        }
    }
};
