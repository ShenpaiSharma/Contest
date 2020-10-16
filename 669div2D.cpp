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

const int N = 1e5 + 1;

void optimizeIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

//vector<ll> adj[N];

/*void Add(ll x,ll y){
	adj[x].push_back(y);
}

ll bfs(ll s,ll r){
	bool vis[N];
	memset(vis,false,sizeof(vis));
	ll level[N];
	memset(level,0,sizeof(level));
	queue<ll> q;
	vis[s] = true;
	q.push(s);
	level[s] = 0;
	while(!q.empty()){
		ll s = q.front();
		q.pop();
		for(auto it=adj[s].begin();it != adj[s].end();++it){
			if(!vis[*it]){
				q.push(*it);
				level[*it] = level[s] + 1;
				vis[*it] = true;
			}
			if(*it == r){
				return level[*it];
			}
		}
	}
}*/

int main(){
    optimizeIO();
	int n;
	cin>>n;
	vector<int> h(n);
	for(int i=0;i<n;i++){
	    cin>>h[i];
	}
	vector<vector<int>> g(n);
	for(int r=0;r<2;r++){
	    auto Add = [&](int i, int j) {
            g[i].push_back(j);
        };
	    vector<int> st;
	    for(int i=0;i<n;i++){
	        while(!st.empty() && h[st.back()] < h[i]){
	            Add(st.back(),i);
	            st.pop_back();
	        }
	        if(!st.empty()){
	            Add(st.back(),i);
	            if(h[st.back()] == h[i]){
	                st.pop_back();
	            }
	        }
	        st.push_back(i);
	    }
	    for(int i=0;i<n;i++){
	        h[i] = -h[i];
	    }
	}
	vector<int> dist(n,-1);
	vector<int> que(1,0);
	dist[0] = 0;
	for(int b=0;b<(int)que.size();b++){
	    for(int j:g[que[b]]){
	        if(dist[j] == -1){
	            que.push_back(j);
	            dist[j] = dist[que[b]] + 1;
	        }
	    }
	}
	cout<<dist[n-1]<<endl;
/*	ll bfs(ll s,ll r){
	bool vis[N];
	memset(vis,false,sizeof(vis));
	ll level[N];
	memset(level,0,sizeof(level));
	queue<ll> q;
	vis[s] = true;
	q.push(s);
	level[s] = 0;
	while(!q.empty()){
		ll s = q.front();
		q.pop();
		for(auto it=adj[s].begin();it != adj[s].end();++it){
			if(!vis[*it]){
				q.push(*it);
				level[*it] = level[s] + 1;
				vis[*it] = true;
			}
			if(*it == r){
				return level[*it];
			}
		}
	}
}*/
	return 0;
}
