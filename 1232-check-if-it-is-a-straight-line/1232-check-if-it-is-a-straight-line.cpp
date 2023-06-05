class Solution {
    int xDiff(vector<int>&a,vector<int>&b){
        return a[0]-b[0];
    }
    int yDiff(vector<int>&a,vector<int>&b){
        return a[1]-b[1];
    }
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
       int x=xDiff(coordinates[0],coordinates[1]);
       int y=yDiff(coordinates[0],coordinates[1]);
        for(int i=2;i<coordinates.size();i++){
            if(x*yDiff(coordinates[0],coordinates[i])!= y*xDiff(coordinates[0],coordinates[i]))
                return false;
        }
        return true;
    }
};