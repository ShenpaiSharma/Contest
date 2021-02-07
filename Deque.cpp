//Given a set of arrays of size N and an integer K, you have to find the maximum integer for each and every contiguous subarray of size K for each of the given arrays.

/*2
5 2
3 4 6 3 4
7 4
3 4 5 8 1 4 10

4 6 6 4
8 8 8 10*/

#include <iostream>
#include <deque> 
using namespace std;


void printKMax(int arr[], int n, int k)
{
    deque<int> dq;
    int i;
    for(i = 0;i<k;i++)
    {
        while(!dq.empty() && arr[i] >= arr[dq.back()])
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    for(;i<n;++i)
    {
        cout<<arr[dq.front()]<<" ";
        while(!dq.empty() && dq.front() <= i-k)
        {
            dq.pop_front();
        }
        while(!dq.empty() && arr[i] >= arr[dq.back()])
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    cout<<arr[dq.front()]<<endl;
}

int main(){
  
	int t;
	cin >> t;
	while(t>0) {
		int n,k;
    	cin >> n >> k;
    	int i;
    	int arr[n];
    	for(i=0;i<n;i++)
      		cin >> arr[i];
    	printKMax(arr, n, k);
    	t--;
  	}
  	return 0;
}
