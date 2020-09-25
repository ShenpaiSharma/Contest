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

void optimizeIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main() {
    optimizeIO();
    ll n;
    cin>>n;
    ll arr[n];
    ll insum = 0;
    for(ll i=0;i<n;i++){
        cin>>arr[i];
        insum += arr[i]^(1<<27);
    }
    int r;
	for(ll i=0;i<1000;i++){
	    if(insum - i*(1<<27) < 0){
	        r = i;
	        break;
	    }
    }
    insum = insum-(r-1)*(1<<27);
	vector<ll> v;
	ll ans = 0;
	for(ll i=0;i<21;i++){
	    ll check = 0;
	    for(ll j=0;j<n;j++){
	        check += arr[j]^(1<<i);
	    }
	    if((((insum + (1<<i)*n) - check)/(2*(1<<i))) % 2 == 1){
            v.push_back(1);
	    }
	    else v.push_back(0);
	}
	for(ll i=0;i<v.size();i++){
	    if(v[i] == 1){
	        ans += 1<<i;
	    }
	}
	cout<<ans;
	return 0;
}
