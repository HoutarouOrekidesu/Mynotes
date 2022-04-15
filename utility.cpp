string del(string s, int i) {
    if (i == 0) return s.substr(1, s.size()-1);
    if (i == s.size()-1) return s.substr(0, s.size()-1);
    string m = s.substr(0, i),
    n = s.substr(i+1, s.size()-i-1);
    return m+n;
}
