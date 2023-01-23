class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
       vector<pair<int,int>>mp(n+1,{0,0});
        
        for(int i=0;i<trust.size();i++) {
            mp[trust[i][0]].first+=1; // kitno ko trust kr raha h
            mp[trust[i][1]].second+=1; // kitne iss pe trust kr rhe h
        }
        for(int i=1;i<=n;i++) {
            // kisiko trust nhi kr raha aur sb is pe trust kr rhe
            if(mp[i].first==0 && mp[i].second==n-1)
                return i;
        }
        return -1;
    }
};