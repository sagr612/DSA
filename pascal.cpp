include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,j;
    cin>>n;
    vector<int>v1,v2;
    v1.push_back(1);
    for(i=1; i<=n; i++)
    {
        if(i%2!=0)
        {
            for(j=0; j<i; j++)
            {
                int p;
                if(j-1<0)
                {
                    p=v1[j];
                }
                else if(j==v1.size())
                {
                    p=v1[j-1];
                }
                else
                {
                    p=v1[j]+v1[j-1];
                }
                v2.push_back(p);
                cout<<p<<" ";
            }
            v1.clear();
        }
        else
        {
            for(j=0; j<i; j++)
            {
                int p;
                if(j-1<0)
                {
                    p=v2[j];
                }
                else if(j==v2.size())
                {
                    p=v2[j-1];
                }
                else
                {
                    p=v2[j]+v2[j-1];
                }
                v1.push_back(p);
                cout<<p<<" ";
            }
            v2.clear();
        }
        cout<<endl;
    }
}
