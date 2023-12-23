class Solution {
public:
    bool isPathCrossing(string path) {
        int n = path.size();
        set<pair<int,int>>st;
        int x=0,y=0;
        st.insert({0,0});
        for(int i=0;i<n;i++) {
            
            if(path[i]=='N') {
               ++y;
            }
            else if(path[i]=='S') --y;
            else if(path[i]=='E') ++x;
            else if(path[i]=='W') --x;
            cout<<x<<" "<<y<<endl;
            if(st.find({x,y})!=st.end()) return true;
            st.insert({x,y});
        }
        return false;
    }
};