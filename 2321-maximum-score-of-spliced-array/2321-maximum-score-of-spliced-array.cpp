class Solution {
    int maximum_subarray(vector<int>nums) {
        int n=nums.size();
        int sum=0,maxi=INT_MIN;
        for(int i=0;i<n;i++) {
            sum+=nums[i];
            maxi=max(maxi,sum);
            if(sum<0) {
                sum=0;
            }
        }
        return maxi;
    }
public:
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        vector<int>v1(n);  // nums2-nums1
        vector<int>v2(n); //nums1-nums2
        int sum1=0,sum2=0;
        for(int i=0;i<n;i++) {
            sum1+=nums1[i];
            sum2+=nums2[i];
        }
        for(int i=0;i<n;i++) {
            v1[i]=nums2[i]-nums1[i];
            v2[i]=nums1[i]-nums2[i];
        }
        int maxi1= maximum_subarray(v1);
        int maxi2= maximum_subarray(v2);
        int ans1= maxi1+sum1;
        int ans2= maxi2+sum2;
        //cout<<sum1<<" "<< sum2<<" "<< maxi1<<" "<<maxi2<<" "<< ans1<<" "<<ans2<<endl;
        return max(ans1,ans2);
        
    }
};