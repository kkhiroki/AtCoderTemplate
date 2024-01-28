#include <vector>
#include <iostream>
#include <cmath>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <fstream>
#include <unistd.h>
#include <string.h>
#include <string>
#include <numeric>
#include <queue>
#include <deque>
#include <sstream>
#include <iomanip>
#include <set>
#include <stack>
#include <cassert>
#include <functional>
#include <random>
#include <bitset>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vvl> vvvl;
typedef vector<vvvl> vvvvl;
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
typedef vector<long double> vld;
typedef vector<vld> vvld;
typedef unordered_map<ll, ll> uii;
typedef unordered_map<ll, ll> uuii;
typedef unordered_map<ll, ll> uuuii;
typedef pair<ll, ll> PL;
typedef vector<PL> vpl;
typedef vector<vector<PL>> vvpl;
typedef vector<vvpl> vvvpl;
typedef pair<ll, PL> TL;
typedef vector<TL> vtl;
typedef vector<vtl> vvtl;
typedef bitset<64> bs;
const ll LINF = 1e17;
const long double pi = 3.1415926535897932;
const string endstr = "\n";
#define FOR(i, a, b) for(ll i = (a); i < b; i++)
#define RFOR(i, a, b) for(ll i = (a); i > b; i--)
#define rep(i, n) for(ll i = 0; i < n; i++)
#define rrep(i, n) for(ll i = n-1; i > -1; i--)
#define FORMAP(it, m) for(auto it = m.begin(); it != m.end(); it++)
#define ff first
#define ss second
#define pb push_back
#define ALL(X) (X).begin(),(X).end()

template <typename T> T gcd(T a, T b) {return (a == 0) ? b : gcd(b%a, a);}
template <typename T> T lcm(T a, T b) { return a / gcd(a, b) * b;}

bool p_comp_fs(const PL p1, const PL p2){ return p1.first < p2.first;};
bool p_comp_fg(const PL p1, const PL p2){ return p1.first > p2.first;};
bool p_comp_ss(const PL p1, const PL p2){ return p1.second < p2.second;};
bool p_comp_sg(const PL p1, const PL p2){ return p1.second > p2.second;};
template <typename T>
vector<T> uniquen(vector<T> vec /* copy */){
    sort(ALL(vec)); vec.erase(unique(vec.begin(), vec.end()), vec.end()); return vec;
}

inline ll popcnt(ll x){return __builtin_popcountll((unsigned long long)x);};
template<class T> bool chmax(T &a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, T b) { if (a > b) { a = b; return true; } return false; }
//friend bool operator<(const tpl& lhs, const tpl& rhs){
//    return std::tie(lhs.l, lhs.r) < std::tie(rhs.l, rhs.r);
//}

bool bit(ll st, ll b){return ((st>>b)&1) == 1;}





int main()
{
    double x, y, size=10;
                                             
    string message("     hello   ななち      ");

    int print_line = 4;
    if (message.length() % 2 != 0) message += " ";

    for (x=0;x<size;x++) 
    {
        for (y=0;y<=4*size;y++)   
        {
            double dist1 = sqrt( pow(x-size,2) + pow(y-size,2) );
            double dist2 = sqrt( pow(x-size,2) + pow(y-3*size,2) );

            if (dist1 < size + 0.5 || dist2 < size + 0.5 ) {
                cout << "V";
            }
            else cout << " ";
        }
        sleep(1);
        cout<<"\n";
    }

    for (x=1;x<2*size;x++)
    {
        for(y=0;y<x;y++) cout << " ";

        for (y=0; y<4*size + 1 - 2*x; y++) 
        {            
            if (x >= print_line - 1 && x <= print_line + 1) {
                int idx = y - (4*size - 2*x - message.length()) / 2;
                if (idx < message.length() && idx >= 0) {
                    if (x == print_line) cout<<message[idx];
                    else cout << " ";
                }
                else cout << "V";
            }
            else cout << "V";
        }
        sleep(1);
        cout<<endl;
    }
}