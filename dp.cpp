// state of dp are the parameters that changes during dp

//bottom up approach (iterative approach)

int dp[100010];

there are two type of bottom up dp
1) Pull dp: answers are pulled from previous answers that are already calculated
2) Push dp: here we are concerning that our current postion has what contribution to the other indices
            f(i+1) += f(i); f(i+2) += f(i);
State (what info we are storing/carring), 
transisiton (way to find current answers from previous answers f(x) = f(x-1) + f(x-2)), 
base cases

void solve() {
    int n;
    cin >> n;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    cout << dp[n];
}

//top down approach (recursive)

int dp[100010];

int fib(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (dp[n] != -1) return dp[n];
    //memoise
    return dp[n] = fib(n-1) + fib(n-2);
}

void solve() {
    memset(dp, -1, sizeof(dp));
    int n;
    cin >> n;
    cout << fib(n);
}



frog 1
https://atcoder.jp/contests/dp/tasks/dp_a
top down 
https://atcoder.jp/contests/dp/submissions/28425981
bottom up
https://atcoder.jp/contests/dp/submissions/28431002
https://atcoder.jp/contests/dp/submissions/29220505

frog 2
https://atcoder.jp/contests/dp/tasks/dp_b
top down
https://atcoder.jp/contests/dp/submissions/28426139
Bottom up
https://atcoder.jp/contests/dp/submissions/28431413
https://atcoder.jp/contests/dp/submissions/29220622

C- Vacation
https://atcoder.jp/contests/dp/tasks/dp_c
top down
https://atcoder.jp/contests/dp/submissions/29623396
Bottom up
https://atcoder.jp/contests/dp/submissions/29623826

Maximum subarray sum

bottom up

Kadane's algorithm 
    
int best = 0, sum = 0;
for (int k = 0; k < n; k++) {
    sum = max(array[k],sum+array[k]);
    best = max(best,sum);
}
cout << best << "\n";


#include <bits/stdc++.h>
using namespace std;
#define int long long 

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int b[n];
    b[0] = a[0];
    int ans = -1*1e9;
    for (int i = 1; i < n; i++) {
        b[i] = max(a[i], a[i]+b[i-1]);
    }
    for (int i = 0; i < n; i++) {
        ans = max(ans, b[i]);
    }
    cout << ans << "\n";
    return 0;
}

top down

#include <bits/stdc++.h>
using namespace std;
#define int long long 
 
int dp[1000010];
 
int f(vector<int> &a, int i) {
    if (i == 0) return dp[0] = a[0];
    if (dp[i] != -1) return dp[i];
    int mx = a[i];
    mx = max(mx, a[i]+f(a, i-1));
    return dp[i] = mx;
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
 
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    memset(dp, -1, sizeof(dp));
    f(a, n-1);
    int ans = -1e9;
    for (int i = 0; i < n; i++) {
        ans = max(ans, dp[i]);
    }
    cout << ans << "\n";
    return 0;
}

//longest increasing subsequence 

#include <bits/stdc++.h>
using namespace std;

int n, dp[100];
vector<int> a(100);

int lis(int i) {
    if (dp[i] != -1) return dp[i];
    int ans = 1;
    for (int j = 0; j < i; j++) {
        if (a[i] > a[j]) ans = max(ans, lis(j) + 1);
    }
    return dp[i] = ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    memset(dp, -1, sizeof(dp));
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int flg = 0;
    for (int i = 0; i < n; i++) {
        flg = max(flg, lis(i));
    }
    cout << flg;
    return 0;
}
=======================================================================================================================================================================
//coin change 1
https://leetcode.com/problems/coin-change/
//top down approach
https://leetcode.com/submissions/detail/639674893/

case of permutations count 
//Dice combinations (here order matters , so we just use the normal recursion)
https://cses.fi/problemset/task/1633
top down 
https://cses.fi/paste/5d3e0bbc951062d1369a1a/
bottom up
https://cses.fi/paste/e9eb7f073ddebb0d36db7d/

case of combinations count
//coin change 2 (here order doesn't matter, so we just need to go by index and state of dp becomes 2)
https://leetcode.com/problems/coin-change-2/
top down
https://leetcode.com/submissions/detail/639769695/
bottom up
https://leetcode.com/submissions/detail/648206011/

=========================================================================================================================================================================
//knapsack 1
https://atcoder.jp/contests/dp/tasks/dp_d
top down approach
https://atcoder.jp/contests/dp/submissions/29245880
bottom up approach
https://atcoder.jp/contests/dp/submissions/29643951

//rod cutting unbounded knapsack
https://practice.geeksforgeeks.org/problems/rod-cutting0840/1

problems based on subsetsum
https://leetcode.com/problems/partition-equal-subset-sum/
top down approach
https://leetcode.com/submissions/detail/640431214/
bottom up approach
https://leetcode.com/submissions/detail/648681941/

==========================================================================================================================

Longest common subsequence 
https://leetcode.com/problems/longest-common-subsequence/
top down approach
https://leetcode.com/submissions/detail/679612921/
