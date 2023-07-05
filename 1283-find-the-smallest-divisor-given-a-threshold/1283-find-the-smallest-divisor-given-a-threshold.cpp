class Solution {
    bool possible (vector<int>&nums,int threshold, int mid){
        long ans=0;
        for(int i=0;i<nums.size();i++){
            ans += (nums[i]+mid-1)/mid;
        }
        // cout<<ans<<endl;
        return ans<=threshold;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1,high=INT_MIN;
        for(int i=0;i<nums.size();i++) high=max(high,nums[i]);
        while(low<=high) {
            int mid= low +(high - low)/2;
            // cout<<"Mid "<<mid<<endl;
            if(possible(nums,threshold, mid))
                high=mid-1;
            else
                low=mid+1;
        }
        return low;
    }
};