string del(string s, int i) {
    if (i == 0) return s.substr(1, s.size()-1);
    if (i == s.size()-1) return s.substr(0, s.size()-1);
    string m = s.substr(0, i),
    n = s.substr(i+1, s.size()-i-1);
    return m+n;
}

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




