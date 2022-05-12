class Container
{
public:
    Container()
    {
        index = 0;
    }
    void insert(int n)
    {
        if(n >= 0)
        {
            data[index] = n;
            index ++;
        }
    }
    virtual int remove() = 0;  //remove an element from container
    void display()
    {
        int j;
        if(index == 0)
            return;
        for(j = 0; j < index - 1; j ++)
            cout<<data[j]<<", ";
        cout<<data[j];
    }
protected:
    int data[100];
    int index;
};
//ans

class RemoveFromBig : public Container
{
public:
    int remove() {
        int ans, maxIdx=0;
        for (int i=1; i<index; i++) {
            if (data[i]>data[maxIdx]) {
                maxIdx=i;
            }
        }
        ans=data[maxIdx];
        for (int i=maxIdx+1; i<index; i++)
            data[i-1]=data[i];
        index--;
        return ans;
    }
};

class RemoveFromSmall : public Container
{
public:
    int remove() {
        int ans, minIdx=0;
        for (int i=1; i<index; i++) {
            if (data[i]<data[minIdx]) {
                minIdx=i;
            }
        }
        ans=data[minIdx];
        for (int i=minIdx+1; i<index; i++)
            data[i-1]=data[i];
        index--;
        return ans;
    }
};
