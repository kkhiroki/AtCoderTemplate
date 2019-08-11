struct UnionFind{
    vl par;
    vl rank;
    map<ll, ll> size;
    UnionFind(ll N) : par(N, 0), rank(N, 0){
        for(ll i = 0; i < N; i++){
            par[i] = i; size[i] = 1;
        }
    }
    
    ll root(ll x){
        if(par[x] == x) return x;
        else{
            par[x] = root(par[x]); // compression
            return par[x];
        }
    }
    
    void unite(ll x, ll y){
        ll rx = root(x); ll ry = root(y);
        if(rx == ry) return;
        if(rank[rx] < rank[ry]) swap(rx, ry);
        if(rank[rx] == rank[ry]) ++rank[rx];
        par[ry] = rx;
        if(rx != ry) size[rx] = size[rx] + size[ry];
        else{
            size[rx] = max(size[rx], size[ry]);
        }
    }
    
    ll get_size(ll x){
        return size[root(x)];
    }
    
    bool same(ll x, ll y){
        return root(x) == root(y);
    }
};

