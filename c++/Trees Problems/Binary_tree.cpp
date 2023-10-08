#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    // constructor
    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};


//MARK:- CREATION OF TREE

node *buildTree(node *root)
{

    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    cout << "Enter the data: " << endl;
    int data;
    cin >> data;
    root = new node(data);

    if (data == -1)
    { // consider -1 as NULL
        return NULL;
    }

    // recursion call
    cout << "Enter data for inserting in left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for inserting in right of " << data << endl;
    root->right = buildTree(root->right);

    return root;
}

//MARK:- LEVEL ORDER TRAVERSAL

// to show in form of tree
// level order traversal and use of separator
void levelOrderTraversal(node *root)
{
    // queue banalo
    queue<node *> q;
    q.push(root);
    q.push(NULL); // separator

    while (!q.empty())
    {
        node *temp = q.front(); // front elment nikal lo
        q.pop();

        // purana level complete hogaya
        if (temp == NULL)
        {
            cout << endl;

            if (!q.empty())
            {
                q.push(NULL); // agar nodes bache hai aur to separator lagana padega n
            }
        }
        else
        {
            cout << temp->data << " ";

            // non null hai to q me push kardiya child ko
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

//MARK:- INORDER
void inorder(node* root){
    //LNR
    //base case
    if(root == NULL){
        return;
    }

    inorder(root->left);
    cout<< root->data <<" ";
    inorder(root->right);
}


//MARK:- PREORDER
void preorder(node* root){
    //NLR
    //base case
    if(root == NULL){
        return;
    }

    cout<< root->data <<" ";
    preorder(root->left); 
    preorder(root->right);
}


//MARK:- POSTORDER
void postorder(node* root){
    //LRN
    //base case
    if(root == NULL){
        return;
    }

    postorder(root->left); 
    postorder(root->right);
    cout<< root->data <<" ";
}


//MARK:- Main

int main()
{

    node *root = NULL;

    // creating tree
    root = buildTree(root);

    // level order
    levelOrderTraversal(root);

    cout<<"Inorder traversal is: "<<endl;
    inorder(root);
    cout<<endl;

    cout<<"Preorder traversal is: "<<endl;
    preorder(root);
    cout<<endl;

    cout<<"Postorder traversal is: "<<endl;
    postorder(root);
    cout<<endl;

    return 0;
}