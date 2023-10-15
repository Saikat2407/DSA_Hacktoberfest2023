import java.util.ArrayList;
import java.util.List;

class TreeNode {
    int val;
    List<TreeNode> children;

    public TreeNode(int val) {
        this.val = val;
        this.children = new ArrayList<>();
    }
}

public class TreeDiameterCalculator {
    private int diameter;

    public int diameterOfTree(TreeNode root) {
        diameter = 0;
        dfs(root);
        return diameter;
    }

    private int dfs(TreeNode node) {
        if (node == null) {
            return 0;
        }

        // Calculate the depths of the children
        List<Integer> childDepths = new ArrayList<>();
        for (TreeNode child : node.children) {
            childDepths.add(dfs(child));
        }

        // Sort the depths in descending order
        childDepths.sort((a, b) -> b - a);

        // Calculate the diameter of the tree rooted at this node
        if (childDepths.size() >= 2) {
            diameter = Math.max(diameter, childDepths.get(0) + childDepths.get(1) + 2);
        }

        // Return the depth of the tree rooted at this node
        return (childDepths.isEmpty() ? 0 : childDepths.get(0)) + 1;
    }

    public static void main(String[] args) {
        // Example usage:
        // Create a tree
        TreeNode root = new TreeNode(1);
        root.children.add(new TreeNode(2));
        root.children.add(new TreeNode(3));
        root.children.get(0).children.add(new TreeNode(4));
        root.children.get(0).children.add(new TreeNode(5));
        root.children.get(1).children.add(new TreeNode(6));
        root.children.get(1).children.add(new TreeNode(7));

        TreeDiameterCalculator calculator = new TreeDiameterCalculator();
        int treeDiameter = calculator.diameterOfTree(root);
        System.out.println("Diameter of the tree: " + treeDiameter); // Output should be 4
    }
}
