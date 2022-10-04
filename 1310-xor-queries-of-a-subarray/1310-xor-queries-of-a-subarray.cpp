class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n=arr.size();
        vector<int>dp(n+1,0);
        for(int i=1;i<n+1;i++){
            dp[i]=dp[i-1]^arr[i-1];
        }
       // for (auto i:dp) cout<<i<<endl;
        vector<int>ans;
        for(auto x:queries){
        //    cout<<dp[x[0]]<<" "<<dp[x[1]]<<endl;
         int p= dp[++x[1]]^dp[++x[0]-1];
         ans.push_back(p);
        }
        return ans;
    }
};