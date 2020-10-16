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
 
ll say(ll a, ll b){
	cout<<"? "<<a<<" "<<b<<endl;
	ll x;
	cin>>x;
	return x;
}
 
int main(){
    optimizeIO();
	
	ll n;
	cin>>n;
	ll a[n];
	ll r =1;
	for(ll i=2;i<=n;i++){
		ll x = say(r,i);
		ll y = say(i,r);
		if(x>y){
			a[r] = x;
			r = i;
		}
		else a[i] = y;
	}
	a[r] = n;
	cout<<"! ";
	for(ll i=1;i<=n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	
	return 0;
}
