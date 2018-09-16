//Feb 6 2018
//Using the code in Problem 94(Get the inorder sequence)
//check if the sequence is ordered
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
    bool isValidBST(TreeNode* root) {
        if(root == NULL) return true;
        if(!root -> left && !root -> right) return true;
        vector<int> inorder = inorderTraversal(root);
        for(int i = 0; i < inorder.size() - 1; i++)
        {
            if(inorder[i] >= inorder[i+1]) return false;
        }
        return true;
    }
};