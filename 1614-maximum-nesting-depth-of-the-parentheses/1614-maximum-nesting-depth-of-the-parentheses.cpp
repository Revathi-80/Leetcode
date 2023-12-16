class Solution {
public:
    int maxDepth(string s) {
        stack<char>st;
        int cnt=0;
        for(int i=0;i<s.size();i++) {
            if(s[i]=='(') {
                st.push('(');
            }
            if(s[i]==')' && st.size()>0)
                st.pop();
            // if(st.size()>1){
                if(cnt<st.size())
                cnt= st.size();
        }
        return cnt;
    }
};