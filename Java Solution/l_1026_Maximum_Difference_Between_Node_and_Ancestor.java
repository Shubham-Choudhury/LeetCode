// Link: https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/description/

class l_1026_Maximum_Difference_Between_Node_and_Ancestor {
    public int maxAncestorDiff(TreeNode root) {
        return maxAncestorDiff(root, root.val, root.val);
    }

    public int maxAncestorDiff(TreeNode root, int min, int max) {
        if (root == null)
            return max - min;
        min = Math.min(min, root.val);
        max = Math.max(max, root.val);
        return Math.max(maxAncestorDiff(root.left, min, max), maxAncestorDiff(root.right, min, max));
    }

    public static void main(String[] args) {
        l_1026_Maximum_Difference_Between_Node_and_Ancestor solution = new l_1026_Maximum_Difference_Between_Node_and_Ancestor();
        TreeNode root = new TreeNode(8);
        root.left = new TreeNode(3);
        root.right = new TreeNode(10);
        root.left.left = new TreeNode(1);
        root.left.right = new TreeNode(6);
        root.left.right.left = new TreeNode(4);
        root.left.right.right = new TreeNode(7);
        root.right.right = new TreeNode(14);
        root.right.right.left = new TreeNode(13);
        System.out.println(solution.maxAncestorDiff(root));
    }
}

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode() {
    }

    TreeNode(int val) {
        this.val = val;
    }

    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}