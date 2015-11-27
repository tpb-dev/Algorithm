/**
 * Dijkstra法により最短距離を求める
 *
 * template引数のint Vは頂点数
 */
template<int V, ll MD>
struct DijkstraComb {
    typedef int T; /// 辺の距離の型
    const int INF = 1e9;
    typedef pair<T, int> P;
    vector<P> g[V];
    /// 辺のクリア
    void init() {
        for (int i = 0; i < V; i++) {
            g[i].clear();
        }
    }
    /// 辺の追加
    void add(int from, int to, T dist) {
        g[from].push_back(P(dist, to));
    }
    T res[V]; /// execを行うと、これに最短距離が入る 
    ll comb[V];
    void exec(int s) {
        fill_n(res, V, INF);
        fill_n(comb, V, 0);
        priority_queue<P, vector<P>, greater<P>> q;
        q.push(P(0, s));
        res[s] = 0;
        comb[s] = 1;
        while (!q.empty()) {
            P p = q.top(); q.pop();
            if (res[p.second] < p.first) continue;
            for (P e: g[p.second]) {
                if (p.first+e.first < res[e.second]) {
                    res[e.second] = p.first+e.first;
                    comb[e.second] = comb[p.second]; 
                    q.push(P(e.first+p.first, e.second));
                } else if (p.first+e.first == res[e.second]) {
                    comb[e.second] += comb[p.second];
                    comb[e.second] %= MD;
                }
            }
        }
        return;
    }
};
