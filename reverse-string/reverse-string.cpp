class Solution {
    void reverseStr(vector<char>&s,int i) {
        int n=s.size();
        if(i==n/2)
            return;
        swap(s[i],s[n-i-1]);
        reverseStr(s,i+1);
    }
public:
    void reverseString(vector<char>& s) {
        reverseStr(s,0);
    }
};