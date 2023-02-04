class Solution {
    bool isVectorEqual(vector<int>a,vector<int>b) {
        
        for(int i=0;i<26;i++) {
            if(a[i]!=b[i])
                return false;
        }
        return true;
    }
public:
    
    bool checkInclusion(string s1, string s2) {
        // s1>s2 return false
        if(s1.size()>s2.size()) 
            return false;
        vector<int>hash1(26,0);
        for(int i=0;i<s1.size();i++) {
            hash1[s1[i]-'a']++;
        }
        int i=0,j=0;
        vector<int>hash2(26,0);
        while(j<s2.size()) {
            hash2[s2[j]-'a']++;
            
            if(j-i+1==s1.size()) {
                if(isVectorEqual(hash1,hash2)) 
                    return true;
            }
            
            if(j-i+1<s1.size()) {
                j++;
            }
            else {
                hash2[s2[i]-'a']--;
                i++;
                j++;
            }
        }
        return false;
    }
};