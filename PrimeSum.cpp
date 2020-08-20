#include <bits/stdc++.h>
using namespace std;

bool Prime(int n){
    if(n < 2) return false;
    for(int x=2;x*x <= n;x++){
        if(n%x == 0) return false;
    }
    return true;
}


int SumofPrime(int n){
    vector<int> ans;
    for(int i=2;i<=n;i++){
        if(Prime(i)) ans.push_back(i);
    }
    int sum = accumulate(ans.begin(), ans.end(), 0);
    return sum;
}

int main() {
	int test;
	cin>>test;
	while(test--){
	    int n;
	    cin>>n;
	    cout<<SumofPrime(n)<<endl;
	}
	return 0;
}
