class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int>mpp;
        int n = matches.size();
        for(int i=0;i<n;i++) {
            mpp[matches[i][0]]=0;
        }
        for(int i=0;i<n;i++){
             mpp[matches[i][1]]++;
        }
        vector<vector<int>>ans;
        vector<int>temp1,temp2;
        for(auto x:mpp) {
            if(x.second==0){
                temp1.push_back(x.first);
            }
            if(x.second==1){
                temp2.push_back(x.first);
            }
        }
        sort(temp1.begin(),temp1.end());
        sort(temp2.begin(),temp2.end());
        ans.push_back(temp1);
        ans.push_back(temp2);
        return ans;
    }
};