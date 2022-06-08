class Solution {
public:
    int removePalindromeSub(string s) {
      return 2- equal(s.begin(),s.end(),s.rbegin()) -s.empty();  
    }
};