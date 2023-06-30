class Solution {
    int maxi(vector<int>&piles,int n) {
        int ans=piles[0];
        for(int i=1;i<n;i++){
            ans=max(ans,piles[i]);
        }
        return ans;
    }
    bool check(vector<int>&piles,int h,int mid){
        long time=0;
        for(long x: piles){
            time += (x)/mid;
            if(x%mid!=0) time++;
        }
        return (time<=h);
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int low=1;
        int high=maxi(piles,n);
        while(low<=high){
            int mid= low +(high-low)/2;
            
            if(check(piles,h,mid)){
                high=mid-1;
            }
            else {
                low=mid+1;
            }
        }
        return low;
    }
};