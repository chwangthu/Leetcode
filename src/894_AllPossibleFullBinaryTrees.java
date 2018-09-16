/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
  public List<TreeNode> allPossibleFBT(int N) {
    List<TreeNode> l = new ArrayList<TreeNode>();
    if(N==1) {
      l.add(new TreeNode(0));
      return l;
    }
    for(int i=1; i<N; i+=2) {
      List<TreeNode> L = allPossibleFBT(i), R = allPossibleFBT(N-1-i);
      for(int j=0; j<L.size(); j++) {
        for(int k=0; k<R.size(); k++) {
          TreeNode node = new TreeNode(0);
          node.left=L.get(j); node.right=R.get(k);
          l.add(node);
        }
      }
    }
    return l;
  }
}
