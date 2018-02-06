/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//6 Feb 2018
//Recursive edition, overload Function inorderTranversal
class Solution {
public:
    void inorderTranversal(TreeNode* root, vector<int>& res)
    {
        if(root -> left) inorderTranversal(root -> left, res);
        res.push_back(root -> val);
        if(root -> right) inorderTranversal(root -> right, res);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root == NULL) return ans;
        inorderTranversal(root, ans);
        return ans;
    }
};

//Iterative edition
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> s;
        TreeNode* cur = root;
        while(cur != NULL || !s.empty())
        {
            while(cur != NULL)
            {
                s.push(cur);
                cur = cur -> left;
            }
            cur = s.top();
            s.pop();
            ans.push_back(cur -> val);
            cur = cur -> right;
        }
        return ans;
    }
};

//Morris Method
class Solution {
     vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode curr = root;
        TreeNode pre;
        while (curr != null) {
            if (curr -> left == null) {
                ans.push_back(curr -> val);
                curr = curr -> right; // move to next right node
            } else { // has a left subtree
                pre = curr -> left;
                while (pre -> right != null) { // find rightmost
                    pre = pre -> right;
                }
                pre -> right = curr; // put cur after the pre node
                TreeNode* temp = curr; // store cur node
                curr = curr -> left; // move cur to the top of the new tree
                temp -> left = null; // original cur left be null, avoid infinite loops
            }
        }
        return ans;
    }
}