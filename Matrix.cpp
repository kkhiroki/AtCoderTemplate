//
//  Matrix.cpp
//  AtCoderDev
//
//  Created by Hiroki Kojima on 2019/06/10.
//  Copyright © 2019 Hiroki Kojima. All rights reserved.
//
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
    ll modsq = 4*mod*mod;
    REP(i, mat_size) REP(j, mat_size) REP(k, mat_size){
        R[i][j] += A[i][k] * B[k][j];
        if(R[i][j]>modsq) R[i][j] %= mod;
    }
    REP(i, mat_size) REP(j, mat_size) R[i][j] %= mod;
    return R;
}

Matrix pow(Matrix A, ll n) {
    Matrix R(A.size(), A.size());
    REP(i, A.size()) R[i][i] = 1;
    while (n > 0) {
        if (n & 1) R = R * A;
        A = A * A;
        n >>= 1;
    }
    return R;
}
#include <stdio.h>
