//{ Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}

Node* buildTree(int in[], int post[], int n);

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Node* root = buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

//Function to return a tree created from postorder and inoreder traversals.


Node* solve(int in[],int post[],int &index,int inorderStart, int inorderEnd, unordered_map<int,queue<int> > &mp, int n){
        //base case
        if(index < 0 || inorderStart > inorderEnd){
            return NULL;
        }
        
        //find root element ki position in inorder
        //pehla wala uthalo kyuki wo root rehta hai
        int element = post[index--];
        //create a new Node
        Node* root = new Node(element);
        //position find karlo us element ki inorder me
        int position = mp[element].front() ; 
        
        mp[element].pop();
        
        //recursive calls kardo
        //postorder me ulta ja rahe hai isiliye pehle right wala part ayega baad me left wala
        root -> right = solve(in,post,index,position+1,inorderEnd,mp,n);
        //left wala part matlab inorderStart se position-1 tak
        root -> left = solve(in,post,index,inorderStart,position-1,mp,n);
        
    }


Node *buildTree(int in[], int post[], int n) {
    //start from last as in post order root is the last node
        int postOrderIndex = n-1 ;
        // unordered_map<int,queue<int> > nodeToIndex; 
        unordered_map<int,queue<int>>mp;
        //create nodes to nodes mapping
        // createMapping(in,nodeToIndex,n);
        
        //push in map the values and their indexes
        for(int i=0; i<n; i++) {
            mp[in[i]].push(i);
            //mp[in[i]] matlab queue ko access kar rahe hai to usme push kardo
        }
        
        Node * ans = solve(in,post,postOrderIndex,0,n-1,mp, n);
        
        return ans;
}
