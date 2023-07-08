class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n=weights.size();
        vector<int>arr(n-1,0);
        for(int i=0;i<n-1;i++){
            arr[i]=weights[i]+weights[i+1];
        }
        sort(arr.begin(),arr.end());
        long long mini=0,maxi=0;
        for(int i=0;i<k-1;i++){
            mini += arr[i];
            maxi += arr[n-2-i];
        }
        return maxi-mini;
    }
};