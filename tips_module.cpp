//
//  tips_module.cpp
//  AtCoderDev
//
//  Created by Hiroki Kojima on 2019/04/29.
//  Copyright © 2019 Hiroki Kojima. All rights reserved.
//

#include <stdio.h>

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

