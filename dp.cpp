// state of dp are the parameters that changes during dp

//bottom up approach

int dp[100010];

void solve() {
  int n;
  cin >> n;
  dp[1] = 1;
  for (int i = 2; i <= n; i++) {
    dp[i] = dp[i-1] + dp[i-2];
  }
  cout << dp[n];
}

//top down approach

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



//frog 1
https://atcoder.jp/contests/dp/tasks/dp_a
//top down 
https://atcoder.jp/contests/dp/submissions/28425981
//bottom up
https://atcoder.jp/contests/dp/submissions/28431002
https://atcoder.jp/contests/dp/submissions/29220505

//frog 2
https://atcoder.jp/contests/dp/tasks/dp_b

//C- Vacation
https://atcoder.jp/contests/dp/tasks/dp_c
// top down
https://atcoder.jp/contests/dp/submissions/29623396
//Bottom up
https://atcoder.jp/contests/dp/submissions/29623826

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

//coin change 1
https://leetcode.com/problems/coin-change/
//top down approach
https://leetcode.com/submissions/detail/639674893/

//Dice combinations (here order matters , so we just use the normal recursion)
https://cses.fi/problemset/task/1633

//coin change 2 (here order doesn't matter, so we just need to go by index and state of dp becomes 2)
https://leetcode.com/problems/coin-change-2/

//knapsack 1
https://atcoder.jp/contests/dp/tasks/dp_d

//rod cutting unbounded knapsack
https://practice.geeksforgeeks.org/problems/rod-cutting0840/1

//problems based on subsetsum
https://leetcode.com/problems/partition-equal-subset-sum/
