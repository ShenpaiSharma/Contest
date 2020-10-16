#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,b,a) for(int i=b;i>=a;i--)
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
#define f first
#define s second
#define pii pair< int, int >
#define tc int t; cin >> t; while(t--)
using namespace std;
#define debug(v) for(auto i:v) cout<<i<<" ";

const ll N = 1e5 + 1;
void optimizeIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

ll n;
vector<int> adj[N];
vector<int> e;
vector<int> m;
bool vis[N];

ll MOD(ll x){
    return ((x%mod + mod)%mod);
}

ll add(ll a,ll b){
    return MOD(MOD(a)+MOD(b));
}

ll mul(ll a, ll b){
    return MOD(MOD(a)*MOD(b));
}

ll dfs(ll s){
    vis[s] = true;
    ll child =0, t_c =0;
    for(auto it = adj[s].begin(); it!=adj[s].end(); ++it){
        if(!vis[*it]){
            ll child = dfs(*it);
            e.push_back(child*(n-child));
            t_c += child;
        }
    }
    return 1+t_c;
}

int main(){
    optimizeIO();
	ll t;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=0;i<n-1;i++){
			ll x,y;
			cin>>x>>y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		ll p;
		cin>>p;
		for(ll i=0;i<p;i++){
			ll z;
			cin>>z;
			m.push_back(z);
		}
		if(p <= n-1){
			for(ll i=0;i<=n-1-p;i++){
				m.push_back(1);
			}
			sort(m.begin(),m.end(),greater<ll>());
		}
		else{
		    ll q =1;
		    sort(m.begin(),m.end());
			for(ll i=p-1;i>=n-2;i--){
			    q = mul(q,m[i]);
			    q = MOD(q);
			    m.pop_back();
			}
			m.push_back(q);
			sort(m.begin(),m.end(),greater<ll>());
		}
		memset(vis,false,sizeof(vis));
		dfs(1);
		sort(e.begin(),e.end(),greater<ll>());
		ll sum = 0;
		for(ll i=0;i<m.size();i++){
		    sum = add(sum,mul(e[i],m[i]));
		    sum = MOD(sum);
		}
		cout<<sum<<endl;
		for(int i=0;i<=n;i++){
		    adj[i].clear();
		}
		m.clear();
		e.clear();
		memset(vis,false,sizeof(vis));
	}
	return 0;
}
