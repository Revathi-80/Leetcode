class Solution {
public:
    bool halvesAreAlike(string s) {
        int n= s.size();
        int cnt1=0,cnt2=0;
        for(int i=0;i<n/2;i++){
            char ch= tolower(s[i]);
            if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')
                cnt1++;
        }
        for(int i=n/2;i<n;i++){
            char ch= tolower(s[i]);
            if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')
                cnt2++;
        }
        if(cnt1==cnt2)
            return true;
        else
            return false;
    }
};