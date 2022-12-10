// Link: https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/


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

class l_1339_Maximum_Product_of_Splitted_Binary_Tree {
    long max = 0;

    public int maxProduct(TreeNode root) {
        if (root == null)
            return 0;

        max = root.val;
        long total = sum(root);
        System.out.println(total);
        helper(root, total);
        return (int) (max % (Math.pow(10, 9) + 7));
    }

    private long helper(TreeNode root, long total) {
        if (root == null)
            return 0;
        long left = helper(root.left, total);
        long right = helper(root.right, total);
        long rem = total - left;
        max = Math.max(max, rem * left);
        rem = total - right;
        max = Math.max(max, rem * right);
        return left + right + root.val;
    }

    private long sum(TreeNode root) {
        if (root == null)
            return 0;
        long left = sum(root.left);
        long right = sum(root.right);
        return left + right + root.val;
    }

    public static void main(String[] args) {
        l_1339_Maximum_Product_of_Splitted_Binary_Tree solution = new l_1339_Maximum_Product_of_Splitted_Binary_Tree();
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(3);
        root.left.left = new TreeNode(4);
        root.left.right = new TreeNode(5);
        root.right.left = new TreeNode(6);
        System.out.println(solution.maxProduct(root));
    }
}
