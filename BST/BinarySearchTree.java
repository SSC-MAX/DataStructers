package BST;

public class BinarySearchTree {
    Node root;

    //插入元素
    private void add(int value){
        //因为此时二叉排序树是空的，所以将其根节点传入，从根节点开始插入
        root = addRecursive(root, value);
    }
    private Node addRecursive(Node current,int value){
        if (current == null){
            return new Node(value);
        }
        if (current.value > value){
            current.left = addRecursive(current.left,value);
        }else if (current.value < value){
            current.right = addRecursive(current.right,value);
        }
        return current;
    }
    //    public void add(Node node){
//        if (root == null){
//            root = node;  //若root为空则将插入的node设为根节点
//        }else {
//            root.addNode(node);
//        }
//    }

    //查找元素
    /*
    * @value:查找的值
    * */
    private boolean containsNodeRecursive(Node current, int value){
        if (current == null){
            return false;
        }
        if (current.value == value){
            return true;
        }
        return value < current.value ? containsNodeRecursive(current.left,value) : containsNodeRecursive(current.right, value);
    }
    //同插入，此方法仅对以上方法进行一层封装，自动将root作为current传入，其实没有此方法直接在调用containsNodeRecursive()的时候将root传入也是可以的
    public boolean containsNode(int value){
        return containsNodeRecursive(root,value);
    }

    //删除元素
    private Node deleteRecursive(Node current, int value){
        //找不到要删除的元素，无法删除
        if (current == null){
            return null;
        }
        //找到了元素，准备删除
        if (current.value == value){
            //若删除的是叶子结点
            if (current.left == null && current.right == null){
                return null;
            }
            //若删除的结点只有左子树或右子树
            if (current.right == null){
                return current.left;
            }
            if (current.left == null){
                return current.right;
            }
            //若删除的结点既有左子树也有右子树(此处使用的是右子树的最小值)
            int smallestValue = getSmallestValue(current.right);
            current.value = smallestValue;
            current.right = deleteRecursive(current.right,smallestValue);
            return current;
        }
        //继续查找要删除的元素
        if (value < current.value){
            current.left = deleteRecursive(current.left,value);
            return current;
        }
        current.right = deleteRecursive(current.right,value);
        //能运行到以下说明成功查找到了要删除的元素并且完成了删除操作，以下的return与删除操作的if中最后的return同效
        return current;
    }
    //寻找最小值，不断取左子树直到没有左子树，即找到最左下的结点
    private int getSmallestValue(Node root){
        if (root.left != null){
            return getSmallestValue(root.left);
        }else {
            return root.value;
        }
    }
    private void delete(int value){
        root = deleteRecursive(root,value);
    }

    //前序遍历
    public void preOrder(Node node){
        if (node == null){
            return;
        }
        System.out.println(node.value);
        if (node.left != null){
            preOrder(node.left);
        }
        if (node.right != null){
            preOrder(node.left);
        }
    }
    //中序遍历
    public void inOrder(Node node){
        if (node == null){
            return;
        }
        if (node.left != null){
            inOrder(node.left);
        }
        System.out.println(node.value);
        if (node.right != null){
            inOrder(node.right);
        }
    }
    //后序遍历
    public void postOrder(Node node){
        if (node == null){
            return;
        }
        if (node.left != null){
            postOrder(node.left);
        }
        if (node.right != null){
            postOrder(node.right);
        }
        System.out.println(node.value);
    }



//    //中序遍历
//    public void infixOrder() {
//        if (this.root != null) {
//            this.root.infixOrder();
//        } else {
//            System.out.println("二叉树为空，无法遍历");
//        }
//    }

    public static void main(String[] args) {
        int[] arr = {7,3,10,12,5,1,9};
        //创建二叉排序树
        BinarySearchTree binarySearchTree = new BinarySearchTree();
        for (int i=0;i<arr.length;i++){
            binarySearchTree.add(arr[i]);
        }
        //中序遍历二叉排序树
//        binarySearchTree.infixOrder();
        binarySearchTree.inOrder(binarySearchTree.root);
        //删除
        binarySearchTree.delete(12);
        System.out.println("-----------删除后的结果是-----------");
        binarySearchTree.inOrder(binarySearchTree.root);
    }
}

//节点
class Node{
    int value;
    Node left;
    Node right;

    public Node(int value){
        this.value = value;
        right = null;
        left = null;
    }

//    public void addNode(Node node){
//        if (node == null){
//            return;
//        }
//        if (node.value < this.value){
//            if (this.left == null){
//                this.left = node;
//            }else {
//                this.left.addNode(node);
//            }
//        } else { //添加的值大于当前节点的值
//            if (this.right == null){
//                this.right = node;
//            }else {
//                this.right.addNode(node);
//            }
//        }
//    }

//    public Node deleteNode(int searchKey){
//        if (this.value == searchKey){
//            //被删除的是叶子节点
//            if (this.left == null && this.right == null){
//                return null;
//            }
//            //被删除的既有左子树也有右子树
//            if (this.left != null && this.right != null){
//
//            }
//            //被删除的只有左子树或右子树
//            if (this.left != null){
//                return this.left;
//            }else {
//                return this.right;
//            }
//
//        }
//        if (this.value > searchKey){
//            this.left.deleteNode(searchKey);
//        }
//        if (this.value < searchKey){
//            this.right.deleteNode(searchKey);
//        }
//    }

//    //前序遍历——中左右
//    public void preOrder(){
//        System.out.println(this.value);
//        if (this.left != null){
//            this.left.preOrder();
//        }
//        if (this.right != null){
//            this.right.preOrder();
//        }
//    }
//    //中序遍历——左中右
//    public void infixOrder() {
//        //递归向左子树
//        if (this.left != null) {
//            this.left.infixOrder();
//        }
//        //输出父节点
//        System.out.println(this.value);
//        //递归向右子树
//        if (this.right != null) {
//            this.right.infixOrder();
//        }
//    }
}
