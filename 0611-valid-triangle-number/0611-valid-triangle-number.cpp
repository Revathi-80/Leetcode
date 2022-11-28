class Solution {
    int binary(vector<int>&nums,int l,int r,int x){
        while(l<=r && r<nums.size()){
            int mid=(l+r)/2;
            if(x<=nums[mid]) {
                r=mid-1;
            }
            else 
                l=mid+1;
        }
        return l;
    }
public:
    int triangleNumber(vector<int>& nums) {
        int cnt=0;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++) {
              
                int t=nums[i]+nums[j];
                int L=j,R=nums.size()-1;
                while(L<=R) {
                    int mid= (L+R)/2;
                    if((mid==j || t>nums[mid]) && (mid+1>=n || t<=nums[mid+1])){
                        cnt+= mid-j;
                        break;
                    }
                    if(mid==j || t>nums[mid])
                        L=mid+1;
                    else
                        R=mid-1;
                } 
            }
        }
        return cnt;
    }
};