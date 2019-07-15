
const ll size = 300300;
ll fact[size], finv[size];

ll nCk(ll n, ll k){
    if(n < k) return 0;
    return fact[n] * (finv[k]*finv[n-k]%mod) %mod;
}

ll modpow(ll x, ll n){
    ll res = 1;
    while(n > 0){
        if(n & 1) res = res * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return res;
}

ll inv(ll x){
    return modpow(x, mod-2);
}

void prepare(){
    fact[0] = 1;
    rep(i, size-1) fact[i+1] = fact[i]*(i+1)%mod;
    finv[size-1] = inv(fact[size-1]);
    for (ll i = size-1; i > 0; i--) {
        finv[i-1] = finv[i]*i%mod;
    }
}

