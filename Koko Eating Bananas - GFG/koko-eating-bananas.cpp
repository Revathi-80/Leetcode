//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private:
    bool possible(vector<int>&piles, int h, int mid){
        long total=0;
        int n=piles.size();
        for(int i=0;i<n;i++){
            total += (piles[i]+mid-1)/mid;
            if(total>h) return false;
        }
        return total<=h;
    }
  public:
    int Solve(int N, vector<int>& piles, int H) {
        int low=1,high=0;
        for(int i=0;i<N;i++){
            high= max(high,piles[i]);
        }
        while(low<=high){
            int mid = low + (high- low)/2;
            if(possible(piles,H,mid))
                high=mid-1;
            else
                low=mid+1;
        }
        return low;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        int h;
        cin >> h;
        Solution obj;

        cout << obj.Solve(n, a, h);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends