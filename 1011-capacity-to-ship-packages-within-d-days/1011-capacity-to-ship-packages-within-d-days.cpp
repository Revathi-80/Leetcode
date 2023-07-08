class Solution {
    bool possible(vector<int>& weights,int days,int mid){
        int cnt=1,sum=0;
        int n=weights.size();
        for(int i=0;i<n;i++){
            if(sum+weights[i]>mid){
                sum=weights[i];
                cnt=cnt+1;
            }
            else{
                sum +=weights[i];
            }
        }
    
        return cnt<=days;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low=INT_MIN,high=0;
        for(int i=0;i<weights.size();i++) {
            high+=weights[i];
            low=max(low,weights[i]);
        }
        while(low<=high) {
            int mid= low + (high-low)/2;
            if(possible(weights,days,mid))
                high=mid-1;
            else
                low=mid+1;
        }
        return low;
    }
};