#include<iostream>
using namespace std;
int subset[100];
int arr[100];

void findSubset(int n, int t, int count, int own, int tcount) {
    for (int i=own; i<n; i++) {
        if (count>tcount) {
            arr[tcount-1]=subset[i];
            findSubset(n, t, count, i+1, tcount+1);
        }
        else if (count==tcount) {
            arr[tcount-1]=subset[i];
            int sum=0;
            for (int j=0; j<count; j++)
                sum+=arr[j];
            if (sum==t) {
                for (int k=0; k<count; k++)
                    cout<<arr[k]<<" ";
                cout<<endl;
            }
        }
    }
}
int main()
{
    int n,t;
    cin>>n>>t;
    for(int i=0;i<n;i++)
        cin>>subset[i];
    for (int i=0; i<n-1; i++) {//sort
        for (int j=0; j<n-i-1; j++) {
            if (subset[j]>subset[j+1]) {
                int tmp=subset[j];
                subset[j]=subset[j+1];
                subset[j+1]=tmp;
            }
        }
    }
    for(int i=1;i<=n;i++)
        findSubset(n,t,i,0,1);
}
