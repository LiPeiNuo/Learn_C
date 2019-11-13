package BinaryTree;
class Node {
    public char val;
    public Node left;
    public Node right;

    public Node(char val) {
        this.val = val;
    }
}
public class BinaryTree {
    private  static  Node root = null;
    public static Node build(){
        Node A = new Node('A');
        Node B = new Node('B');
        Node C = new Node('C');
        Node D = new Node('D');
        Node E = new Node('E');
        Node F = new Node('F');
        Node G = new Node('G');
        A.left = B;
        A.right = C;
        B.left = D;
        B.right = E;
        E.left = G;
        C.right = F;
        return A;
    }
    //先序遍历
    public static void prevOrder(Node root){
        //先访问根节点，递归遍历左子树，递归遍历右子数
        if(root == null){
            return;
        }
        System.out.print(root.val);
        prevOrder(root.left);
        prevOrder(root.right);
    }

    //中序遍历
    public static void inOrder(Node root){
        if(root == null){
            return;
        }
        inOrder(root.left);
        System.out.print(root.val);
        inOrder(root.right);
    }
    //后序遍历
    public static void postOrder(Node root){
        if(root == null){
            return;
        }
        postOrder(root.left);
        postOrder(root.right);
        System.out.print(root.val);
    }

    //求节点个数
    public static int size(Node root){
        if(root == null){
            return 0;
        }
        else if(root.left == null && root.right == null){
            return 1;
        }
        return 1 + size(root.left) + size(root.right);
    }

    //求叶节点个数
    public static int leafSize(Node root){
        if(root == null){
            return 0;
        }
        else if(root.left == null && root.right == null){
            return 1;
        }
        return leafSize(root.right) + leafSize(root.left);
    }

    //求第k层节点个数
    public static int getKLevelSize(Node root, int k){
        if(k < 1 || root == null){
            return 0;
        }
        if(k == 1){
            return 1;
        }
        return getKLevelSize(root.left,k-1) + getKLevelSize(root.right,k - 1);
    }

    public static void main(String[] args){
        root = build();
        prevOrder(root);
        System.out.println();
        inOrder(root);
        System.out.println();
        postOrder(root);
        System.out.println();
        System.out.println("节点个数为：" + size(root));
        System.out.println("叶节点的个数为：" + leafSize(root));
        System.out.println("第3层节点的个数为：" + getKLevelSize(root,3));
    }
}
