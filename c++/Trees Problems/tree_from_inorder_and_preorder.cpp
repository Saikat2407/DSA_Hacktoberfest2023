//{ Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    // void createMapping(int in[],map<int,int> &nodeToIndex,int n){
        
    //     //traverse karke inorder ke index ko store karwalo
    //     for(int i=0; i<n;i++){
    //         nodeToIndex[in[i]] = i;
    //     }
        
    // }
    
    Node* solve(int in[],int pre[],int &index,int inorderStart, int inorderEnd, unordered_map<int,queue<int>>&mp, int n){
        //base case
        if(index >= n || inorderStart > inorderEnd){
            return NULL;
        }
        
        //find root element ki position in inorder
        //pehla wala uthalo kyuki wo root rehta hai
        int element = pre[index++];
        //new Node
        Node* root = new Node(element);
        //position find karlo us element ki inorder me
        int position = mp[element].front() ; 
        
        mp[element].pop();
        
        //recursive calls kardo
        //left wala part matlab inorderStart se position-1 tak
        root -> left = solve(in,pre,index,inorderStart,position-1,mp,n);
        root -> right = solve(in,pre,index,position+1,inorderEnd,mp,n);
    }
    
    Node* buildTree(int in[],int pre[], int n)
    {
        int preOrderIndex = 0 ;
        // map<int,int>nodeToIndex; 
        unordered_map<int,queue<int>>mp;
        //create nodes to nodes mapping
        // createMapping(in,nodeToIndex,n);
        //push in map
        for(int i=0; i<n; i++) {
            mp[in[i]].push(i);
            
        }
        
        Node * ans = solve(in,pre,preOrderIndex,0,n-1,mp,n);
        
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends