class Solution {
    
public:
    vector<vector<int>>ans;
    int minDistance(string word1, string word2) {
        ans.resize(word1.size()+1,vector<int>(word2.size()+1,0));
        for(int i=0;i<=word1.size();i++){
            for(int j=0;j<=word2.size();j++){
                if(i==0 || j==0)
                    continue;
                if(word1[i-1]==word2[j-1])
                    ans[i][j]=1+ans[i-1][j-1];
                else
                    ans[i][j]=max(ans[i-1][j],ans[i][j-1]);
            }
        }
        return word1.size()+word2.size()-2*ans[word1.size()][word2.size()];
    }
    
};