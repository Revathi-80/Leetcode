using extra space to store the index of the row and col containing 0
```
void setZeroes(vector<vector<int>>& matrix) {
int n=matrix.size(),m=matrix[0].size();
set<int>rows;
set<int>cols;
for(int i=0;i<n;i++){
for(int j=0;j<m;j++){
if(matrix[i][j]==0){
rows.insert(i);
cols.insert(j);
}
}
}
for(int i=0;i<n;i++){
for(int j=0;j<m;j++){
if(rows.find(i)!=rows.end() || cols.find(j)!=cols.end() )
matrix[i][j]=0;
}
}
}
```
​
​