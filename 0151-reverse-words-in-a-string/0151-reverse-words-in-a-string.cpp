class Solution {
public:
    string reverseWords(string s) {
        vector<string>ans;
        //break
        stringstream st(s);
        //individual word 
        string word;
        while(st>>word) {
            ans.push_back(word);
        }
        string res="";
        reverse(ans.begin(),ans.end());
        for(int i=0;i<ans.size();i++) {
    
            res+=ans[i];
            if(i!=ans.size()-1) res+= " ";
            
        }
        return res;
    }
};