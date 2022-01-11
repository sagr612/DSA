#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,j,a=0,b=1,c=1;
    cin>>n;
    for(i=0;i<n;i++)
    {
        for(j=0;j<i+1;j++)
        {
            cout<<c<<" ";
            c=a+b;
            a=b;
            b=c;
        }
        cout<<endl;
    }
}
