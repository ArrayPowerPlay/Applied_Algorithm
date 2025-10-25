#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,K;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    cin>>K;
    int cnt=0,sum;
    for(int mask=0;mask<(1<<n);mask++){
        sum=0;
        for(int i=0;i<n;i++){
            if (mask & (1 << i)) sum += v[i];
        }
        if(sum>=K) cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}
