class Solution
{
    public:
        int findContentChildren(vector<int> &g, vector<int> &s)
        {
            int cnt = 0, n = g.size(), i = 0, j = 0,m=s.size();
            sort(g.begin(), g.end());
            sort(s.begin(), s.end());
            while (j < n && i<m) {
                if(g[j]<=s[i]) {
                    cnt++;
                   j++;
                }
                i++;
            }
            return cnt;
        }
};