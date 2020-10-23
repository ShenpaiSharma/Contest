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
//#define tc int t; cin >> t; while(t--)
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

void IO(){
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
}

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
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

ll n,m,sx,sy,lx,ly,a,b;
vector<pair<ll,ll>> node[N];
vector<pair<ll,ll>> X;
vector<pair<ll,ll>> Y;

/*vector<ll> dist;
vector<bool> done;*/

void addEdgeWithStart(){
    for(ll i=0;i<m;i++){
        ll w = min(abs(X[i].f - sx), abs(Y[i].f - sy));
        node[0].pb(make_pair(i+1,w));
    }
}

void addEdgeFromEnd(){
    for(ll i=0;i<m;i++){
        ll w = abs(X[i].f - lx) + abs(Y[i].f - ly);
        node[X[i].s].pb(make_pair(m+1,w));
    }
    node[0].pb(make_pair(m+1,(abs(sx-lx) + abs(sy - ly))));
}

void addAdjacentEdge(vector<pair<ll,ll>> &inst){
    for(ll i=1;i<inst.size();i++){
        ll w = abs(inst[i].f - inst[i-1].f);
        node[inst[i-1].s].pb(make_pair(inst[i].s,w));
        node[inst[i].s].pb(make_pair(inst[i-1].s,w));
    }
}

/*struct comp {
    bool operator() (const pair<ll,int> &x, const pair<ll,int> &y) {
        return (x.first > y.first);
    }
};*/

ll djisktra(ll src){
    vector<ll> dist(m+2);
    for(ll i=0;i<=m+1;i++){
        dist[i] = LONG_MAX;
    }
    dist[src] = 0;
    set<pair<ll,ll>> S;
    S.insert(make_pair(0,src));
    while(!S.empty()){
        auto p = *(S.begin());
        ll block = p.s;
        ll bdist = p.f;
        S.erase(S.begin());
        for(auto i:node[block]){
            if(bdist + i.s < dist[i.f]){
                ll dest = i.f;
                auto f = S.find(make_pair(dist[dest],dest));
                if(f != S.end()){
                    S.erase(f);
                }
                S.insert(make_pair(bdist + i.s,dest));
                dist[dest] = bdist + i.s;
            }
        }
    }
    return dist[m+1];
}

int main(){
	//IO();
	cin>>n>>m;
	cin>>sx>>sy>>lx>>ly;
	for(ll i=1;i<=m;i++){
		cin>>a>>b;
		X.pb(make_pair(a,i));
		Y.pb(make_pair(b,i));
	}
	/*for(auto i:X){
	    cout<<i.f<<" "<<i.s<<endl;
	}*/
	addEdgeWithStart();
	addEdgeFromEnd();
	sort(X.begin(),X.end());
	sort(Y.begin(),Y.end());
	addAdjacentEdge(X);
	addAdjacentEdge(Y);
	
	cout<<djisktra(0)%mod;
	/*priority_queue<pair<ll,int>, vector<pair<ll,int>>, comp> pq;            // or greater<pair<ll,int>>
    dist.resize(m + 2, LONG_MAX);       done.resize(m + 2, false);
    dist[0] = 0;
    pq.push({dist[0], 0});

    while(!pq.empty()) {
        pair<ll,int> curr = pq.top();       pq.pop();

        if(curr.s == m + 1) {       // destination
            dist[m + 1] = curr.f;
            break;
        }
        
        if(done[curr.s]) continue;

        int id = curr.s;    ll w = curr.f;
        done[id] = true;
        dist[id] = w;
        //printf("Popped:%d, dist:%lld\n", id, w);

        for(auto edge: node[id])
            if(dist[edge.f] > w + edge.s)
                pq.push({w + edge.s, edge.f});
    }

    cout<<dist[m + 1]<<endl;*/
	return 0;
}
