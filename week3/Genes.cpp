#include <iostream>
using namespace std;
/*
dominant -> 10, recessive -> 3, non-existant -> 1
a-a -> 20, a-b -> 13, a -> 10
a-c -> 11, b-b -> 6, b -> 3
b-c -> 4, c-c -> 2, c -> 1
*/
string name[3100], data[3100];
int type[3100]={0}, idx=0;
int represent(string gene) {
    int num;
    if (gene=="dominant") num=10;
    else if (gene=="recessive") num=3;
    else if (gene=="non-existent") num=1;
    return num;
}

int findGene(string par1, string par2) {
    int idx1, idx2;
    for (int i=0; i<idx; i++) {
        if (name[i]==par1) idx1=i;
        if (name[i]==par2) idx2=i;
    }
    return (type[idx1]+type[idx2]);
}

int change(int rep) {
    int s;
    if (rep==20 || rep==13 || rep==10)
        s=10;
    else if (rep==11 || rep==6 || rep==3)
        s=3;
    else if (rep==4 || rep==2 || rep==1)
        s=1;
    return s;
}
int main() {
    int n;
    cin>>n;
    string input1, input2;
    for (int i=0; i<n; i++) {
        cin>>input1>>input2;
        if (input2=="dominant" || input2=="recessive"|| input2=="non-existent") {
            name[idx]=input1;
            type[i]=represent(input2);
            idx++;
        }
        else {
            data[idx]=input1;
            name[idx]=input2;
            idx++;
        }
    }
    //find gene
    for (int i=0; i<idx; i++) {
        if (type[i]==0) {
            for (int j=i; j<idx; j++) {
                if (name[i]==name[j]) {
                    type[i]=change(findGene(data[i], data[j]));
                    type[j]=type[i];
                }
            }
        }
    }
    //sort
    for (int i=0; i<idx-1; i++) {
        for (int j=0; j<idx-i-1; j++) {
            if (name[j]>name[j+1]) {
                string temp;
                int tmp;
                temp=name[j];
                name[j]=name[j+1];
                name[j+1]=temp;
                tmp=type[j];
                type[j]=type[j+1];
                type[j+1]=tmp;
            }
        }
    }
    for (int i=0; i<idx; i++) {
        if (i>0 && name[i]==name[i-1]) continue;
        if (type[i]==10) cout<<name[i]<<" dominant"<<endl;
        else if (type[i]==3) cout<<name[i]<<" recessive"<<endl;
        else if (type[i]==1) cout<<name[i]<<" non-existent"<<endl;
    }
}
