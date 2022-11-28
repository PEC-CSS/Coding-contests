// ਹਰਅਸੀਸ ਸਿੰਘ

#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;
#define ff                              first
#define ss                              second
#define infinity                        8999999999999999999
#define sz(v)                           ((int)(v).size())
#define all(v)                          (v).begin(),(v).end()
#define MOD_DEFINE                      const int MOD = 1e9 + 7;
#define endl                            '\n'
#define int                             long long
#define pii                             pair<int, int>
#define vi                              vector<int>
#define pb(n)                           push_back((n))
#define mii                             map<int, int>
#define umii                            unordered_map<int, int>
#define l(var, initial, final)          for(int var=initial; var < final; var++)
#define cout                            std::cout
#define cin                             std::cin
#define pqb                             priority_queue<int>
#define pqs                             priority_queue<int, vi, greater<int>>
#define fps(x, y)                       fixed<<setprecision(y)<<x
typedef long long ll;
typedef vector<pii> vpii;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

void prn() { }
template<typename T1, typename T2> istream &operator >> (istream& in, pair<T1, T2> &a){in >> a.ff >> a.ss; return in;}
template<typename T1, typename T2> ostream &operator << (ostream& out, pair<T1, T2> a){out << a.ff << ' ' << a.ss; return out;}
template<typename T, typename T1> T amax(T &a, T1 b){if(b > a) a = b; return a;}
template<typename T, typename T1> T amin(T &a, T1 b){if(b < a) a = b; return a;}
template<typename T> istream& operator>>(istream &in, vector<T> &v) { for (auto &x : v) in >> x; return in;}
template<typename T> ostream& operator<<(ostream &out, vector<T> &v) {out << "{ "; for (auto &x : v) out << x << " "; out << "}\n"; return out;}
template<typename T, typename... Args> void prn(T x, Args... args) {cout << x << " "; prn(args...);}
template<typename Iterable> void prnIter(const Iterable& ITER, ostream&out = cout){ auto x = ITER.begin(); out << "{ "; for (; x != ITER.end(); ++x) out << *x << ' '; out << "}" << endl;}

MOD_DEFINE
vector<vector<int>> dp;

int get(int id, int state, const vector<int> &in){
        int n = sz(in); // for mod
        
        id %= n;
        if(id < 0) id += n;
        if(state == 0){
                return in[id];
        }
        
        for(int j = 31; j >= 0; j--){
                if((state >> j) & 1){
                        if(dp[id][j] != -1) return dp[id][j];
                        return dp[id][j] = get(id - (1 << j), state - (1 << j), in) ^ get(id + (1 << j), state - (1 << j), in);
                }
        }
        assert(false);

        return -1;
}   

void slv(){
        int n, m; cin >> n >> m; 
        dp = vector<vector<int>> (n, vector<int> (32, -1));
        vector<int> in(n); cin >> in;

        for(auto &p : in) p > 0 ? p = 1 : p = 0;

        int pos = 0;
        for(int i = 0; i < n; i++){
                if(get(i, m, in)) pos++;
        }
        cout << pos << endl;
}

int32_t main(){
        
        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

        int T = 1;

        cin >> T;
        for(int t = 1; t <= T; t++){
                slv();
        }
        return 0;
}
/*
*think brute force first.
*try proving the algorithm on pen n paper first.
*floating point precision errors ?
*implementation too lengthy ? logic might be incorrect.
*read the question again.
*/