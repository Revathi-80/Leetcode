//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
void generate(int ind,vector<int>&arr,int N,vector<int>&ds,int sum){
    if(ind>=N){
        ds.push_back(sum);
      return;
    }
    //  pick
    generate(ind+1,arr,N,ds,sum+arr[ind]);
    
    // notpick
    generate(ind+1,arr,N,ds,sum);
      
}
public:
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int>ds;
        generate(0,arr,N,ds,0);
        return ds;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends