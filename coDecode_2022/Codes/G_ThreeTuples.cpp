#include <bits/stdc++.h>
using namespace std;

#define int long long int

int ab[555555],ac[555555];
int bc[555555],cb[555555];

void solve(){
	int n, p, q, r, x, y, z;
	int ans, s;
	
	cin >> n >> p >> q >> r;
	for(int i = 0; i < n; ++i){
		cin >> x >> y >> z;
		ab[x] = max(ab[x], y);
		ac[x] = max(ac[x], z);
		bc[y] = max(bc[y], z);
		cb[z] = max(cb[z], y);
	}
	
	for(int i = p; i > 0; --i){
		ab[i] = max(ab[i], ab[i + 1]);
		ac[i] = max(ac[i], ac[i + 1]);
	}
	
	for(int i = q; i > 0; --i)
		bc[i] = max(bc[i], bc[i + 1]);
	
	for(int i = 1; i < q + 6; ++i)
		bc[i] += bc[i - 1];
	
	for(int i = r; i > 0; --i)
		cb[i] = max(cb[i], cb[i + 1]);
	
	for(int i = 1;i < r + 6; ++i)
		cb[i] += cb[i - 1];
	
	ans = 0;
	for(int i = 1; i < p + 1; ++i){
		y = ab[i]; z = ac[i];
		
		if (y == q or z == r) continue;
		ans += (q - y) * (r - z);
		
		if (bc[y + 1] - bc[y] > z){
		 	s = bc[y] + cb[z] - y * z;
			s = bc[q + 1] - s;
			ans -= s;
		}
	}
	
	cout << ans;	
}

signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    solve();
}
