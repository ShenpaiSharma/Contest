#include <bits/stdc++.h>
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define rrep(i,b,a) for(ll i=b;i>=a;i--)
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

////////////////////////////////////////////////////////////////////////////////////////

vector<pair<ll,ll>> v[101][101];
char a[101][101];
vector<pair<ll,ll>> g;
vector<pair<ll,ll>> b;
ll n,m;

bool bfs(ll x,ll y)
{
    if(a[n-1][m-1] == '#' && g.size() != 0) return false;
    if(g.size() == 0) return true;
    ll c = 0;
    if(a[n-1][m-1] == 'G') c++;
    bool vis[n][m];
    set(vis,false);
    queue<pair<ll,ll>> Q;
    vis[x][y] = true;
    Q.push(make_pair(x,y));
    while(!Q.empty())
    {
        pair<ll,ll> S = Q.front();
        Q.pop();
        for(auto it : v[S.f][S.s])
        {
            if(!vis[it.f][it.s])
            {
                vis[it.f][it.s] = true;
                Q.push(make_pair(it.f,it.s));
                if(a[it.f][it.s] == 'G')
                    c++;
                    //cout<<c<<endl;
            }
        }
    }
    if(c == g.size()) return true;
    else return false;
}

// bool fun()
// {
//     for(auto it:g)
//     {
//         if(!bfs(it.f,it.s)) return false;
//     }
//     return true;
// }

int main(){
	optimizeIO();
	tc
    {
        cin>>n>>m;
        
        ll x,y;
        rep(i,0,n)
        {
            rep(j,0,m)
            {
                cin>>a[i][j];
                if(a[i][j] == 'G')
                {
                    g.pb(make_pair(i,j));
                }
                if(a[i][j] == 'B')
                {
                    b.pb(make_pair(i,j));
                }
            }
        }
        bool flag = true;
        for(auto it: b)
        {
            x = it.f;
            y = it.s;
            //cout<<x<<" "<<y<<endl;
            if(x-1 >= 0)
            {
                if(a[x-1][y] == 'G')
                {
                    flag = false;
                    break;
                }
                else a[x-1][y] = '#',a[x][y] = '#';
            }
            if(x+1 < n)
            {
                if(a[x+1][y] == 'G')
                {
                    flag = false;
                    break;
                }
                else a[x+1][y] = '#',a[x][y] = '#';
            }
            if(y-1 >= 0)
            {
                if(a[x][y-1] == 'G')
                {
                    flag = false;
                    break;
                }
                else a[x][y-1] = '#',a[x][y] = '#';
            }
            if(y+1 < m)
            {
                if(a[x][y+1] == 'G')
                {
                    flag = false;
                    break;
                }
                else a[x][y+1] = '#',a[x][y] = '#';
            }
        }
        
       rep(i,0,n)
        {
            rep(j,0,m)
            {
				
                if(i-1 >= 0 && a[i-1][j] != '#') v[i][j].pb(make_pair(i-1,j));
                if(i+1 < n && a[i+1][j] != '#') v[i][j].pb(make_pair(i+1,j));
                if(j-1 >= 0 && a[i][j-1] != '#') v[i][j].pb(make_pair(i,j-1));
                if(j+1 < m && a[i][j+1] != '#') v[i][j].pb(make_pair(i,j+1));
            }
        }
        if(flag)
        {
            if(bfs(n-1,m-1)) cout<<"Yes";
            else cout<<"No";
        }
        else cout<<"No";
        g.clear();
        b.clear();
        rep(i,0,n)
        {
            rep(j,0,m)
            {
                v[i][j].clear();
            }
        }
        cout<<"\n";
    }
	return 0;
}