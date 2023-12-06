class Solution {
public:
    string removeOuterParentheses(string s) {
        // stack<char>st;
        string ans="";
        int cnt=0;
        for(int i=0;i<s.size();i++) {
            if(s[i]=='(' ) {
                if(cnt>0) ans+=s[i];
                cnt++;
                
            } 
            else {
                cnt--;
                if(cnt>0) {
                    ans+=s[i];
                }
            
            }
        }
        return ans;
    }
};