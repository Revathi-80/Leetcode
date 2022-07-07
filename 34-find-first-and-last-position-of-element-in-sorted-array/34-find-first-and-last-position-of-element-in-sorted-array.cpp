class Solution {
public:
    int first(vector<int>&nums,int target,int low,int high,int n){
        if(high>=low){
            int mid=(high+low)/2;
            if((mid==0 || target>nums[mid-1]) && nums[mid]==target)
                return mid;
            else if(target>nums[mid])
                return first(nums,target,mid+1,high,n);
            else
                return first(nums,target,low,mid-1,n);
        }
        return -1;
    }
    int last(vector<int>&nums,int target,int low,int high,int n){
        if(high>=low){
            int mid=(low+high)/2;
            if((mid==n-1 || target<nums[mid+1]) && nums[mid]==target)
                return mid;
            else if(target<nums[mid])
                return last(nums,target,low,mid-1,n);
            else
                return last(nums,target,mid+1,high,n);
        }
        return -1;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans;
        int n= nums.size();
        int f= first(nums,target,0,n-1,n);
        int l=last(nums,target,0,n-1,n);
        ans.push_back(f);
        ans.push_back(l);
        return ans;
    }
};