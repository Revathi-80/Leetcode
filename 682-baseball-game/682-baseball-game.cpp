class Solution {
public:
    int calPoints(vector<string>& ops) {
       stack<int>s;
        for(string op:ops){
            if(op=="+"){
                int top=s.top();
                s.pop();
                int ntop=top+s.top();
                s.push(top);
                s.push(ntop);
            }
            else if(op=="C"){
                s.pop();
            }
            else if(op=="D"){
                s.push(2*s.top());
            }
            else {
                s.push(stoi(op));
            }
        }
        int ans=0;
        while(s.size()!=0){
            ans+=s.top();
            s.pop();
        }
        return ans;
    }
};