//Whole package to deal with long nCrs
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
  return fac[x] * powmod(fac[y] * fac[x-y], mod - 2) % mod;
};


// Important problem related to how to do problems concerned with binomail roots

https://codeforces.com/contest/1569/problem/C
