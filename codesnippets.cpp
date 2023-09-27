// merge segments
vector<pair<int,int>> a(n);
for (int i = 0; i < n; i++) {
    cin >> a[i].first;
}
for (int i = 0; i < n; i++) {
    cin >> a[i].second;
}
sort(a.begin(), a.end());
vector<pair<int,int>> p;
int l = a[0].first, r = a[0].second;
for (auto [f, s]: a) {
    if (f >= l && f <= r) r = max(r, s);
    else {
        p.push_back({l, r});
        l = f, r = s;
    }
}
p.push_back({l, r});


// level order traversal bfs
const int N = 2e5 + 10;

vector<int> g[N];
int vis[N];
vector<int> l(n);

void bfs(int x) {
  queue<int> q;
  q.push(x);
  vis[x] = 1;
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (int u : g[v]) {
      if (!vis[u]) {
        q.push(u);
        vis[u] = 1;
        l[u] = l[v] + 1;
      }
    }
  }
  
  
  // 4 * size of the maximum possible length of array
int t[800010];

void build(vector<int>& a, int v, int tl, int tr) {
  if (tl == tr) t[v] = a[tl]; 
  else {
    int tm = (tl + tr) / 2;
    build(a, v * 2, tl, tm);
    build(a, v * 2 + 1, tm + 1, tr);
    t[v] = max(t[v * 2], t[v * 2 + 1]);
  }
}

int getMax(int v, int tl, int tr, int l, int r) {
  if (l > r) return 0;
  if (l == tl && r == tr) return t[v];
  int tm = (tl + tr) / 2;
  return max(getMax(v * 2, tl, tm, l, min(r, tm)), getMax(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
}


int z = n;
while (__builtin_popcount(z) != 1) {
  b.push_back(0);
  z += 1;
}
build(b, 1, 0, z - 1);
getMax(1, 0, z - 1, i, j);

// dsu  
wmod = [&] (long long a, long long b) {
    long long res = 1;
    a %= mod;
    for(; b; b >>= 1) {
        if (b & 1) {
            res = (res * a) % mod;
        }
         a = (a * a) % mod;
     }
     return res;
};
auto binom = [&] (int x, int y) {
    return fac[x] * powmod(fac[x - y], mod - 2) % mod;
};
 
 
// DSU
 
struct DSU {
    vector<int> s, p;
    DSU() {}
    DSU(int n) {
        init(n);
    }
    void init(int n) {
        p.resize(n);
        iota(p.begin(), p.end(), 0);
        s.assign(n, 1);
    }
    int find(int v) {
        if (p[v] == v) return v;
        return p[v] = find(p[v]);
    }
    bool same(int a, int b) {
        return find(a) == find(b);
    }
    void merge(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return;
        if (s[a] < s[b]) {
            swap(a, b);
        }
        p[b] = a;
        s[a] += s[b];
    }
};
  
// nCr
  
int mod = 998244353;
int fac[1000010];
fac[0] = 1;
for (int i = 1; i < 1000001; i++) {
  fac[i] = (fac[i - 1] * i) % mod;
}
auto powmod = [&] (long long a, long long b) {
  long long res = 1;
  a %= mod;
  for(; b; b >>= 1) {
    if (b & 1) {
      res = (res * a) % mod;
    }
    a = (a * a) % mod;
  }
  return res;
};
auto binom = [&] (int x, int y) {
  return fac[x] * powmod(fac[x - y], mod - 2) % mod;
};
  
  
int ncr[66][66];
for(int i = 0; i <= 60; i++) ncr[i][0] = 1;
  for(int i = 1; i <= 60; i++) {
    for(int j = 1; j <= i; j++) ncr[i][j] = (ncr[i - 1][j] + ncr[i - 1][j - 1]) % MOD;
}
  
string del(string s, int i) {
    if (i == 0) return s.substr(1, s.size()-1);
    if (i == s.size()-1) return s.substr(0, s.size()-1);
    string m = s.substr(0, i),
    n = s.substr(i+1, s.size()-i-1);
    return m+n;
}
