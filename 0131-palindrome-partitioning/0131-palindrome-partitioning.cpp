class Solution {
     void subsets(string s,int index, vector<string>&ds, vector<vector<string>>&ans) {

        //base case
        if(index==s.size()){
                ans.push_back(ds);
            return;
        }
       for(int i=index;i<s.size();i++) {
           if(palindrome(s,index,i)) {
               ds.push_back(s.substr(index,i-index+1));
               subsets(s,i+1,ds,ans);
               ds.pop_back();
           }
       }
    }
        bool palindrome(string s, int start, int end) {
        while(start<=end) {
            if(s[start++]!=s[end--])
                return false;
        }
        return true;
    }
public:
    vector<vector<string>> partition(string s) {
         vector<string>ds;
        vector<vector<string>>ans;
        subsets(s,0,ds,ans);
        return ans;
    }
};