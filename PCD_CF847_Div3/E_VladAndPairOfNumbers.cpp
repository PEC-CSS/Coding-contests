// QUESTION-E
// VLAD AND A PAIR OF NUMBERS

#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int x;
        cin>>x;
        /* a^b=(a+b)/2
        2*(a^b)=(a+b)
        (a^b)=2(a&b)
        Hence, (a^b)=x
        (a&b)=x/2         */
        if(x%2==0){ // x cannot be odd as a&b is an integer
            int a=x+x/2; // a=(a^b)+(a&b)
            int b=x/2; // b=(a&b)
            if((a^b)==x){ // check if condition is satisfied
                cout<<a<<" "<<b<<endl;
            }
            else{
                cout<<-1<<endl;
            }
        }
        else{
            cout<<-1<<endl;
        }
    }
    return 0;
}