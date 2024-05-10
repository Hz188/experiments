import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

//TODO 重复元素的BST 利用count or 规定左子树小于等于 or 右子树大于等于
public class BST<E extends Comparable<E>> {

    private class Node {
        public E e;
        public Node right, left;

        //TODO 添加一个size变量:记录每个节点子节点的个数，利用这个去实现rank select
        //TODO 添加一个depth变量，记录深度
        public Node(E e) {
            this.e = e;
            right = null;
            left = null;
        }
    }

    private Node root;
    private int size;


    public BST() {
        root = null;
        size = 0;
    }

    public int size() {
        return size;
    }

    public boolean isEmpty() {
        return size == 0;
    }

    // 向二分搜索树中添加新的元素e
    public void add(E e) {
        root = add(root, e);
    }

    // 向以node为根的二分搜索树中插入元素e，递归算法
    // 返回插入新节点后的二分搜索树的根
    private Node add(Node node, E e) {
        if (node == null) { //null 本来就也是一种二叉树节点，所以对 null一视同仁看作一个 node
            size++;
            return new Node(e);
        }

        if (e.compareTo(node.e) < 0) {
            node.left = add(node.left, e);
        } else if (e.compareTo(node.e) > 0) {
            node.right = add(node.right, e);
        }

        return node;
    }

    // 返回插入新节点后的二分搜索树的根  有问题
    public void addNotRecursion(E e) {
        if (root == null){
            root = new Node(e);
            size++;
            return;
        }
        Node node = root;
        while (true) {
            if (e.compareTo(node.e) < 0) {
                if(node.left == null){
                    node.left = new Node(e);
                    size++;
                    return;
                } else {
                    node = node.left;
                }

            } else if (e.compareTo(node.e) > 0) {
                if (node.right == null) {
                    node.right = new Node(e);
                    size++;
                    return;
                } else {
                    node = node.right;
                }
            }
        }
    }

    //是否包含 e
    public boolean contains(E e) {
        return contains(root, e);
    }

    //看以 node 为根的BST中是否包含元素e
    private boolean contains(Node node, E e) {
        // 递归
//        if (node == null){
//            return false;
//        }
//
//        boolean flag = false;
//        if (e.compareTo(node.e) == 0)
//            return true;
//        else if (e.compareTo(node.e) > 0)
//            flag = contains(node.right, e);
//        else  //e.compareTo(node.e) < 0
//            flag = contains(node.left, e);
//
//        return flag;

        // 非递归
        Stack<Node> stack = new Stack<>();
        stack.push(node);
        while (!stack.isEmpty()) {
            Node pop = stack.pop();
            if (pop.e == e)
                return true;
            if (pop.left != null)
                stack.push(pop.left);
            if (pop.right != null)
                stack.push(pop.right);
        }
        return false;
    }

    // 二分搜索树的前序遍历
    public void preOrder() {
        preOrder(root);
        System.out.println();
    }

    // 前序遍历以node为根的二分搜索树, 递归算法
    private void preOrder(Node node) {
        if (node == null) {
            return;
        }

        System.out.print(node.e + " ");
        preOrder(node.left);
        preOrder(node.right);

    }

    // 非递归前序遍历
    public void preOderNR() {

        Stack<Node> stack = new Stack<>();
        stack.push(root);
        while (!stack.isEmpty()) {
            Node cur = stack.pop();
            System.out.print(cur.e + " ");
            if (cur.right != null) {
                stack.push(cur.right);
            }
            if (cur.left != null) {
                stack.push(cur.left);
            }
        }
        System.out.println();
    }


    //中序遍历
    public void inOrder() {
        inOrder(root);
        System.out.println();
    }

    public void inOrderNR() {
        // 非递归
        Stack<Node> stack = new Stack<>();
        Node cur = root;
        while (!stack.isEmpty() || cur != null) {
            while (cur != null) {
                stack.push(cur);
                cur = cur.left;
            }
            cur = stack.pop();
            System.out.print(cur.e + " ");
            cur = cur.right;
        }
        System.out.println();
    }

    //中序遍历以node为根的二分搜索树
    private void inOrder(Node node) {

        if (node == null) {
            return;
        }
        inOrder(node.left);
        System.out.print(node.e + " ");
        inOrder(node.right);
    }

    //后序遍历
    public void postOrder() {
        postOrder(root);
        System.out.println();
    }

    public void postOrderNR() {

        //非递归
        Node cur = root;
        Stack<Node> stack = new Stack<>();
        if (cur == null) {
            System.out.println("空树");
            return;
        }
        Node prev = null;
        while (!stack.isEmpty() || cur != null) {
            while (cur != null) {
                stack.push(cur);
                cur = cur.left;
            }
            cur = stack.peek();
            if (cur.right == null || cur.right == prev) {
                cur = stack.pop();
                System.out.print(cur.e + " ");
                prev = cur;
                cur = null;
            } else {
                cur = cur.right;
            }
        }
        System.out.println();

        //双栈法，非递归
//        if(node != null){
//            Stack<Node> s1 = new Stack<Node>();
//            Stack<Node> s2 = new Stack<Node>();
//            s1.push(node);
//            while(!s1.isEmpty()){
//                node = s1.pop();
//                s2.push(node);
//                if(node.left != null){
//                    s1.push(node.left);
//                }
//                if(node.right != null){
//                    s1.push(node.right);
//                }
//            }
//            while(!s2.isEmpty()){
//                System.out.print(s2.pop().e + " ");
//            }
//        }
//        System.out.println();

    }

