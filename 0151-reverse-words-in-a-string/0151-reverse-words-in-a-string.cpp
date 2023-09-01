class Solution {
public:
    string reverseWords(string s) {
        vector<string>vec;
        stringstream ss(s);
        string word;
        while(ss>>word) {
            vec.push_back(word);
        }
        string ans="";
        for(int i=vec.size()-1;i>=0;i--) {
            ans+=vec[i];
            if(i!=0)
            ans+=" ";
        }
        return ans;
    }
};