                           /*^^::^^^anmit007^^::^^^*/
//---------------------------------------------------------------------------------------//
#include<bits/stdc++.h>
#define ll          long long
#define ld          long double
#define int         int64_t
#define pb          push_back
#define mid(l,r)    l+(r-l)/2;
#define endl        '\n'
#define pll         pair<int,int>
#define vll         vector<int>
#define all(a)      (a).begin(),(a).end()
#define in(a)       insert(a)
#define F           first
#define S           second
#define sz(x)       (int)x.size()
#define hell        1000000007
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define mi          map<int,int>
#define set_bits(x) _builtin_popcount(x)
#define lcm(a,b)    ((a)*(b)) / gcd((a),(b))
#define ios     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define REPI(i,a,b) for(ll i=b-1;i>=a;i--)
using namespace std;
static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
/*                            Trace                                        
------------------------------------------------------------------------------------------------*/
 
#define trace1(x)                cerr<<#x<<": "<<x<<endl
#define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a, b, c, d)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define trace5(a, b, c, d, e)    cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
#define trace6(a, b, c, d, e, f) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl
                                
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
bool revsort(ll a, ll b) {return a > b;}
void swap(int &x, int &y) {int temp = x; x = y; y = temp;}
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
void google(int t) {cout << "Case #" << t << ": ";}
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
 
 
vector<ll>tree;
vector<ll>arr;
 
void buildTree(ll s , ll e , ll ti)
{
 
    if(s==e){
      tree[ti] = arr[s];
      return;
    }
 
ll m = (s+e)/2;
buildTree(s,m,ti*2+1);
buildTree(m+1,e,ti*2+2);
tree[ti] = min(tree[2*ti+1],tree[2*ti+2]);
 
}
void update(ll nl , ll nr , ll ti , ll idx , ll val)
{
    if(nl==nr) {
      tree[ti] = val;
      arr[idx] = val;
      return;
    }
    ll mid = nl+(nr-nl)/2;
    if(idx>mid){
      update(mid+1,nr,(2*ti)+2,idx,val);
    }else{
      update(nl,mid,(2*ti)+1,idx,val);
    }
 
    tree[ti] = min(tree[(ti*2)+1],tree[(ti*2)+2]);
 
}
 
ll query(ll s, ll e , ll ti , ll l , ll r){
 if(r <s or l > e)  return INT_MAX;
 if(l <= s and r>=e) return tree[ti];
 ll m = (s+e)/2;
 ll ansLeft = query(s,m,2*ti+1,l,r);
 ll ansRight = query(m+1,e,2*ti+2,l,r);
 return min(ansLeft,ansRight);
}
 
 
 
signed main()
{
ios
 
#ifndef ONLINE_JUDGE 
  freopen("Error.txt" , "w" , stderr);
#endif
ll n ; cin >> n ;
ll q ; cin >> q ;
arr.resize(n);
for(int i= 0 ; i < n ; i++) cin >> arr[i];
tree.resize(4*n);
buildTree(0,n-1,0);
while(q--){
 
int type ; cin >> type ;
if(type==1){
  int idx , val ; cin >> idx >> val;
  idx--;
  update(0,n-1,0,idx,val);
}else{
  int l , r ; cin >> l >> r;
  l--;r--;
  cout << query(0,n-1,0,l,r) << endl;
}
 
}
}