// Segment Tree

int f(int node, int node_low, int node_high, int query_low, int query_high) {
    if (query_low <= node_low && node_high <= query_high) {
        return tree[node];
    }
    if (node_high < query_low || query_high < node_low) {
        return 0;
    }

    int last_in_first = (node_high + node_low)/2;

    return f(2*node, node_low, last_in_first, query_low, query_high) + 
    f(2*node + 1, last_in_first + 1, node_high, query_low, query_high);
}

problem 

//general segment tree
https://cses.fi/paste/6277b99f0a975a6d3b5665/

//changing certain element and adressing the range queries
https://cses.fi/paste/20f26b201eae8e073b575d/

//recursive change function
https://cses.fi/paste/b3ee1b29eeb579313b64de/


// Update and find in one (not best in terms of time complexity, using separate function is recommended)

int f(int node, int node_low, int node_high, int query_low, int query_high, int v) {
    if (query_low <= node_low && node_high <= query_high) {
        if (v != -1) tree[node] = v;
        return tree[node];
    }
    if (node_high < query_low || query_high < node_low) {
        return 0;
    }
 
    int last_in_first = (node_high + node_low)/2;
 
    int sum = f(2*node, node_low, last_in_first, query_low, query_high, v) + 
    f(2*node + 1, last_in_first + 1, node_high, query_low, query_high, v);
 
    tree[node] = tree[2*node] + tree[2*node + 1];
 
    return sum;
}

//dsu
const int N = 

int par[N], sz[N];

void make (int v) {
    par[v] = v;
    sz[v] = 1;
}

int find (int v) {
    if (par[v] == v) return v;
    return par[v] = find(par[v]);
}

void Union (int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) {
        if (sz[a] < sz[b]) swap(a, b);
        par[b] = a;
        sz[a] += sz[b];
    }
}

// Checker function

bool Union (int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return false;
    if (sz[a] < sz[b]) swap(a, b);
    par[b] = a;
    sz[a] += sz[b];
    return true;
}

vector<int> fen(n + 1);
auto add = [&] (int i, int x) {
  for (; i <= n; i += i & -i) {
    fen[i] += x;
  }
};
auto sum = [&] (int i) {
  int ans = 0;
  for (; i > 0; i -= i & -i) {
    ans += fen[i];
  }
  return ans;
};
