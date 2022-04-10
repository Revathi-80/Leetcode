class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxi=0;
        int i=0,j=height.size()-1;
        while(i<j){
            int x= min(height[i],height[j])*(j-i);
            if(x>maxi)
                maxi=x;
            if(height[i]<height[j])
                i++;
            else
                j--;
        }
        return maxi;
    }
};