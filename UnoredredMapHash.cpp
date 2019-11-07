
namespace std {
    template <>
    class hash<std::pair<ll, ll>> {
    public:
        size_t operator()(const std::pair<ll, ll>& x) const{
            return hash<ll>()(x.first) ^ hash<ll>()(x.second);
        }
    };
}
