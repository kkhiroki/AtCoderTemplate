
//const ll mod = 1e9+7;
template< int mod >
struct ModInt {
    int x;
    ModInt() : x(0) {}
    ModInt(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}
    ModInt &operator+=(const ModInt &p) {
        if((x += p.x) >= mod) x -= mod;
        return *this;
    }
    ModInt &operator-=(const ModInt &p) {
        if((x += mod - p.x) >= mod) x -= mod;
        return *this;
    }
    ModInt &operator*=(const ModInt &p) {
        x = (int) (1LL * x * p.x % mod);
        return *this;
    }
    ModInt &operator/=(const ModInt &p) {
        *this *= p.inv();
        return *this;
    }
    ModInt operator-() const { return ModInt(-x); }
    ModInt operator+(const ModInt &p) const { return ModInt(*this) += p; }
    ModInt operator-(const ModInt &p) const { return ModInt(*this) -= p; }
    ModInt operator*(const ModInt &p) const { return ModInt(*this) *= p; }
    ModInt operator/(const ModInt &p) const { return ModInt(*this) /= p; }
    bool operator==(const ModInt &p) const { return x == p.x; }
    bool operator!=(const ModInt &p) const { return x != p.x; }
    
    ModInt inv() const {
        int a = x, b = mod, u = 1, v = 0, t;
        while(b > 0) {
            t = a / b;
            swap(a -= t * b, b);
            swap(u -= t * v, v);
        }
        return ModInt(u);
    }
    
    ModInt pow(int64_t n) const {
        ModInt ret(1), mul(x);
        while(n > 0) {
            if(n & 1) ret *= mul;
            mul *= mul;
            n >>= 1;
        }
        return ret;
    }
    
    friend ostream &operator<<(ostream &os, const ModInt &p) {
        return os << p.x;
    }
    
    friend istream &operator>>(istream &is, ModInt &a) {
        int64_t t;
        is >> t;
        a = ModInt< mod >(t);
        return (is);
    }
    
    static int get_mod() { return mod; }
};

using mint = ModInt<mod>;
typedef vector<mint> vm;
typedef vector<vm> vvm;
typedef vector<vvm> vvvm;

const ll size = 30300;
mint fact[size], finv[size];

mint nCk(ll n, ll k){
    if(n < k) return 0;
    return fact[n]*finv[k]*finv[n-k];
}

void prepare(){
    fact[0] = 1;
    rep(i, size-1) fact[i+1] = fact[i]*mint(i+1);
    finv[size-1] = fact[size-1].inv();
    for (ll i = size-1; i > 0; i--) {
        finv[i-1] = finv[i]*mint(i);
    }
}

