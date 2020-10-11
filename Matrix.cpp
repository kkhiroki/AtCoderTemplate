struct Matrix {
    vvl val;
    Matrix(ll n, ll m, ll x = 0) : val(n, vl(m, x)) {}
    void init(ll n, ll m, ll x = 0) {val.assign(n, vl(m, x));}
    ll size() const {return val.size();}
    inline vector<ll>& operator [] (ll i) {return val[i];}
};

Matrix operator * (Matrix A, Matrix B) {
    ll mat_size = A.size();
    Matrix R(mat_size, mat_size);
    rep(i, mat_size) rep(j, mat_size){
        A[i][j] %= mod; B[i][j] %= mod;
    }
    ll modsq = 4*mod*mod;
    rep(i, mat_size) rep(j, mat_size) rep(k, mat_size){
        R[i][j] += A[i][k] * B[k][j];
        if(R[i][j]>modsq) R[i][j] %= mod;
    }
    rep(i, mat_size) rep(j, mat_size) R[i][j] %= mod;
    return R;
}

Matrix pow(Matrix A, ll n) {
    Matrix R(A.size(), A.size());
    rep(i, A.size()) R[i][i] = 1;
    while (n > 0) {
        if (n & 1) R = R * A;
        A = A * A;
        n >>= 1;
    }
    return R;
}
