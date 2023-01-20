class Solution {
    void backtrack(vector<int>&nums, set<vector<int>>&s, int index,vector<int>&temp) {
        int n=nums.size();
        
        if(index>=n) {
            if(temp.size()>=2) {
                s.insert(temp);
                
            }
            return;
        }
        
        if(temp.size()==0 || temp.back()<=nums[index]) {
            temp.push_back(nums[index]);
            backtrack(nums,s,index+1,temp);
            temp.pop_back();
        }
        backtrack(nums,s,index+1,temp);
        
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>>s;
        vector<int>temp;
        
        backtrack(nums,s,0,temp);
        
        return vector(s.begin(),s.end());
    }
};