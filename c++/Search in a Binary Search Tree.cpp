class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == NULL)
        {
            return NULL;
        }
        if(root->val > val){
            return searchBST(root->left,val);
        }
        if(root->val < val){
            return searchBST(root->right,val);
        }
        else return root;
    }
};
// Link for the Question : https://leetcode.com/problems/search-in-a-binary-search-tree/description/