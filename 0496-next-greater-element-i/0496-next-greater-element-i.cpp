class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
       int n=nums2.size();
        
       vector<int>ans;
        stack<int>s;
        for(int i=n-1;i>=0;i--) {
            if(s.size()==0 ){
                ans.push_back(-1);
            }
            else if(s.size()>0 && s.top()>nums2[i]) {
                ans.push_back(s.top());
            }
            else  {
                while(s.size()> 0 && s.top()<=nums2[i]) {
                    s.pop();
                }
                if(s.size()==0) {
                    ans.push_back(-1);
                }
                else {
                    ans.push_back(s.top());
                }
            }
            s.push(nums2[i]);
        }
        reverse(ans.begin(),ans.end());
        vector<int>res;
        for(int i=0;i<nums1.size(); i++) {
            for(int j=0;j<n;j++) {
                if(nums1[i]==nums2[j])
                    res.push_back(ans[j]);
            }
            //res.push_back(ans[it]);
        }
        return res;
    }
};