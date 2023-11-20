#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        std::vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        if (n < 3) {
            cout << n << '\n';
            for (auto i : a) {
                cout << i << ' ';
            }
            cout << '\n' << 0 << '\n' << '\n';
            continue;
        }
        int min_val = *min_element(a.begin(), a.end());
        auto check = [&](int pa, int pb) -> bool {
            std::vector<pair<int, int>> va, vb;
            int da = a[pb] - a[pa];
            std::vector<int> vis(n, false);
            va.push_back({a[pa], pa});
            vis[pa] = true;
            for (int i = pa + 1, j = va.front().first + da; i < n; i++) {
                if (a[i] == j) {
                    va.push_back({j, i});
                    vis[i] = true;
                    j += da;
                }
            }
            std::map<int, int> dfcnt;
            std::set<pair<int, int>> s;
            for (int i = 0; i < n; i++) {
                if (!vis[i]) {
                    if (!s.empty()) {
                        dfcnt[a[i] - (s.rbegin()->second)]++;
                    }
                    s.insert({i, a[i]});
                }
            }
            while (!va.empty()) {
                if (dfcnt.size() <= 1) {
                    break;
                }
                auto [val, pos] = va.back();
                va.pop_back();
                auto rb = s.lower_bound({pos, numeric_limits<int>::min()});
                auto lb = s.end();
                if (rb != s.begin()) {
                    lb = prev(rb);
                    auto [lp, lv] = *lb;
                    dfcnt[val - lv]++;
                }
                if (rb != s.end()) {
                    auto [rp, rv] = *rb;
                    if (lb != s.end()) {
                        auto [lp, lv] = *lb;
                        dfcnt[rv - lv]--;
                        if (dfcnt[rv - lv] == 0) {
                            dfcnt.erase(rv - lv);
                        }
                    }
                    dfcnt[rv - val]++;
                }
                s.insert({pos, val});
                if (va.empty() and dfcnt.size() > 1) {
                    return false;
                }
            }
            cout << va.size() << '\n';
            for (auto i : va) {
                cout << i.first << ' ';
            }
            cout << '\n';
            cout << s.size() << '\n';
            for (auto i : s) {
                cout << i.second << ' ';
            }
            cout << '\n';
            return true;
        };
        if (check(0, 1)) {
        } else if (check(0, 2)) {
        } else if (check(1, 2)) {
        } else {
            cout << "-1";
            cout << '\n';
        }
    }
    return 0;
}
