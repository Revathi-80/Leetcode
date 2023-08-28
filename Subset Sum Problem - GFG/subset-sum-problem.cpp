//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
private:
    bool subsets(vector<int>&arr,int ind,int sum,vector<vector<int>>&dp) {
        if(sum==0) return true;
        if(ind==0) return arr[0]==sum;
        if(dp[ind][sum]!=-1) return dp[ind][sum];
        bool notTake = subsets(arr,ind-1,sum,dp);
        bool take=false;
        if(sum>=arr[ind]) 
            take= subsets(arr,ind-1,sum-arr[ind],dp);
        return dp[ind][sum]=take || notTake;
    }
public:
    bool isSubsetSum(vector<int>arr, int sum){
        int n=arr.size();
        vector<bool>prev(sum+1,0),curr(sum+1,0);
        prev[0]=curr[0]=1;
        prev[arr[0]]=1;
        for(int ind=1;ind<n;ind++){
            for(int j=1;j<=sum;j++) {
                bool nottake = prev[j];
                bool take=false;
                if(j>=arr[ind])
                    take=prev[j-arr[ind]];
               curr[j]=take|nottake;
            }
            prev=curr;
        }
        return prev[sum];
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends