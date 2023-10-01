// Leetcode Problem 987
// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

// Solution

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        queue<pair<TreeNode*,pair<int,int>>> q;
        map<int,map<int,vector<int>>> nodes;

        if(root==NULL){
            return ans;
        }
        q.push(make_pair(root,make_pair(0,0) ));

        while(!q.empty()){
            pair<TreeNode*,pair<int,int>> curr=q.front();
            q.pop();
            TreeNode* node=curr.first;
            int lvl=curr.second.first;
            int hd=curr.second.second;

            if(node->left){
                q.push(make_pair(node->left,make_pair(lvl+1,hd-1)));
            }
            if(node->right){
                q.push(make_pair(node->right,make_pair(lvl+1,hd+1)));
            }

            nodes[hd][lvl].push_back(node->val);
        }

        for(auto i:nodes){
            int l=INT_MIN;
            vector<int> vertical;
            for(auto j:i.second){
                sort(j.second.begin(),j.second.end());
                for(auto k: j.second){
                    vertical.push_back(k);
                }
            }
            ans.push_back(vertical);
        }
        return ans;
    }
};