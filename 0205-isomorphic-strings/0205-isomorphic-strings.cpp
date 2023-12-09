class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<int,int>mpp1,mpp2;
        
        if(s.length() != t.length()) {
            return false;
        }
        for(int i=0;i<s.length();i++) {
            if(mpp1[s[i]] != mpp2[t[i]])
                return false;
            
            mpp1[s[i]] = i+1;
            mpp2[t[i]] = i+1;
        }
        return true;
    
    }
};