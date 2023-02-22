// QUESTION-D
// MATRYOSHKAS

#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        sort(arr.begin(), arr.end());
        reverse(arr.begin(), arr.end()); // sorting in descending order
        vector<pair<int, int>> count; // frequency of each integer in question array
        int i=0;
        while(i<n){
            int j=i;
            while(i<n && arr[i]==arr[j]){
                i++;
            }
            count.push_back({arr[j], i-j});
        }
        int ans=count[0].second; // the number of sets will be atleast the frequency of the largest element
        for(int i=1; i<count.size(); i++){
            if(count[i].first+1==count[i-1].first){ // for consecutive integers
                ans+=max(count[i].second-count[i-1].second, 0);
                // if frequency of smaller integer is larger, extra sets will be required
            }
            else{
                ans+=count[i].second; // for non-consecutive integers, new sets will be required
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}