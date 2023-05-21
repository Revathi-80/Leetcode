class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n=numbers.size();
        int i=0,j=n-1;
        while(i<j) {
            int num=numbers[i]+numbers[j];
            if(num==target)
                return {i+1,j+1};
            if(num>target)
                j--;
            else 
                i++;
        }
        return{0,0};
    }
};