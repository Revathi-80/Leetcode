class Solution {
public:
    bool check(string &s,int n,int i){
        if(i>=n/2)
            return true;
        if(s[i]!=s[n-i-1])
            return false;
        else
            return check(s,n,i+1);
    }
    bool isPalindrome(string s) {
        string str="";
        int n=s.length();
    for(int i=0;i<n;i++){
        if((s[i]>=65 && s[i]<=90)  )
            str+=tolower(s[i]);
        if(s[i]>=97 && s[i]<=122)
            str+=s[i];
        if(s[i]>=48 && s[i]<=57)
            str+=s[i];
    }    
       //cout<<str;
        int m=str.length();
      return  check(str,m,0);
    }
};
