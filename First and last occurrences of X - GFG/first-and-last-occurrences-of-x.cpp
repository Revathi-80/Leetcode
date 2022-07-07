// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
  int first(vector<int>&arr,int low, int high,int x,int n){
      if(high>=low){
          int mid=(low+high)/2;
          if((mid==0 || x>arr[mid-1])&& x==arr[mid])
          return mid;
          else if(x>arr[mid])
          return first(arr,mid+1,high,x,n);
          else
          return first(arr,low,mid-1,x,n);
      }
      return -1;
  }
  int last(vector<int>&arr,int low, int high,int x,int n){
      if(high>=low){
          int mid=(low+high)/2;
          if((mid==n-1 || x<arr[mid+1])&& x==arr[mid])
          return mid;
          else if(x<arr[mid])
          return last(arr,low,mid-1,x,n);
          else
          return last(arr,mid+1,high,x,n);
      }
      return -1;
  }
    vector<int> firstAndLast(vector<int> &arr, int n, int x) {
        vector<int>ans;
        int f=first(arr,0,n-1,x,n);
        int l=last(arr,0,n-1,x,n);
        if(f==-1 && l==-1)
        ans.push_back(f);
        else{
        ans.push_back(f);
        ans.push_back(l);
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        Solution obj;
        vector<int> ans= obj.firstAndLast(arr, n, x) ;
        for(int i:ans){
            cout<<i<<" ";
        }
        cout<< endl;
    }
    return 0;
}
  // } Driver Code Ends