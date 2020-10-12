#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> prefixSum(vector<vector<int>> a,int n,int m){
    vector<vector<int>> aux;
    aux.resize(m,vector<int>(n));
    
    for(int i=0;i<m;i++){
	    aux[0][i] = a[0][i];
	}
	for(int i=1;i<n;i++){
	    for(int j=0;j<n;j++){
	        aux[i][j] = a[i][j] + aux[i-1][j];
	    }
	}
	for(int i=0;i<n;i++){
	    for(int j=1;j<n;j++){
	        aux[i][j] += aux[i][j-1];
	    }
	}
	return aux;
}

int main() {
	int n,m;
	cin>>n>>m;
    vector<vector<int>> a(n);
    
    int x;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            
            cin>>x;
            a[i].push_back(x);
        }
    }
	
	vector<vector<int>> aux = prefixSum(a,n,m);
	
	for(int i=0;i<a.size();i++){
	    for(int j=0;j<a[i].size();j++){
	        cout<<aux[i][j]<<" ";
	    }
	    cout<<endl;
	}
	int q;
	cin>>q;
	while(q--){
	    int r1,c1,r2,c2;
	    cin>>r2>>c2>>r1>>c1;
	    r1 = r1-1;
	    c1 = c1-1;
	    if(r1==-1){
	        cout<<aux[r2][c2] - 0 - aux[r2][c1] + 0<<endl;
	    }
	    else if(c1==-1){
	        cout<<aux[r2][c2] - aux[r1][c2] - 0 + 0<<endl;
	    }
	    else if(r1 == -1 && c1 == -1){
	        cout<<aux[r2][c2]<<endl;
	    }
	    else cout<<aux[r2][c2] - aux[r1][c2] - aux[r2][c1] + aux[r1][c1]<<endl;
	}
	return 0;
}
