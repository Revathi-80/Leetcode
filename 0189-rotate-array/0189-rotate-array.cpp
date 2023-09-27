class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;
        int rot=n-k;
        reverse(nums.begin(),nums.begin()+rot);
        reverse(nums.begin()+rot,nums.end());
        reverse(nums.begin(),nums.end());
    }
};