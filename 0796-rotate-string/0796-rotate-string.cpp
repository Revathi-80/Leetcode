class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()) return false;
        string str= s+s;
        // cout<<str<<" "<<str.find(goal);
        return str.find(goal)!=string::npos;
    }
};