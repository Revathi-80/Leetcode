//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
       unordered_map<int,int>mpp;
    //   mpp[0]=0;
       int len=0;
       int sum=0;
       for(int i=0;i<N;i++){
           sum+=A[i];
           if(sum==K){
               len=max(len,i+1);
           }
           if(mpp.find(sum-K)!=mpp.end()){
               int wind=i- mpp[sum-K];
               len=max(len,wind);
           }
           if(mpp.find(sum)==mpp.end())
           mpp[sum]=i;
       }
       return len;
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends