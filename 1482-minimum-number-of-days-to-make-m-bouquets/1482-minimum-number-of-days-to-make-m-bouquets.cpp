class Solution {
    bool possible(vector<int>&bloomDay,int day,int m,int k){
        int cnt=0,boq=0;
        int n=bloomDay.size();
        for(int i=0;i<n;i++){
            if(bloomDay[i]<=day)
                cnt++;
            else {
                boq += (cnt/k);
                cnt=0;
            }
        }
        boq += (cnt/k);
        return boq>=m;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        long total =m*1LL*k*1LL;
        if(n<total)
            return -1;
        int mini=INT_MAX,maxi=INT_MIN;
        for(int i=0;i<n;i++){
            mini= min(mini,bloomDay[i]);
            maxi=max(maxi,bloomDay[i]);
        }
        int low=mini,high=maxi;
        while(low<=high){
            int mid= low + (high-low)/2;
            if(possible(bloomDay,mid,m,k)){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};