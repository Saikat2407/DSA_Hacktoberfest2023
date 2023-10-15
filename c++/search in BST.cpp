#include<iostream>
#include<queue>
using namespace std;


class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this-> data = data;
        this -> left = NULL;
        this -> right = NULL;
    }
};

Node* createNode(Node* &root,int data){
    if(root == NULL){
        root = new Node(data);
        return root;
    }

    if(root -> data > data){
        root -> left = createNode(root -> left,data);
    }
    else{
        root -> right = createNode(root -> right,data);
    }

    return root;
}

void takeInput(Node* &root){
    int data;
    cin>>data;
    if(data == -1) return;
    createNode(root,data);
    while(data != -1){
        cin>>data;
        if(data!=-1)
        createNode(root,data);
    }
}

void levelOrderTraversal(Node* root){
    if(root == NULL) return ;
    queue<Node*> q;

    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if(temp == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }else{
            cout<<temp -> data<<" ";
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
    }
}

void preoder(Node* root){
    if(root == NULL){
        return;
    }

    cout<<root -> data<<" ";
    preoder(root -> left);
    preoder(root -> right);
}
void postorder(Node* root){
    if(root == NULL){
        return;
    }

    postorder(root -> left);
    postorder(root -> right);
    cout<<root -> data<<" ";
}
void Inorder(Node* root){
    if(root == NULL){
        return;
    }

    Inorder(root -> left);
    cout<<root -> data<<" ";
    Inorder(root -> right);
}

bool findInBST(Node* root,int target){
    if(root == NULL) return false;

    if(root -> data == target) return true;

    if(target > root -> data) return findInBST(root -> right,target);
    else return findInBST(root -> left,target);
}

int minVal(Node* root){
    if(root == NULL) return -1;
    Node* temp = root;

    while(temp -> left != NULL){
        temp = temp -> left;
    }

    return temp->data;
}
int maxVal(Node* root){
    if(root == NULL) return -1;
    Node* temp = root;

    while(temp -> right != NULL){
        temp = temp -> right;
    }

    return temp->data;
}

int main(){
    Node* root = NULL;
    cout<<"Enter data -> ";
    takeInput(root);
    cout<<"\n printing Level order : \n";
    levelOrderTraversal(root);
    cout<<"\n printing preorder : \n";
    preoder(root);
    cout<<"\n printing postorder : \n";
    postorder(root);
    cout<<"\n printing Inorder : \n";
    Inorder(root);
    cout<<"Checking presence -->> "<<findInBST(root,10)<<endl;
    cout<<"Minimum value : "<<minVal(root)<<endl;
    cout<<"Maximum value : "<<maxVal(root);
    return 0;
}
