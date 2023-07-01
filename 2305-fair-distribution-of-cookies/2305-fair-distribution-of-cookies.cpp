class Solution {
private:
    int dfs(vector<int>&cookies,vector<int>&ds,int k,int cnt,int ind){
        int n=cookies.size();
        if(n-ind<cnt) return INT_MAX;
        if(ind==n) return *max_element(ds.begin(),ds.end());
        int ans=INT_MAX;
        for(int j=0;j<k;j++){
            cnt -= ds[j]==0?1:0;
            ds[j] +=cookies[ind];
            ans = min(ans,dfs(cookies,ds,k,cnt,ind+1));
            ds[j] -= cookies[ind];
            cnt += ds[j]==0?1:0;
        }
        return ans;
    }
public:
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int>ds(k);
        return dfs(cookies,ds,k,k,0);
    }
};