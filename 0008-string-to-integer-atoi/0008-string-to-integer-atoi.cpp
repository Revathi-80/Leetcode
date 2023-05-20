class Solution {
public:
    int myAtoi(string s) {
        int n=s.size();
        int res=0;
        int neg=1;
        int i=0;
        while(i<n && s[i]==' ') i++;
        if(s[i]=='-' ||s[i]=='+') {
            neg=s[i]=='-'?-1:1;
            i++;
        }
        while(i<n && (s[i]>='0' && s[i]<='9')) {
                 
                 int digit= (s[i]-'0')*neg;
                 if(neg==1 && (res>INT_MAX/10 || (res==INT_MAX/10 && digit>INT_MAX%10)))
                     return INT_MAX;
                  if(neg==-1 && (res<INT_MIN/10 || (res==INT_MIN/10 && digit<INT_MIN%10)))
                      return INT_MIN;
                res=res*10+digit;
               i++;
        }
        
        return res;
    }
};