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
