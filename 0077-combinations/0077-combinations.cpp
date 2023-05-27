class Solution {
    void combination (int ind,int n,int k,vector<int>&ds, vector<vector<int>>&ans){
        if(ind>n || ds.size()>=k){
            if(ds.size()==k ) {
                ans.push_back(ds);
            }
            return;
        }
        ds.push_back(ind);
        combination(ind+1,n,k,ds,ans);
        ds.pop_back();
        combination(ind+1,n,k,ds,ans);
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int>ds;
        vector<vector<int>>ans;
        combination(1,n,k,ds,ans);
        return ans;
    }
};