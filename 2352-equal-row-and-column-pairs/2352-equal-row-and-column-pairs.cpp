class Solution {
    string func(vector<int>grid){
        string ans="";
        for(int i=0;i<grid.size();i++){
            ans+=to_string(grid[i]);
            ans+="#";
        }
        return ans;
    }
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        map<string,int>mpp;
        for (int i=0;i<n;i++){
            mpp[func(grid[i])]++;
        }
        int cnt=0;
        for (auto it:mpp) cout<<it.first<<" "<<it.second<<endl;
        for(int i=0;i<n;i++){
            string ans="";
            for(int j=0;j<n;j++){
                ans+=to_string(grid[j][i]);
                ans+="#";
            }
            
            cnt+=mpp[ans];
        }
        return cnt;
    }
};