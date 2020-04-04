
const int VMAX = 1e6; // *** NOTE !!! ***
class LiChao
{
public:
    struct Line
    {
        ll a = 0, b = 0;
        Line() { ; }
        Line(ll _a, ll _b) { a = _a; b = _b; }
        ll operator()(ll x) { return a * x + b; }
    };
 
    Line aint[4 * VMAX];
 
    void build(int nod, int st, int dr)
    {
        aint[nod] = Line((1ll << 30), (1ll << 60));
        if(st == dr)    return;
        int mij = st + (dr - st) / 2;
        build(nod * 2, st, mij);
        build(nod * 2 + 1, mij + 1, dr);
    }
 
    void update(int nod, int st, int dr, Line l)
    {
        int mij = st + (dr - st) / 2;
 
        if(l(mij)< aint[nod](mij)) swap(aint[nod], l);
 
        if(st == dr)    return;
 
        if(l(st) < aint[nod](st))   update(nod * 2, st, mij, l);
        if(l(dr) < aint[nod](dr))   update(nod * 2 + 1, mij + 1, dr, l);
    }
 
    ll query(int nod, int st, int dr, int pos)
    {
        if(st == dr)    return aint[nod](pos);
 
        ll val = aint[nod](pos);
        int mij = st + (dr - st) / 2;
        if(pos <= mij)  val = min(val, query(nod * 2, st, mij, pos));
        else    val = min(val, query(nod * 2 + 1, mij + 1, dr, pos));
        return val;
    }
 
    void update(ll x, ll y)
    {
        update(1ll, 1ll, VMAX, Line(x, y));
    }
 
    ll query(ll x)
    {
        return query(1, 1, VMAX, x);
    }
 
    void build()
    {
        build(1, 1, VMAX);
    }
 
};

