class Solution {
    void func(int n, vector<string>&ans, string temp,int i=0,int j=0) {
        
        if(i==n && j==n) { //number of opening and closing brackets are equal to n
            ans.push_back(temp);
            return;
        }
        //opening
        if(i+1<=n) {
            temp.push_back('(');
            func(n,ans,temp,i+1,j);
            temp.pop_back();
        }
        
        //closing
        if(j+1<=n && j+1<=i) {
            temp.push_back(')');
            func(n,ans,temp,i,j+1);
            temp.pop_back();
        }
        
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string temp;
        func(n,ans,temp);
        return ans;
    }
};