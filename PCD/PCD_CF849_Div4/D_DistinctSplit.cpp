#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        map<char, int> count;
        for(int i=0; i<n; i++){
            count[s[i]]++;
        }
        map<char, int> temp;
        int ans=count.size()+temp.size();
        for(int i=0; i<n; i++){
            temp[s[i]]++;
            count[s[i]]--;
            if(count[s[i]]==0){
                count.erase(s[i]);
            }
            int curr=count.size()+temp.size();
            ans=max(ans, curr);
        }
        cout<<ans<<endl;
    }
    return 0;
}