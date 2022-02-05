//bfs

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
vector<int> g[N];
vector<bool> vis(N, false);
int level[N];

void bfs(int source) {
	queue<int> q;
	q.push(source);
	vis[source] = 1;
	while (!q.empty()) {
		int cur_v = q.front();
		q.pop();
		for (int child : g[cur_v]) {
			if (!vis[child]) {
				q.push(child);
				vis[child] = 1;
				level[child] = level[cur_v] + 1;
			}
		}
	}
}

//https://www.spoj.com/problems/NAKANJ/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
const int inf = 1e9+7;
int vis[8][8], level[8][8];

int getX(string s) {
	return s[0] - 'a';
}

int getY(string s) {
	return s[1] - '1';
}

bool isvalid(int x, int y) {
	return x >= 0 && x < 8 && y >= 0 && y < 8;
}

vector<pair<int,int>> movements = {
	{-1, 2}, {1, 2}, {-1, -2}, {1, -2}, 
	{2, -1}, {2, 1}, {-2, -1}, {-2, 1} 
};

int bfs(string source, string dest) {
	int sourceX = getY(source);
	int sourceY = getY(source);
	int destX = getX(dest);
	int destY = getY(dest);
	queue<pair<int,int>> q;
	q.push({sourceX, sourceY});
	vis[sourceX][sourceY] = 1;
	level[sourceX][sourceY] = 0;

	while (!q.empty()) {
		pair<int,int> v = q.front();
		int x = v.first, y = v.second;
		q.pop();
		for (auto movement : movements) {
			int childX = movement.first + x;
			int childY = movement.second + y;
			if (!isvalid(childX, childY)) continue;
			if (!vis[childX][childY]) {
				q.push({childX, childY});
				vis[childX][childY] = 1;
				level[childX][childY] = level[x][y] + 1;
			}
		}
		if (level[destX][destY] != inf) break;
	}
	return level[destX][destY];
}

void reset() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			level[i][j] = inf;
			vis[i][j] = 0;
		}
	}
}

signed main()
{
	ios::sync_with_stdio(false); 
	cin.tie(nullptr);
	#ifndef ONLINE_JUDGE
	freopen("C:/Users/DSC/Desktop/code sublime/inputf.in", "r", stdin);
	#endif
	
	int _;
	cin >> _;
	for (_; _; _--) {
		reset();
		string s1, s2;
		cin >> s1 >> s2;
		cout << bfs(s1, s2) << "\n";
	}
	return 0;
}

