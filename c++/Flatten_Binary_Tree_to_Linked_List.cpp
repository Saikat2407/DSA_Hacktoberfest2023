class Solution {
public:
    void flatten(TreeNode* root) {
        //Iterate through the TreeNode iteratively in the preorder fashion.
      TreeNode* curr=root;
      while(curr!=NULL){
          if(curr->left){
              TreeNode* pred=curr->left;
              while(pred->right){
                  pred=pred->right;
              }
          //If you find a left pointer, go to the rightmost Node (Last node in the subtree's preorder traversal), and join with the current node's right node
          pred->right=curr->right;

         // Then overwrite curr->right with the left subtree (It now contains the right subtree)
          curr->right=curr->left;

        //  Make curr->left = NULL, since all nodes have to be to the right.
          curr->left=NULL;
      }  
      curr=curr->right;
      }
    }
};
