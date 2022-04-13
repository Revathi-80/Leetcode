class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int r1=0,r2=n-1,c1=0,c2=n-1;
        int val=0;
        vector<vector<int>>v(n,vector<int>(n));
        while(r1<=r2 && c1<=c2){
            for(int i=c1;i<=c2;i++) //left to right
                v[r1][i]=++val;
            for(int j=r1+1;j<=r2;j++) //top to bottom
                v[j][c2]=++val;
            for(int i=c2-1;i>=c1;i--) //right to left
                v[r2][i]=++val;
            for(int j=r2-1;j>r1;j-- ) //bottom to up
                v[j][c1]=++val;
            r1++;
            c1++,r2--,c2--;
        }
        return v;
    }
};