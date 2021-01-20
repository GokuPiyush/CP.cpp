/*
Given a Two Binary Trees, write a function that returns true if one is mirror of other, else returns false.
MirrorTree1
*/


#include <bits/stdc++.h>

using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

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
        if (i >= ip.size()) break;
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

int areMirror(Node *, Node *);

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString1, treeString2;
        getline(cin, treeString1);
        Node *root1 = buildTree(treeString1);

        getline(cin, treeString2);
        Node *root2 = buildTree(treeString2);

        cout << areMirror(root1, root2) << "\n";
    }
    return 0;
}// } Driver Code Ends


/* Node structure
struct Node
{
    int data;
    Node* left, *right;
}; */

/* Given two trees, should return true if they are
   mirror of each other. */
int areMirror(Node* a, Node* b) {
    // Your code here
    vector<int> ans1, ans2;
    
    queue<Node*> q1, q2;
    q1.push(a);
    while(!q1.empty()){
        Node * tmp = q1.front();
        ans1.push_back(tmp->data);
        if(tmp->left)
            q1.push(tmp->left);
        if(tmp->right)
            q1.push(tmp->right);
        q1.pop();
    }
    q2.push(b);
    while(!q2.empty()){
        Node * tmp = q2.front();
        ans2.push_back(tmp->data);
        if(tmp->right)
            q2.push(tmp->right);
        if(tmp->left)
            q2.push(tmp->left);
        q2.pop();
    }
    
    if(ans1.size() == ans2.size()){
        for(auto it1=ans1.begin(), it2=ans2.begin(); it1!=ans1.end() && it2!=ans2.end(); it1++, it2++){
            //cout<< *it1<< ' '<< *it2<< endl;
            if(*it1 != *it2){
                return 0;
            }
        }
        return 1;
    }else{
        return 0;
    }
}
