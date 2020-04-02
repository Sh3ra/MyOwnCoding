import java.util.List;
import java.util.ArrayList;
/**
 * full_binary_tree
 */
public class full_binary_tree {

    public static class TreeNode {
             int val;
             TreeNode left;
             TreeNode right;
             TreeNode(int x) { val = x; }
         }
         
    static List<TreeNode> list=new ArrayList<TreeNode>();

    public static List<TreeNode> allPossibleFBT(int N) {
        TreeNode treeNode = new TreeNode(0);
        list.add(treeNode);
        return list;
    }

    public static void main(String[] args) {
        for (TreeNode element : allPossibleFBT(7)) {
            System.out.println(element.val);
        }
    }
}