#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll N = 1e5;
const ll k = 16;
const ll ZERO = 1e9 +1;
ll table[1000][1000];

int main(){
	ll n;
	cin>>n;
	ll arr[n];
	for(ll i=0;i<n;i++){
		cin>>arr[i];
	}
	for(ll i=0;i<n;i++){
		table[i][0] = arr[i];
	}
	for(ll j=1;j<=k;j++){
		for(ll i=0;i<=n-(1<<j);i++){
			table[i][j] = min(table[i][j-1], table[i+(1<<(j-1))][j-1]);
		}
	}

	ll q;
	cin>>q;
	while(q--){
		ll l,r;
		ll ans = ZERO;
		cin>>l>>r;
		for(ll i=k;i>=0;i--){
			if(l+(1<<i)-1 <= r){
				ans = min(ans,table[l][i]);
				l += 1<<i;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
