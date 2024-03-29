map<ll, ll> prime_factor(int64_t n) {
    map<ll, ll> ret;
    for(ll i = 2; i * i <= n; i++) {
        while(n % i == 0) {
            ret[i]++;
            n /= i;
        }
    }
    if(n != 1) ret[n] = 1;
    return ret;
}

vector<bool> prime_table(ll n) {
    vector<bool> prime(n + 1, true);
    if(n >= 0) prime[0] = false;
    if(n >= 1) prime[1] = false;
    for(ll i = 2; i * i <= n; i++) {
        if(!prime[i]) continue;
        for(ll j = i + i; j <= n; j += i) {
            prime[j] = false;
        }
    }
    return prime;
}

vector<ll> prime_table(ll n) {
    vector<ll> prime(n + 1, -1);

    if(n >= 0) prime[0] = 0;
    if(n >= 1) prime[1] = 1;
    
    for(ll i = 2; i <= n; i++) {
        if(prime[i] != -1) continue;

        prime[i] = i;
        for(ll j = i + i; j <= n; j += i) {
            prime[j] = i;
        }
    }
    return prime;
}

