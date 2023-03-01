const int N = 2e5 + 10;

vector<int> g[N];
int vis[N];

void bfs(int x) {
  queue<int> q;
  q.push(x);
  vis[x] = 1;
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (int u : g[v]) {
      if (!l[u]) {
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
  
vector<int> par(n + 1, 0), sz(n + 1, 0);
function<void(int)> make = [&] (int v) {
  par[v] = v;
  sz[v] = 1;
};
function<int(int)> find = [&] (int v) {
  if (par[v] == v) {
    return v;
  }
  return par[v] = find(par[v]);
};
function<void(int,int)> Union = [&] (int a, int b) {
  a = find(a);
  b = find(b);
  if (a != b) {
    if (sz[a] < sz[b]) {
      swap(a, b);
    }
    par[b] = a;
    sz[a] += sz[b];
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
