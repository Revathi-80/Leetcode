class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        set<int>ans;
        vector<int>v;
        int num1=-1,num2=-1,cnt1=0,cnt2=0;
        for(int ele:nums) {
            if(ele==num1)
                cnt1++;
            else if(ele==num2)
                cnt2++;
            else if(cnt1==0) {
                num1=ele;
                cnt1=1;
            }
            else if(cnt2==0) {
                num2=ele;
                cnt2=1;
            }
            else {
                cnt1--;
                cnt2--;
            }
        }
        int count1=0,count2=0;
        for(int i:nums) {
            if(i==num1)
                count1++;
            if(i==num2)
                count2++;
        }
        if(count1>nums.size()/3)
            ans.insert(num1);
        if(count2>nums.size()/3)
            ans.insert(num2);
        for(int x:ans)
            v.push_back(x);
        return v;
        
    }
};