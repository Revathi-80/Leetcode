class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1=0,cnt2=0;
        int el1=INT_MIN,el2=INT_MIN;
        int n=nums.size();
        for(int i=0;i<n;i++) {
            if(cnt1==0 && el2!=nums[i]) {
                cnt1=1;
                el1=nums[i];
            }
            else if(cnt2==0 && el1!=nums[i]) {
                cnt2=1;
                el2=nums[i];
            }
            else if(el1==nums[i]) cnt1++;
            else if(el2==nums[i]) cnt2++;
            else cnt1--,cnt2--;
        }      
        vector<int>ds;
        cnt1=0,cnt2=0;
        for(int i=0;i<n;i++) {
            if(el1==nums[i]) cnt1++;
            if(el2==nums[i]) cnt2++;
        }
        int mini=(int)(n/3)+1;
        if(cnt1>=mini) ds.push_back(el1);
        if(cnt2>=mini) ds.push_back(el2);
        return ds;
    }
};