public class  Main {

    public static void main(String[] args) {

        BST<Integer> bst = new BST<>();

        int[] nums = {5, 3, 6, 8, 4, 2};
        for(int num: nums) {
//            bst.add(num);
            bst.addNotRecursion(num);
        }
        System.out.println(bst);


        /////////////////
        //      5      //
        //    /   \    //
        //   3    6    //
        //  / \    \   //
        // 2  4     8  //
        /////////////////

//        System.out.println(bst.contains(1));
//        System.out.println(bst.contains(8));


        bst.remove(3);


//        System.out.println("----pre递归----");
//        bst.preOrder();
//        System.out.println("----pre非递归----");
//        bst.preOderNR();
//        System.out.println("");
//
//        System.out.println("----in递归----");
//        bst.inOrder();
//        System.out.println("----in非递归----");
//        bst.inOrderNR();
//        System.out.println("");
//
//        System.out.println("----post递归----");
//        bst.postOrder();
//        System.out.println("----post非递归----");
//        bst.postOrderNR();
//        System.out.println("");
//
//        System.out.println("----层序遍历----");
//        bst.levelOrder();
//        System.out.println("");
//
//        System.out.println("----最小值----");
//        System.out.println(bst.minimum());
//        System.out.println("");
//
//        System.out.println("----最大值----");
//        System.out.println(bst.maximum());
//        System.out.println("");
//
//        System.out.println("-----删除最小值节点---");
//        System.out.println(bst.removeMin());
//        System.out.println("");
//
//        System.out.println("-----删除最大值节点---");
//        System.out.println(bst.removeMax());
//        System.out.println("");


        System.out.println(bst);




    }
}
