class Solution {
    bool valid(string &s, int index,int length) {
        return length==1 || (s[index]!='0' && (length<3 || s.substr(index,length)<="255")); 
    }
    
    void backtrack(string &s, int index, vector<int>&dots, vector<string>&ans) {
        int length= s.size()- index;
        int dotsRemain= 4- dots.size();
        
        if(length  > dotsRemain*3 || length< dotsRemain) { //255.222.11.3424
            // 001 (3<4)                                                         
            return;
        }
        
        if(dots.size() ==3 ) {
            // last quadrant
            // check the validity
            if(valid(s,index,length)) {
                string temp;
                int last=0;
                for(int dot: dots) {
                    temp.append(s.substr(last,dot));
                    last+=dot;
                    temp.append(".");
                }
                temp.append(s.substr(index));
                ans.push_back(temp);
            }
            return;
        }
        for(int cur=1;cur<=3 && cur<=length;cur++) {
            dots.push_back(cur);
            if(valid(s,index,cur)) {
                backtrack(s,index+cur,dots,ans); //--
            }
            dots.pop_back();
        }
    }
    
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string>ans;  // store the combinations
        vector<int>dots; // the number of dots inserted
        backtrack(s,0,dots,ans);
        return ans;
        
    }
};