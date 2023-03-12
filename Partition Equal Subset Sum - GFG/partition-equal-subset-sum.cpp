//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    bool subset(int arr[],int n,int sum) {
        bool dp[n+1][sum+1];
        for(int i=0;i<=n;i++)
         dp[i][0]=true;
        for(int j=1;j<=sum;j++)
          dp[0][j]=false;
          for(int i=1;i<=n;i++) {
              for(int j=1;j<=sum;j++) {
                  if(arr[i-1]<=j)
                     dp[i][j]= dp[i-1][j-arr[i-1]] || dp[i-1][j];
                  else
                    dp[i][j]= dp[i-1][j];
              }
          }
          return dp[n][sum];
    }
public:
    int equalPartition(int N, int arr[])
    {
        int sum=0;
        for(int i=0;i<N;i++) sum+=arr[i];
        
      bool ans=  (sum%2)?false :subset(arr,N,sum/2);
      return ans?1:0;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends