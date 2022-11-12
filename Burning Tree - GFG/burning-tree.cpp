//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

class Solution {
    int minTime(Node* start,map<Node*,Node*>&mp){
        queue<Node*>q;
        q.push(start);
        map<Node*,int>vis;
        vis[start]=1;
        int time=0;
        while(!q.empty()){
            int fl=0;
            int size=q.size();
            for(int i=0;i<size;i++){
                Node*node=q.front();
                vis[node]=1;
                q.pop();
                //left
                if(node->left && !vis[node->left]){
                    q.push(node->left);
                    vis[node->left]=1;
                    fl=1;
                }
                //right
                if(node->right && !vis[node->right]){
                    q.push(node->right);
                    vis[node->right]=1;
                    fl=1;
                }
                //top
                if(mp[node] && !vis[mp[node]]){
                    q.push(mp[node]);
                    vis[mp[node]]=1;
                    fl=1;
                }
            }
            if(fl)
            time++;
        }
        return time;
        
    }
    Node * bfsParent(Node* root, int target, map<Node*,Node*>&mp) {
        queue<Node*>q;
        q.push(root);
        Node* res;
        while(!q.empty()){
            Node* node=q.front();
            if(node->data==target) res=node;
            q.pop();
            if(node->left){
                q.push(node->left);
                mp[node->left]=node;
            }
            if(node->right) {
                q.push(node->right);
                mp[node->right]=node;
            }
        }
        return res;
    }
  public:
    int minTime(Node* root, int target) 
    {
        map<Node*,Node*>mp;
        Node * start= bfsParent(root,target,mp);
        int maxi=minTime(start,mp);
        return maxi;
    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends