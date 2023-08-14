class Solution {
    void maxR(vector<int>&height,int n,vector<int>&maxiR) {
        maxiR[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--){
            maxiR[i]=max(height[i],maxiR[i+1]);
        }
        
    }
   void maxL (vector<int>&height, int n,vector<int>&maxiL) {
       
        maxiL[0]=height[0];
        for(int i=1;i<n;i++){
            maxiL[i]=max(height[i],maxiL[i-1]);
        }
        
    }
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int sum=0;
        vector<int>maxiR(n);
        maxR(height,n,maxiR);
        vector<int>maxiL(n);
        maxL(height,n,maxiL);
        vector<int>water(n);
        for(int i=0;i<n;i++){
            water[i]=min(maxiL[i],maxiR[i]) - height[i];
            sum+=water[i];
        }
        return sum;
    }
};