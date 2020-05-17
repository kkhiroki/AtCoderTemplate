template <typename X, typename M>
class LazySegmentTree{
private:
    using FX = std::function<X(X, X)>; // query for data
    using FA = std::function<X(X, M)>; // update data by lazy value
    using FM = std::function<M(M, M)>; // update lazy
    using FP = std::function<M(M, size_t)>; // calculate a lazy value for a segment
    ll sz;
    vector<X> data;
    vector<M> lazy;
    FX fx;
    FA fa;
    FM fm;
    FP fp;
    const X ex; // unit for X
    const M em; // unit for M

public:
    LazySegmentTree(const vector<X>& v, FX fx, FA fa, FM fm, FP fp, X ex, M em)
    : fx(fx), fa(fa), fm(fm), fp(fp), ex(ex), em(em){
        
        this->sz = 1;
        while(this->sz < v.size()) this->sz = (this->sz<<1);
        
        this->data = std::vector<X>(2*this->sz - 1, ex);
        this->lazy = std::vector<M>(2*this->sz - 1, em);
        
        rep(i, v.size()) this->data[i+ sz-1] = v.at(i);
        for(ll k = sz-2; k >= 0; k--){
            this->data[k] = fx(data[2*k+1], data[2*k+2]);
        }
    }
    
    void eval(ll k, size_t len){
        if(lazy[k] == em) return;
        if(k < sz-1){
            lazy[2*k+1] = fm(lazy[2*k+1], lazy[k]);
            lazy[2*k+2] = fm(lazy[2*k+2], lazy[k]);
        }
        data[k] = fa(data[k], fp(lazy[k], len));
        lazy[k] = em;
    }
    
    
    void update(ll ql, ll qr, M val, ll k = 0, ll sl = 0, ll sr = -1){
        if(sr < 0) sr = sz;
        
        eval(k, sr-sl);
        if(qr <= sl || sr <= ql) return;
        else if(ql <= sl && sr <= qr){
            lazy[k] = fm(lazy[k], val);
            eval(k, sr-sl);
        }
        else{
            update(ql, qr, val, 2*k+1, sl, (sl+sr)/2);
            update(ql, qr, val, 2*k+2, (sl+sr)/2, sr);
            data[k] = fx(data[2*k+1], data[2*k+2]);
        }
    }
    
    X query(ll ql, ll qr, ll k = 0, ll sl = 0, ll sr = -1){
        if(sr < 0) sr = sz;
        eval(k, sr-sl);
        
        if(qr <= sl || sr <= ql) return ex;
        
        if(ql <= sl && sr <= qr) return data[k];
        else{
            X lval = query(ql, qr, 2*k+1, sl, (sl+sr)/2);
            X rval = query(ql, qr, 2*k+2, (sl+sr)/2, sr);
            return fx(lval, rval);
        }
    }
    
    X operator[](ll idx) const{
        return this->data.at(idx + sz-1);
    }
};
