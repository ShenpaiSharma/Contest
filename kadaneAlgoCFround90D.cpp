#include <bits/stdc++.h>
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define rrep(i,b,a) for(ll i=b;i>=a;i--)
#define vi vector<ll> 
#define fori(a) for(auto i : a )
#define all(a) begin(a), end(a)
#define set(a,b) memset(a,b,sizeof(a))
#define pi 3.14159
#define ll long long
#define ull unsigned long long
#define pb push_back
#define PF push_front //deque
#define mp make_pair
#define pq priority_queue
const ll mod=1e9+7;
const ll N = 1e5 +1;
#define f first
#define s second
#define pii pair< ll, ll >
#define so(v) sort(v.begin(), v.end())
#define tc int t; cin >> t; while(t--)
using namespace std;
#define deb1a(v)                  \
    cout << #v << "--->" << endl; \
    for (auto it : v)             \
        cout << it << " ";        \
    cout << endl;
#define deb2a(v)                  \
    cout << #v << "--->" << endl; \
    for (auto it : v)             \
    {                             \
        for (auto it1 : it)       \
        {                         \
            cout << it1 << " ";   \
        }                         \
        cout << endl;             \
    }
#define deb3a(v)                               \
    cout << #v << "-->" << endl;               \
    for (auto it : v)                          \
    {                                          \
        cout << it.fi << " " << it.se << endl; \
    }

void optimizeIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

/*void IO(){
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
}*/

/*ll MOD(ll x){
    return ((x%mod + mod)%mod);
}

ll add(ll a,ll b){
    return MOD(MOD(a)+MOD(b));
}

ll mul(ll a, ll b){
    return MOD(MOD(a)*MOD(b));
}

bool prime(ll n){
	if( n< 2) return false;
	for(ll i=2;i*i<=n;i++){
		if(n%i == 0){
			return false;
		}
	}
	return true;
}

vector<ll> factors(ll n){
	vector<ll> fa;
	for(ll i=2;i*i<=n;i++){
		while(n%i == 0){
			fa.pb(i);
			n /= i;
		}
	}
	if(n > 1){
		fa.pb(n);
	}
	return fa;
}


vector<ll> Sieve(ll n){
	vector<ll> s;
	bool prime[n+1];
	memset(prime,true,sizeof(prime));
	for(ll p=2;p*p<=n;p++){
		if(prime[p]){
			for(ll i=2*p;i<=n;i+=p){
				prime[i] = false;
			}
		}
	}
	for(ll i=2;i<=n;i++){
		if(!prime[i]){
			s.pb(i);
			cout<<i<<" ";
		}
	}
	return s;
}

ll phi(ll n){
	ll result = n;
	for(ll p=2;p*p<=n;p++){
		if(n%p == 0){
			while(n%p == 0){
				n /= p;
			}
			result -= result/p;
		}
	}
	if(n >1){
		result -= result/n;
	}
	return result;
}

ll modexpo(ll x,ll n,ll mod){
	if(n == 0) return 1;
	else if(n%2 == 0){
		return modexpo((x*x)%mod,n/2,mod);
	}
	else return (x*modexpo((x*x)%mod,(n-1)/2,mod))%mod;
}

const ll zero;

void buildtree(ll start, ll end, ll node)
{
    if(start == end)
    {
        tree[node] = arr[start];
        return;
    }
    ll mid = (start + end)/2;
    buildtree(start, mid, 2*node);
    buildtree(mid+1, end, 2*node +1);
    tree[node] = min(tree[2*node], tree[2*node + 1]);
}

void update(ll s, ll e, ll idx, ll val, ll node)
{
	if(s == e)
	{
		tree[node] = val;
		arr[idx] = val;
	}
	else
	{
		ll mid = (s+e)/2;
		if(idx >= s && idx <= mid)
		{
			update(s,mid,idx,val,2*node);
		}
		else
		{
			update(mid+1,e,idx,val,2*node+1);
		}
		tree[node] = min(tree[2*node], tree[2*node+1]);
	}
}

ll query(ll s,ll e,ll l,ll r, ll node)
{
	if(r < s || l > e) return zero;
	if(l <= s && r >= e)
	{
		return tree[node];
	}
	ll mid = (s+e)/2;
	ll p1 = query(s,mid,l,r,2*node);
	ll p2 = query(mid+1,e,l,r,2*node+1);
	return min(p1,p2);
}

ll binary_search(ll arr[],ll l, ll r,ll x){
	if(r >= l){
		ll mid = l + (r-l)/2;
		if(x == arr[mid]){
			return x;
		}
		if(x < arr[mid]){
			return binary_search(arr,l,mid-1,x);
		}
		return binary_search(arr,mid+1,r,x);
	}
	return -1;
}*/

//////////////////////////////////////////////////////////////////////////////////////////

ll kadane(vi a)
{
    ll n = a.size();
    ll ans = a[0];
    ll curr = a[0];
    rep(i,1,n)
    {
        curr = max(a[i], curr + a[i]);
        ans = max(ans, curr);
    }
    return ans;
}

int main()
{
	optimizeIO();
	tc
    {
        ll n;
        cin>>n;
        vi a(n);
        ll ans = 0;
        rep(i,0,n)
        {
            cin>>a[i];
            if(i%2 == 0) ans += a[i];
        }
        if(n == 1) cout<<ans;
        else if(n==2) cout<<max(a[0],a[1]);
        else
        {
            vi b,v;
            for(ll i=1;i<n;i+=2)
            {
                b.pb(a[i] - a[i-1]);
                if(i+1 < n) v.pb(a[i] - a[i+1]);
            }
            ll x = max(kadane(b), kadane(v));
            if(x > 0) cout<<ans+x;
            else cout<<ans;
        }
    
        cout<<"\n";
    }
	return 0;
}
