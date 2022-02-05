#include <bits/stdc++.h>
using namespace std;
#define int long long int

void solve() {
    int hc, dc, hm, dm;
    cin >> hc >> dc >> hm >> dm;
    int k, w, a;
    cin >> k >> w >> a;
    for (int i = 0; i <= k; i++) {
        int c = hc + (k-i)*a;
        int d = dc + i*w;
        int x = (c + dm - 1)/dm;
        int y = (hm + d - 1)/d;
        if (x >= y) {
            cout << "YES" << "\n";
            return;
        }
    }
    cout << "NO" << "\n"; 
}

signed main()
{
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("inputf.in", "r", stdin);
    #endif
    
    int _;
    cin >> _;
    for (_; _; _--) {
        solve();
    }
    return 0;
}
