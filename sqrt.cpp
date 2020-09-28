int binarySearch(int l, int r, int x) 
{ 
    int m= l + (r-l)/2;
    while (l <= r) { 
        m = l + (r - l) / 2; 

        if (1LL*m*m <= x && 1LL*(m+1)*(m+1) > x) 
            return m; 
        if (1LL*m*m < x) 
            l = m + 1; 

        else
            r = m - 1; 
    } 
} 
  

int Solution::sqrt(int A) {
    int max =1e5;
    int ans;
    if(A == 0 || A == 1) return A;
    else
        
        ans = binarySearch(1,max-1,A);
        return ans;
}
