// Problem Link - https://www.spoj.com/problems/AGGRCOW/
#include<bits/stdc++.h>
using namespace std;
#define ll              long long int
#define ld              long double
#define mod             1000000007
#define inf             1e18
#define nl              "\n"
#define pb              push_back
#define eb              emplace_back
#define vi              std::vector<ll>
#define vs              std::vector<std::string>
#define pii             std::pair<ll,ll> 
#define ump             std::unordered_map
#define mp              stdc::make_pair
#define pq_max          std::priority_queue<ll>
#define pq_min          std::priority_queue<ll,vi,std::greater<ll> >
#define all(n)          n.begin(),n.end()
#define ff              first
#define ss              second
#define mid(l,r)        (l+(r-l)/2)
#define bitc(n)         __builtin_popcount(n)
#define loop(i,a,b)     for(int i=(a);i<=(b);i++)
#define looprev(i,a,b)  for(int i=(a);i>=(b);i--)
#define iter(container, it) for(__typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define log(args...)    { std::string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); std::stringstream _ss(_s); std::istream_iterator<std::string> _it(_ss); err(_it, args); }
#define logarr(arr,a,b) for(int z=(a);z<=(b);z++) std::cout<<(arr[z])<<" ";std::cout<<std::endl;    
template <typename T> T gcd(T a, T b){if(a%b) return gcd(b,a%b);return b;}
template <typename T> T lcm(T a, T b){return (a*(b/gcd(a,b)));}
vs tokenizer(std::string str,char ch) {std::istringstream var((str)); vs v; std::string t; while(std::getline((var), t, (ch))) {v.pb(t);} return v;}
 
 
void err(std::istream_iterator<std::string> it) {}
template<typename T, typename... Args>
void err(std::istream_iterator<std::string> it, T a, Args... args) {
    std::cout << *it << " = " << a << std::endl;
    err(++it, args...);
}

//typedef trie<std::string,null_type,trie_string_access_traits<>,pat_trie_tag,trie_prefix_search_node_update> pbtrie;
 
void file_i_o()
{
    std::ios_base::sync_with_stdio(0); 
    std::cin.tie(0); 
    std::cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}
bool isPossibleToPlaceCows(ll positions[], ll n, ll c, ll mid){
    ll cowsPlaced = 1;
    ll lastPlaced = positions[0];
    for(size_t i=1;i<n;i++){
        if(positions[i] - lastPlaced >= mid){
            cowsPlaced+=1;
            lastPlaced = positions[i];
        }
    }
    if(cowsPlaced>=c) return true;
    return false;
}
int largestMinimumDistance(ll positions[],ll n, ll c){
    ll low = 1;
    ll high = positions[n-1]-positions[0];
    while(low<=high){
        ll mid = (low+high) >> 1;
        if(isPossibleToPlaceCows(positions,n,c,mid)){
            low = mid + 1;         
        }
        else{
            high = mid - 1;
        }
    }
    return high;
}


int main(int argc, char const *argv[]) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....
    ll t;
    cin >> t;
    while(t--){
        ll n,c;
        cin >> n >> c;
        ll positions[n];
        for(size_t i=0;i<n;i++){
            cin >> positions[i];
        }
        sort(positions,positions+n);
        cout << largestMinimumDistance(positions,n, c) << "\n";
    }
    
 
    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      std::cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}