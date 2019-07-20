struct edge{ll to, cap, rev;};
const ll size = 200200;
vector<edge> G[size];
bool used[size];

void add_edge(ll from, ll to, ll cap){
    G[from].pb({to, cap, (ll)(G[to].size())});
    G[to].pb({from, 0, (ll)(G[from].size()-1)});
}

ll dfs(ll v, ll t, ll f){
    used[v] = true;
    if(v == t) return f;
    for(auto& e : G[v]){
        if(!used[e.to] && e.cap > 0){
            ll d = dfs(e.to, t, min(f, e.cap));
            if(d > 0){
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

ll max_flow(ll s, ll t){
    ll res = 0;
    while(true){
        memset(used, 0, sizeof(used));
        ll f = dfs(s, t, LINF);
        if(f == 0) break;
        res += f;
    }
    return res;
}
