class Solution {
private:
    int count(int x){
        int sum=0;
        while(x!=0) {
            sum++;
            x&=(x-1);
        }
        return sum;
    }
public:
    vector<int> countBits(int n) {
       vector<int>ans(n+1);
        for(int i=0;i<=n;i++){
            ans[i]=count(i);
        }
        return ans;
    }
};