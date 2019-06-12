#include <vector>
#include <iostream>
#include <cmath>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <fstream>
#include <unistd.h>
#include <string>
#include <numeric>
#include <queue>
#include <deque>
#include <sstream>
#include <iomanip>
#include <set>
#include <stack>
#include <cassert>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vvl> vvvl;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
typedef vector<vvb> vvvb;
typedef vector<vvvb> vvvvb;
typedef vector<string> vs;
typedef vector<vs> vvs;
typedef vector<vvs> vvvs;
typedef vector<char> vc;
typedef vector<vector<char>> vvc;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvd> vvvd;
typedef pair<int, int> P;
typedef pair<ll, ll> PL;
typedef vector<P> vp;
typedef vector<PL> vpl;
typedef vector<vector<P>> vvp;
typedef vector<vector<PL>> vvpl;
const int INF = 1001001001;
const ll LINF = 1e17;
const double pi = 3.1415926535897932;
const string endstr = "\n";
#define FOR(i, a, b) for(ll i = (a); i < b; i++)
#define RFOR(i, a, b) for(ll i = (a); i > b; i--)
#define REP(i, n) for(ll i = 0; i < n; i++)
#define RREP(i, n) for(ll i = n-1; i > -1; i--)
#define FORMAP(it, m) for(auto it = m.begin(); it != m.end(); it++)
#define ff first
#define ss second
#define pb push_back
#define epb emplace_back

template <typename T>
T gcd(T a, T b) {
    return (a == 0) ? b : gcd(b%a, a);
}
template <typename T>
T lcm(T a, T b) {
    return a / gcd(a, b) * b;
}

bool p_comp_fs(const PL p1, const PL p2){ return p1.first < p2.first;};
bool p_comp_fg(const PL p1, const PL p2){ return p1.first > p2.first;};
bool p_comp_ss(const PL p1, const PL p2){ return p1.second < p2.second;};
bool p_comp_sg(const PL p1, const PL p2){ return p1.second > p2.second;};
template <typename T>
vector<T> uniquen(vector<T> vec){
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    return vec;
}

const ll mod = 1e9+7;

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
    REP(i, mat_size) REP(j, mat_size){
        A[i][j] %= mod; B[i][j] %= mod;
    }
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

ll N, M;

void prepare(Matrix& mat){
    REP(i, M) REP(j, M){
        if(i == 0){
            if(j == 0 || j == M-1) mat[i][j] = 1;
        }
        else if(i == j+1){
            mat[i][j] = 1;
        }
    }
}
int main(){
    // debug start //
    ifstream file("/Users/hiroki/AtCoder/in.txt");
    if(file.is_open())
        cin.rdbuf(file.rdbuf());
    // debug end //
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M;
    auto mat = Matrix(M, M);
    prepare(mat);
    auto matN = pow(mat, N-(M-1));
    
    ll ans = 0;
    REP(i, M) ans += matN[0][i];
    cout << ans%mod << endl;
    return 0;

}
