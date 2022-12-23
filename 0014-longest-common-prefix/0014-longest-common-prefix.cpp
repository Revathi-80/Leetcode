class Solution {
    string Commonprefix (string s1, string s2) {
        string str="";
        int n= min(s1.size(),s2.size());
        for(int i=0;i<n;i++) {
            if(s1[i]!=s2[i])
                break;
            str+=s1[i];
        }
        return str;
    }
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        string prefix=strs[0];
        for(int i=1;i<n;i++) {
             prefix= Commonprefix(prefix,strs[i]);
        }
        return prefix;
    }
};