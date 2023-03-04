#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;
    cin>>n;
    
    int absum=0;
    int count=0;
    int min1=INT_MAX;
    
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(x<0){
            count++;
        }
        absum+=abs(x);
        min1=min(min1,abs(x));
    }

    if(count&1){
        cout<<absum-(2*min1)<<endl;
    }
    else{
        cout<<absum<<endl;
    }

}
signed main()
{
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