    private void postOrder(Node node) {
        if (node == null)
            return;

        postOrder(node.left);
        postOrder(node.right);
        System.out.print(node.e + " ");

    }

    public void levelOrder() {
        Queue<Node> q = new LinkedList<>();
        q.add(root);
        while (!q.isEmpty()) {
            Node cur = q.remove();
            System.out.print(cur.e + " ");
            if (cur.left != null) {
                q.add(cur.left);
            }
            if (cur.right != null) {
                q.add(cur.right);
            }
        }
        System.out.println();
    }

    public E minimum() {
        if (size == 0) {
            throw new IllegalArgumentException("BST is empty.");
        }
//        System.out.println("NR ---> " + minimumNR(root).e);
//        System.out.println("R  ---> " + minimum(root).e);
        return minimum(root).e;
    }

    //找当前节点为根节点的 BST的最小值
    private Node minimum(Node node) {
        if (node.left == null) {
            return node;
        }
        return minimum(node.left);
    }

    //找当前节点为根节点的 BST的最小值、
    private Node minimumNR(Node node) {
        while (node.left != null) {
            node = node.left;
        }
        return node;
    }

    public E maximum() {
        if (size == 0) {
            throw new IllegalArgumentException("BST is empty.");
        }
//        System.out.println("NR ---> " + maximumNR(root).e);
//        System.out.println("R  ---> " + maximum(root).e);
        return maximum(root).e;
    }

    //找当前节点为根节点的 BST的最大值
    private Node maximum(Node node) {
        if (node.right == null) {
            return node;
        }
        return maximum(node.right);
    }

    //找当前节点为根节点的 BST的最大值、
    private Node maximumNR(Node node) {
        while (node.right != null) {
            node = node.right;
        }
        return node;
    }

    //删除最小值节点
    public E removeMin() {
        E ret = minimum();
        root = removeMin(root);

        return ret;
    }

    //删除以root为根的最小值节点
    //返回删除后的BST的根
    private Node removeMin(Node node) {
        if (node.left == null) {
            Node rightNode = node.right;
            node.right = null;
            size--;
            return rightNode;
        }
        node.left = removeMin(node.left);
        return node;
    }

    //删除最大值节点
    public E removeMax() {
        E ret = maximum();
        root = removeMax(root);

        return ret;
    }

    //删除以root为根的最大值节点
    //返回删除后的BST的根
    private Node removeMax(Node node) {
        if (node.right == null) {
            Node leftNode = node.left;
            node.left = null;
            size--;
            return leftNode;
        }
        node.right = removeMax(node.right);
        return node;
    }

    //删除BST中 任意 e 的结点
    public void remove(E e) {
        remove(root, e);
    }

    // 删除掉以node为根，值为e的节点，递归算法
    // 返回新根
    private Node remove(Node node, E e) {
        if (node == null) {
            return null;
        }
        if (e.compareTo(node.e) < 0) {
            node.left = remove(node.left, e);
            return node;
        } else if (e.compareTo(node.e) > 0) {
            node.right = remove(node.right, e);
            return node;
        } else {//e == node.e

            //左子树 为空
            if (node.left == null) {
                Node rightNode = node.right;
                node.right = null;
                size--;
                return rightNode;
            }
            //右子树为空
            if (node.right == null) {
                Node leftNode = node.left;
                node.left = null;
                size--;
                return leftNode;
            }
            //左右都不为空
            //找到比待删除节点大的最小节点，即右子树的最小值  --- 后继
            //或者找 左子树得最大值  --- 前驱
            //将此节点删除，取出
            //代替待删除节点，成为新根
            Node successor = minimum(node.right);  //这里是找后继，还可以找前驱
            successor.right = removeMin(node.right);
            //removeMin删除的节点，被successor指向
            //所以removeMin里的size--多余了
            size++;

            successor.left = node.left;

            //当前节点脱离，此时才真正删除，size--，更符合逻辑
            node.left = node.right = null;
            size--;
            return successor;
        }
    }

    public void floor(E e) {
        //TODO 找大于e的最小值，e可以不是BST中的元素
    }

    public void ceil(E e) {
        //TODO 找小于e的最大值，e可以不是BST中的元素
    }

    public void rank(E e) {
        //TODO 返回element的排名rank
    }

    public void select(int rank) {
        //TODO 返回排名rank的element
    }

    @Override
    public String toString() {
        StringBuilder res = new StringBuilder();
        generateBSTString(root, 0, res);
        return res.toString();
    }

    //生成以node为节点，深度为depth的描述二叉树的字符串
    private void generateBSTString(Node node, int depth, StringBuilder res) {
        if (node == null) {
            res.append(generateDepthString(depth)).append("null\n");
            return;
        }
        res.append(generateDepthString(depth)).append(node.e).append("\n");
        generateBSTString(node.left, depth + 1, res);
        generateBSTString(node.right, depth + 1, res);
    }

    private String generateDepthString(int depth) {
        StringBuilder res = new StringBuilder();
        for (int i = 0; i < depth; i++) {
            res.append("--");
        }
        return res.toString();
    }


}
