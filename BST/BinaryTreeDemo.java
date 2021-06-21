package BST;

public class BinaryTreeDemo {
    public static void main(String[] args) {
        //先创建一棵二叉树
        BinaryTree binaryTree = new BinaryTree();
        //创建需要的节点
        HeroNode root = new HeroNode(1, "a");
        HeroNode node2 = new HeroNode(2, "b");
        HeroNode node3 = new HeroNode(3, "c");
        HeroNode node4 = new HeroNode(4, "d");
        HeroNode node5 = new HeroNode(5, "e");

        root.setLeft(node2);
        root.setRight(node3);
        node3.setLeft(node5);
        node3.setRight(node4);

        binaryTree.setRoot(root);

        int searchKey = 6;

        System.out.println("----------------前序遍历----------------");
//        binaryTree.preOrder();
        root.preOrderSearch(searchKey);

        System.out.println("----------------中序遍历----------------");
//        binaryTree.infixOrder();
        root.infixOrderSearch(searchKey);
        System.out.println("----------------后序遍历----------------");
//        binaryTree.postOrder();
        root.postOrderSearch(searchKey);
    }
}

//定义一棵BinaryTree
class BinaryTree {
    private HeroNode root;

    public void setRoot(HeroNode root) {
        this.root = root;
    }

    /*
     * 实际上这里进行了一次封装
     * 遍历的核心算法在HeroNode中，这里仅索取根节点，并调用根节点的遍历方法
     */

    //前序遍历
    public void preOrder() {
        if (this.root != null) {
            this.root.preOrder();
        } else {
            System.out.println("二叉树为空，无法遍历");
        }
    }

    //中序遍历
    public void infixOrder() {
        if (this.root != null) {
            this.root.infixOrder();
        } else {
            System.out.println("二叉树为空，无法遍历");
        }
    }

    //后序遍历
    public void postOrder() {
        if (this.root != null) {
            this.root.postOrder();
        } else {
            System.out.println("二叉树为空，无法遍历");
        }
    }
}


//节点
class HeroNode {
    private int no;
    private String name;
    private HeroNode left;   //默认null
    private HeroNode right;  //默认null

    public HeroNode(int no, String name) {
        super();
        this.no = no;
        this.name = name;
    }

    public int getNo() {
        return no;
    }

    public void setNo(int no) {
        this.no = no;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public HeroNode getLeft() {
        return left;
    }

    public void setLeft(HeroNode left) {
        this.left = left;
    }

    public HeroNode getRight() {
        return right;
    }

    public void setRight(HeroNode right) {
        this.right = right;
    }

    public String toString() {
        return "HeroNode [no=" + no + ", name=" + name + "]";
    }

    //前序遍历——中左右
    public void preOrder() {
        System.out.println(this);  //先输出父节点
        //递归向左子树
        if (this.left != null) {
            this.left.preOrder();
        }
        //递归向右子树
        if (this.right != null) {
            this.right.preOrder();
        }
    }

    //中序遍历——左中右
    public void infixOrder() {
        //递归向左子树
        if (this.left != null) {
            this.left.infixOrder();
        }
        //输出父节点
        System.out.println(this);
        //递归向右子树
        if (this.right != null) {
            this.right.infixOrder();
        }
    }

    //后序遍历——左右中
    public void postOrder() {
        if (this.left != null) {
            this.left.postOrder();
        }
        if (this.right != null) {
            this.right.postOrder();
        }
        System.out.println(this);
    }

    //前序遍历查找

    /**
     * @param searchKey 查找的数
     * @return 找到则返回对应的节点，找不到就返回null
     */
    public HeroNode preOrderSearch(int searchKey) {
        System.out.println("现在在比较的是：" + this.toString());
        //比较当前节点
        if (this.no == searchKey) {
            System.out.println("根部就找到了，node是" + this.toString());
            return this;
        }
        //使用resNode来存储后续递归得到的结果，并根据它的值来决定是否需要继续在左右子树中查找
        //如果不使用resNode，即使后续递归查找到结果并回溯到这里时，仍然会执行在左右子树中的查找
        HeroNode resNode = null;
        if (this.left != null) {
            resNode = this.left.preOrderSearch(searchKey);
        }
        if (resNode == null){
            if (this.right != null) {
                resNode = this.right.preOrderSearch(searchKey);
            }
        }
       return resNode;
//        if (this.left != null){
//            this.left.preOrderSearch(searchKey);
//        }
//        if (this.right != null){
//            this.right.preOrderSearch(searchKey);
//        }
    }

    //中序遍历查找
    public HeroNode infixOrderSearch(int searchKey){
        HeroNode resNode = null;
        if (this.left != null){
            resNode = this.left.infixOrderSearch(searchKey);
        }
        if (resNode == null){
            if (this.no == searchKey){
                System.out.println("找到了,HeroNode是"+this);
                return this;
            }
            if (right != null){
                resNode = this.right.infixOrderSearch(searchKey);
            }
        }
        return resNode;
    }

    //后序遍历查找
    //后序查找中的resNode对比较次数没有影响，因为比较在最后一步
    public HeroNode postOrderSearch(int searchKey){
        HeroNode resNode = null;
        if (this.left != null){
            resNode = this.left.postOrderSearch(searchKey);
        }
        if (resNode == null){
            if (this.right != null){
                resNode = this.right.postOrderSearch(searchKey);
            }
            if (this.no == searchKey){
                System.out.println("找到了，HeroNode是"+this);
                return resNode;
            }
        }
        return resNode;
    }
}
