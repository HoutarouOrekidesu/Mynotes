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
