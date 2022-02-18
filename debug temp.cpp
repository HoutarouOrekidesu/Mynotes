#pragma once
#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define allr(x) rbegin(x), rend(x)
#define forn(i,a,b) for (int i=a;i<=b;i++)
#define rep(i,b) forn(i,0,b-1)
#define norf(i,b,a) for (int i=b;i>=a;i--)
#define per(i,b) norf(i,b-1,0)
#define fi first
#define se second
#define pb push_back
#define endl "\n"
#define sz(x) ((int)(x).size())
#define bg begin()
#define ed end()
#define vi vector<int>
#define smp unordered_map<int,int>
#define mp map<int,int>
#define pi pair<int,int>
#define st set<int>
#define ust unordered_set<int>
#define int long long

template<typename T>
void rep(T &container) {
	for (auto value: container) {
		cout << value << " "; 
	}
	cout << "\n";
}

template <typename T>
void d(T &&t)  { cout << t << "\n"; }
template <typename T, typename... Args>
void d(T &&t, Args &&... args)
{
    cout << t << " ";
    d(forward<Args>(args)...);
}

 // cout << pair<T1, T2>
template<typename T1, typename T2>
ostream& operator<<(ostream &ostream, const pair<T1, T2> &p) { 
	return (ostream << p.first << " " << p.second); 
}
// cout << vector<T>
template<typename T> 
ostream& operator<<(ostream &ostream, const vector<T> &c) { 
	for (auto &it : c) {
		cout << it << " "; 
	}
	return ostream; 
}
