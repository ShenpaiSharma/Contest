#include <bits/stdc++.h>
using namespace std;
typedef long long lld;

int main() {
    int n,a[100000],t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int min=INT_MAX;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            if(a[i]<min)min=a[i];
        }
        int ans=INT_MAX,iter=5;
        while(iter--)
        {
        int res=0;
        for(int i=0;i<n;i++)
        {
            int d=a[i];
            while(d-5>=min)
            {
                d-=5;
                res++;
            }
            while(d-2>=min)
            {
                d-=2;
                res++;
            }
            while(d-1>=min)
            {
                d-=1;
                res++;
            }
            //cout<<a[i]<<endl;
        }
        min--;
        if(res<ans)ans=res;
        }
        cout<<ans<<endl;
    }
    return 0;
}
