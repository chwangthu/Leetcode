class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaves1 = getLeaves(root1);
        vector<int> leaves2 = getLeaves(root2);
        if(leaves1.size() != leaves2.size()) return false;
        for(int i = 0; i < leaves1.size(); i++) {
            if(leaves1[i] != leaves2[i]) return false;
        }
        return true;
    }
    vector<int> getLeaves(TreeNode* root) {
        if(root -> left == NULL && root -> right == NULL) {
            vector<int> res;
            res.push_back(root -> val);
            return res;
        }
        vector<int> leftLeaves = {}; vector<int> rightLeaves = {};
        if(root -> left) leftLeaves = getLeaves(root -> left);
        if(root -> right) rightLeaves = getLeaves(root -> right);
		leftLeaves.insert(leftLeaves.end(), rightLeaves.begin(), rightLeaves.end());
        return leftLeaves;
    }
};