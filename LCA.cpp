const ll size = 100100;
const ll MX_LOG = 20;
vl G[size];
ll par[MX_LOG][size];
ll depth[size];

void dfs(ll v, ll p, ll d){
    depth[v] = d;
    par[0][v] = p;
    for(ll c : G[v]){
        if(c == p) continue;
        dfs(c, v, d+1);
    }
}

void init(ll root){
    dfs(root, -1, 0);
    rep(k, MX_LOG-1) rep(v, size){
        if(par[k][v] < 0) par[k+1][v] = -1;
        else par[k+1][v] = par[k][par[k][v]];
    }
}

ll lca(ll u, ll v){
    if(depth[u] > depth[v]) swap(u, v);
    ll dd = depth[v] - depth[u];
    rep(k, MX_LOG) {
        if(dd >> k & 1) v = par[k][v];
    }
    if(u == v) return u;
    
    for(ll k = MX_LOG-1; k >= 0; k--){
        if(par[k][u] != par[k][v]){
            u = par[k][u];
            v = par[k][v];
        }
    }
    return par[0][u];
}
