class Solution {
    string commonStr(string & p, string &t) {
        string s="";
        int n= min(p.size(),t.size());
        for(int i=0;i<n;i++) {
            if(p[i]!=t[i]) break;
            s+=p[i];
        }
        return s;
    }
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        int n=strs.size();
        string p=strs[0];
        for(int i=1;i<n;i++) {
            p=commonStr(p,strs[i]);
        }
        return p;
    }
};