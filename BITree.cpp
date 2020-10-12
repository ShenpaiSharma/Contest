#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
int bit[N];

void update(int i,int val){
	for(;i<N;i += i&-i){
		bit[i] += val;
	}
}

int Sum(int i){
	int sum = 0;
	for(;i>0;i -= i&-i){
		sum += bit[i];
	}
	return sum;
}

int main(){
	//cout<<"hello";
	int n;
	cin>>n;
	int arr[n];
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	for(int i=1;i<=n;i++){
		update(i,arr[i]);
	}
	int q;
	cin>>q;
	while(q--){
		int type;
		cin>>type;
		if(type == 1){
			int x,i;
			cin>>i>>x;
			update(i,x-arr[i]); // Indexing in binary tree start from 1
			arr[i] = x;
		}
		else if(type == 2){
		    int l,r;
		    cin>>l>>r;
			cout<<Sum(r) - Sum(l-1)<<endl;
		}
		else cout<<"Type propely idiot"<<endl;
	}
	return 0;
}
