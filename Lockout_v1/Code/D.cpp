#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

template<typename T, class C = std::less<T>>
using ordered_set = tree<T, null_type, C,
      rb_tree_tag, tree_order_statistics_node_update>; 

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;

    std::vector<i64> a(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
        if (i)
            a[i] += a[i - 1];
    }

    ordered_set<i64, std::less_equal<i64>> pbds;
    pbds.insert(0);
    i64 ans = 0;
    for (int i = 0; i < n; i++)
    {
        pbds.insert(a[i]);
        ans += pbds.order_of_key(a[i]);
    }

    std::cout << ans;
    
    return 0;
}