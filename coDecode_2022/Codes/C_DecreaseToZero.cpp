#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void solve(){
    int n; cin >> n;
    vector <int> arr(n);
    for (int i = 0; i < n; i ++){
        cin >> arr[i];
    }
    if (n == 1){
        cout << "alice\n"; 
        return;
    }
    for(int i = 0; i < n; i ++){
        if (abs(arr[i]) > 1){
            cout << (i % 2? "bob\n" : "alice\n");
            return;
        }
    }
    cout << (n % 2? "alice\n" : "bob\n");
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t; cin >> t;
    for (int _ = 0; _ < t; _ ++){
        solve();
    }
    return 0;
}
