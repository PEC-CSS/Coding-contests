#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        char c;
        cin>>c;
        string s="codeforces";
        bool check=false;
        for(int i=0; i<10; i++){
            if(s[i]==c){
                check=true;
                break;
            }
        }
        if(check){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}