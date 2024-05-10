import java.util.ArrayList;

public class BSTMap<K extends Comparable<K>, V> implements Map<K, V> {


    private class Node {
        public K key;
        public V value;
        public Node left;
        public Node right;

        public Node(K key, V value) {
            this.key = key;
            this.value = value;
            left = null;
            right = null;
        }
    }

    private Node root;
    private int size;

    public BSTMap() {
        root = null;
        size = 0;
    }


    @Override
    public int getSize() {
        return size;
    }

    @Override
    public boolean isEmpty() {
        return size == 0;
    }


    // 向二分搜索树中添加新的元素(key,value)
    @Override
    public void add(K key, V value) {
        root = add(root, key, value);
    }

    // 向以node为根的二分搜索树中插入元素(key,value)，递归算法
    // 返回插入新节点后的二分搜索树的根
    private Node add(Node node, K key, V value) {
        if (node == null) { //null 本来就也是一种二叉树节点，所以对 null一视同仁看作一个 node
            size++;
            return new Node(key, value);
        }

        if (key.compareTo(node.key) < 0) {
            node.left = add(node.left, key, value);
        } else if (key.compareTo(node.key) > 0) {
            node.right = add(node.right, key, value);
        } else {  //key.compareTo(node.key) == 0
            node.value = value;
        }
        return node;
    }

    //返回node为根节点，key 所在的节点
    private Node getNode(Node node, K key) {
        if (node == null) {
            return null;
        }
        if (key.compareTo(node.key) == 0)
            return node;
        else if (key.compareTo(node.key) < 0) {
            return getNode(node.left, key);
        } else {
            return getNode(node.right, key);
        }
    }

    @Override
    public boolean contains(K key) {
        return getNode(root, key) != null;
    }

    @Override
    public V get(K key) {
        Node node = getNode(root, key);
        return node == null ? null : node.value;
    }

    @Override
    public void set(K key, V newValue) {
        Node node = getNode(root, key);
        if (node == null) {
            throw new IllegalArgumentException(key + " doesn't exists.");
        }

        node.value = newValue;
    }

    //删除键为key的节点，递归算法
    @Override
    public V remove(K key) {
        Node node = getNode(root, key);
        if (node != null) {
            root = remove(root, key);
            return node.value;
        }
        return null;
    }

    // 删除掉以node为根，键为key的节点，递归算法
    // 返回新根
    private Node remove(Node node, K key) {
        if (node == null) {
            return null;
        }
        if (key.compareTo(node.key) < 0) {
            node.left = remove(node.left, key);
            return node;
        } else if (key.compareTo(node.key) > 0) {
            node.right = remove(node.right, key);
            return node;
        } else {  //key == node.key

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

    //找当前节点为根节点的 BST的最小值
    private Node minimum(Node node) {
        if (node.left == null) {
            return node;
        }
        return minimum(node.left);
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


    public static void main(String[] args) {
        System.out.println("Pride and Prejudice");

        ArrayList<String> words = new ArrayList<>();
        if (FileOperation.readFile("7Map/pride-and-prejudice.txt", words)) {
            System.out.println("Total words: " + words.size());
            BSTMap<String, Integer> map = new BSTMap<>();
            for (String word : words) {
                if (map.contains(word)) {
                    map.set(word, map.get(word) + 1);
                } else {
                    map.add(word, 1);
                }
            }
            System.out.println("Total different words:" + map.getSize());
            System.out.println("Frequency of PRIDE: " + map.get("pride"));
            System.out.println("Frequency of PREJUDICE: " + map.get("prejudice"));
        }
    }
}
