//11 Feb 2018
//Get the inorder Tranveral and find minimum distance between adjancent nodes
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
    int minDiffInBST(TreeNode* root) {
        vector<int> inorder;
        inorder = inorderTraversal(root);
        int min = INT_MAX;
        for(int i = 1; i < inorder.size(); i++)
        {
            int tep = inorder[i] - inorder[i-1];
            if(tep < min) min = tep;
        }
        return min;
    }
};