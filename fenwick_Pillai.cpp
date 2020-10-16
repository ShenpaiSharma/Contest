// Not been able to pass all the test case

#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll N = 1e5;
const ll mod = 1e9 + 7;

void optimizeIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

ll MOD(ll x){
    return ((x%mod + mod)%mod);
}

ll add(ll a,ll b){
    return MOD(MOD(a)+MOD(b));
}

ll mul(ll a, ll b){
    return MOD(MOD(a)*MOD(b));
}
ll bit[N];
ll n;

void update(ll i,ll val){
	for(;i<=n;i += i&-i){
		bit[i] = add(val,bit[i]);
	}
}

ll phil(ll n){
    ll result = n%mod;
    for(ll p=2;p*p<=n;p++){
        if(n%p == 0){
            while(n%p == 0){
                n /= p;
            }
            result -= result/p;
        }
    }
    if(n > 1){
        result -= result/n;
    }
    return result;
}

ll GSum(ll n){
    ll sum = 0;
    for(ll i=1;i*i<n;i++){
        if(n%i == 0){
            sum = add(sum,i*phil(n/i));
        }
    }
    for(ll i = sqrt(n);i>=1;i--){
        if(n%i == 0){
            sum = add(sum,(n/i)*phil(n/(n/i)));
        }
    }
    return sum%mod;
}

ll Sum(ll i){
	ll sum = 0;
	for(;i>0;i -= i&-i){
		sum = add(sum,bit[i]);
	}
	return sum%mod;
}

int main() {
	optimizeIO();
	cin>>n;
	ll a[n+1];
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	ll g[n+1];
	memset(g,0,sizeof(g));
	for(ll i=1;i<=n;i++){
		g[i] = GSum(a[i]);
	}
	for(ll i=1;i<=n;i++){
		update(i,g[i]);
	}
	ll q;
	cin>>q;
	while(q--){
		char t;
		ll x,y;
		cin>>t>>x>>y;
		if(t == 'C'){
			cout<<Sum(y)%mod - Sum(x-1)%mod<<endl;
		}
		else if(t == 'U'){
			ll e = GSum(y)%mod;
			update(x,e-g[x]);
			g[x] = e%mod;
			a[x] =y%mod;
		}
	}
	return 0;
}
