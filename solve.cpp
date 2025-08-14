/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 Code written by Aditya ;)   ||  Codechef/codeforces: @adityaraj5200
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
//----------HEADER----------
#include<bits/stdc++.h>
using namespace std;

//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//template<class T> using ordered_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update >;

//----------MACROS----------
#define fastio                        \
    ios_base::sync_with_stdio(false);  \
    cin.tie(NULL);                     \
    cout.tie(NULL)
#define endl                  "\n" 
#define all(u)                u.begin(), u.end()
#define rall(v)               v.rbegin(), v.rend()
#define sortall(u)            sort(all(u))
#define lcm(a,b)              (a*b)/__gcd(a,b)
#define gcd(a,b)              __gcd(a,b)
#define summation(n)          (((n)*((n)+1))/2)
#define countDigits(n)             (1+floor(log10(n)))
#define setbits(u)            __builtin_popcount(u)
#define ctz(u)                __builtin_ctz(u)
#define clz(u)                __builtin_clz(u)
#define checkbit(num,i)       (num&(1<<i))  //select the bit of position i of val
#define lowbit(u)             ((u)&((u)^((u)-1))) //get the lowest bit of u
#define trav(u,it)            for(auto it = u.begin(); it != u.end(); it++)
#define in(u, a, b)           (min(a,b) <= u && u <= max(a,b))

//----------TYPEDEFS----------
typedef unsigned int          uint;
typedef long long             ll;
typedef unsigned long long    ull;
typedef long double           ld;
typedef pair<int, int>         pii;

//----------DEBUG METHODS----------
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char* x) { cerr << '"' << x << '"'; }
void __print(const string& x) { cerr << '"' << x << '"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template<typename T, typename V>
void __print(const pair<T, V>& x) { cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}'; }
template<typename T>
void __print(const T& x) { int f = 0; cerr << '{'; for (auto& i : x) cerr << (f++ ? "," : ""), __print(i); cerr << "}"; }
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) { __print(t); if (sizeof...(v)) cerr << ", "; _print(v...); }

#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#define nline cerr << endl
#else
#define debug(x...)
#define nline 
#endif

//----------CONSTANTS----------
const ll mod = 1000000007;
const ll mod2 = 998244353;
const ld ep = 0.0000001;
const ld pi = acos(-1.0);

//----------TEMPLATES---------- Works only in C++ 17
template<typename... T>
void read(T&... args) { ((cin >> args), ...); }
template<typename... T>
void put(T&&... args) { ((cout << args << " "), ...); }
template<typename... T>
void putl(T&&... args) { ((cout << args << " "), ...); cout << endl; }
template<typename... T>
void putnl(T&&... args) { ((cout << args << "\n"), ...);}

//----------Custom hash map-------------
struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
template <typename T1, typename T2> // Key should be integer type
using safe_map = unordered_map<T1, T2, custom_hash>;


//----------Operator overloads--------------
template <typename T1, typename T2> // cin >> pair<T1, T2>
istream& operator>>(istream& istream, pair<T1, T2>& p) {
    return (istream >> p.first >> p.second);
}
template <typename T> // cin >> vector<T>
istream& operator>>(istream& istream, vector<T>& v) {
    for (auto& it : v)
        cin >> it;
    return istream;
}
template <typename T1, typename T2> // cout << pair<T1, T2>
ostream& operator<<(ostream& ostream, const pair<T1, T2>& p) {
    return (ostream << p.first << " " << p.second);
}
template <typename T> // cout << vector<T>
ostream& operator<<(ostream& ostream, const vector<T>& c) {
    for (auto& it : c)
        cout << it << " ";
    return ostream;
}
template <typename T>
int32_t size_i(T& container) { return static_cast<int32_t>(container.size()); }


//----------Mathematical functions------------
int GCD_extended(int a, int b, int& x, int& y) {
    x = 1, y = 0;
    int x1 = 0, y1 = 1, a1 = a, b1 = b;
    while (b1){
        int q = a1 / b1;
        tie(x, x1) = make_tuple(x1, x - q * x1);
        tie(y, y1) = make_tuple(y1, y - q * y1);
        tie(a1, b1) = make_tuple(b1, a1 - q * b1);
    }
    return a1;
}

ll modpow(ll x, ll n, ll m = mod) {
    if (x == 0 && n == 0)
        return 0; // undefined case
    
    ll res = 1;
    while (n > 0)
    {
        if (n % 2)
            res = (res * x) % m;
        x = (x * x) % m;
        n /= 2;
    }
    return res;
}

ll modinv(ll x, ll m = mod) {
    return modpow(x, m - 2, m);
}

mt19937 rng;
int getRandomNumber(int l, int r)
{
    uniform_int_distribution<int> dist(l, r);
    return dist(rng);
}

/*/------------------------------ CODE BEGINS ------------------------------/*/
void preprocess(){
    rng = mt19937(chrono::steady_clock::now().time_since_epoch().count());
}

const int N = 2e5 + 5;

void solve(){
    
}

void bruteforce(){
    // This function is used to check the correctness of the solution
    // by comparing it with a brute force solution.
    // It should be implemented only if necessary.
    // Otherwise, it can be left empty or removed.
    
}
/*/------------------------------- CODE ENDS -------------------------------/*/

int main(){
    fastio;
    // cout << setprecision(12) << fixed;

    preprocess();

    int num_tc=1;
    cin>>num_tc;
    for(int tc=1;tc<=num_tc;tc++){
        // solve();
        bruteforce();
    }

    return 0;
}