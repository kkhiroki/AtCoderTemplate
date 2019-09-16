template< unsigned mod >
struct RollingHash {
    vector< unsigned > hashed, power;
    
    inline unsigned mul(unsigned a, unsigned b) const {
        unsigned long long x = (unsigned long long) a * b;
        unsigned xh = (unsigned) (x >> 32), xl = (unsigned) x, d, m;
        asm("divl %4; \n\t" : "=a" (d), "=d" (m) : "d" (xh), "a" (xl), "r" (mod));
        return m;
    }
    
    RollingHash(const string &s, unsigned base = 10007) {
        int sz = (int) s.size();
        hashed.assign(sz + 1, 0);
        power.assign(sz + 1, 0);
        power[0] = 1;
        for(int i = 0; i < sz; i++) {
            power[i + 1] = mul(power[i], base);
            hashed[i + 1] = mul(hashed[i], base) + s[i];
            if(hashed[i + 1] >= mod) hashed[i + 1] -= mod;
        }
    }
    
    unsigned get(int l, int r) const {
        unsigned ret = hashed[r] + mod - mul(hashed[l], power[r - l]);
        if(ret >= mod) ret -= mod;
        return ret;
    }
    
    unsigned connect(unsigned h1, int h2, int h2len) const {
        unsigned ret = mul(h1, power[h2len]) + h2;
        if(ret >= mod) ret -= mod;
        return ret;
    }
    
    int LCP(const RollingHash< mod > &b, int l1, int r1, int l2, int r2) {
        int len = min(r1 - l1, r2 - l2);
        int low = -1, high = len + 1;
        while(high - low > 1) {
            int mid = (low + high) / 2;
            if(get(l1, l1 + mid) == b.get(l2, l2 + mid)) low = mid;
            else high = mid;
        }
        return (low);
    }
};

using RH1 = RollingHash< 1000000007 >;
using RH2 = RollingHash< 2147483647 >;
using RH3 = RollingHash< 2147483629 >;


const vector<unsigned int> mods = {1000000007, 2147483647, 2147483629};
const vector<unsigned int> bases = {10007, 1000000007, 2147483647};

struct RollingHashMultiple{
private:
    RH1 rh1;
    RH2 rh2;
    RH3 rh3;
    
public:
    RollingHashMultiple(string& s)
    : rh1(s, bases[0]), rh2(s, bases[1]), rh3(s, bases[2]){}
    
    bool match(int l1, int r1, int l2, int r2){
        if(rh1.get(l1, r1) != rh1.get(l2, r2)) return false;
        if(rh2.get(l1, r1) != rh2.get(l2, r2)) return false;
        if(rh3.get(l1, r1) != rh3.get(l2, r2)) return false;
        return true;
    }
    
    vl getHashes(int l, int r){
        vl res;
        res.pb(rh1.get(l, r));
        res.pb(rh2.get(l, r));
        res.pb(rh3.get(l, r));
        return res;
    }
};
