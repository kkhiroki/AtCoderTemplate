struct UnionFind{
    vl par;
    vl rank;
    vl size;
    UnionFind(ll N) : par(N, 0), rank(N, 0), size(N, 1){
        for(ll i = 0; i < N; i++){
            par[i] = i;
        }
    }
    
    ll root(ll x){
        if(par[x] == x) return x;
        else{
            par[x] = root(par[x]); // compression
            return par[x];
        }
    }
    
    void merge(ll x, ll y){
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
    
    ll getSize(ll x){
        return size[root(x)];
    }
    
    bool same(ll x, ll y){
        return root(x) == root(y);
    }
};

