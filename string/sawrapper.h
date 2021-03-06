// tを完全に含む範囲を出力,O(|t|logn)
template<class Str>
array<int, 2> find(SA<Str> &sa, string t) {
    int n = (int)sa.s.size(), m = (int)t.size();
    array<int, 2> ans;
    int l, r;

    l = 0, r = n+1;
    while (r-l > 1) {
        int md = (l+r)/2;
        if (sa.s.compare(sa.sa[md], m, t) < 0) {
            l = md;
        } else {
            r = md;
        }
    }
    ans[0] = r;

    l = 0, r = n+1;
    while (r-l > 1) {
        int md = (l+r)/2;
        if (sa.s.compare(sa.sa[md], m, t) <= 0) {
            l = md;
        } else {
            r = md;
        }
    }
    ans[1] = r;
    return ans;
}

template<class Str>
int cp_len(SA<Str> sa, SparseTable<int> &st, int l, int r) {
    if (l == r) return int(sa.s.size()) - l;
    int li = sa.rsa[l], ri = sa.rsa[r];
    return st.query(min(li, ri), max(li, ri), TEN(9));
}
