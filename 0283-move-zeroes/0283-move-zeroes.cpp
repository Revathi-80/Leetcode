class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int j=-1;
        for(int i=0;i<n;i++) {
            if(nums[i]==0){
                j=i;
                break;
            }
        }
        if(j==-1) j=n;
        for(int i=j+1;i<n;i++) {
            if(nums[i]!=0){
            swap(nums[j],nums[i]);
                j++;
            }
        }
    }
};


// brute force
// int n=nums.size();
//         vector<int>temp;
//         for(int i=0;i<n;i++) {        //O(n)
//             if(nums[i]!=0)
//                 temp.push_back(nums[i]);
//         }
//         int k= temp.size();
//         for(int i=0;i<k;i++) {
//             nums[i]=temp[i];
//         }
//         for(int i=k;i<n;i++) {
//             nums[i]=0;
//         }