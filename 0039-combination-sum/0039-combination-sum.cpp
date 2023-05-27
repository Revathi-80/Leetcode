class Solution {
void combination(int ind, vector<int>&candidates, int target, vector<int>&ds, vector<vector<int>>&ans , int n) {
    if(ind>=n || target <=0) {
        if(target==0) {
            ans.push_back(ds);
        }
        return ;
    }
    ds.push_back(candidates[ind]);
    target-=candidates[ind];
    combination(ind,candidates,target,ds,ans,n);
    ds.pop_back();
    target+=candidates[ind];
    combination(ind+1,candidates,target,ds,ans,n);
}
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>ds;
        vector<vector<int>>ans;
        int n=candidates.size();
        combination(0,candidates,target,ds,ans,n);
        return ans;
    }
};