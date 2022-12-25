class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        int n=nums.size();
        vector<int>ans(n);
        stack<int>s;
        for(int i=2*(n-1);i>=0;i--) {
         
                while(s.size()>0 && nums[s.top()]<= nums[i%n]) 
                    s.pop();
                ans[i%n]= s.size() ? nums[s.top()] :-1;
            s.push(i%n);
        }
        return ans;
    }
};