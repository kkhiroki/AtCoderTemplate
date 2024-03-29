template<typename T>
struct BinaryIndexedTree{
    vector<T> data;
    BinaryIndexedTree(ll sz){
        data.assign(++sz, 0);
    }
    
    T sum(ll k){
        T ret = 0;
        for(++k; k>0; k -= k&-k) ret += data[k];
        return ret;
    }
    
    void add(ll k, T x){
        for(++k; k < data.size(); k += k&-k) data[k] += x;
    }
};
