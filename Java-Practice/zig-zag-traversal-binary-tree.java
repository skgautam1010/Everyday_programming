import java.util.*;

class Tree {
    int data;
    Tree left, right;

    Tree(int item) {
        data = item;
        left = right = null;
    }
}

class ZigZagTraversal {
    void printZigZag(Tree root) {
        if (root == null) return;
        Stack<Tree> currentLevel = new Stack<>();
        Stack<Tree> nextLevel = new Stack<>();
        boolean leftToRight = false;
        currentLevel.push(root);
        while(!currentLevel.isEmpty()) {
            Tree temp = currentLevel.pop();
            System.out.println(temp.data + " ");
            if(leftToRight) {
                if(temp.left != null) {
                    nextLevel.push(temp.left);
                }
                if(temp.right != null) {
                    nextLevel.push(temp.right);
                }
            } else {
                if(temp.right != null) {
                    nextLevel.push(temp.right);
                }
                if(temp.left != null) {
                    nextLevel.push(temp.left);
                }
            }
            if(currentLevel.isEmpty()){
                leftToRight = !leftToRight;
                Stack<Tree> tempStack = currentLevel;
                currentLevel = nextLevel;
                nextLevel = tempStack;
            }
        }
    }
    

    public static void main(String[] args) {
        Tree root = new Tree(1);
        root.left = new Tree(2);
        root.right = new Tree(3);
        root.left.left = new Tree(4);
        root.left.right = new Tree(5);
        root.right.left = new Tree(6);
        root.right.right = new Tree(7);

        ZigZagTraversal zzt = new ZigZagTraversal();
        System.out.println("Zig-Zag Traversal of binary tree is:");
        zzt.printZigZag(root);
    }
}
