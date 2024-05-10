import java.io.File;
import java.util.ArrayList;

public class Main {

    private static double testSet(Set<String> set, String fileName) {
        long startTime = System.nanoTime();

        System.out.println(fileName);
        ArrayList<String> words = new ArrayList<>();

        if (FileOperation.readFile(fileName, words)) {
            System.out.println("Total words: " + words.size());

            for (String word : words) {
                set.add(word);
            }
            System.out.println("Total different words: " + set.getSize());
        }

        long endTime = System.nanoTime();

        return (endTime - startTime) / 1.0e9;
    }

    public static void main(String[] args) {
        String fileName = "6Set/pride-and-prejudice.txt";

        BSTSet<String> bstSet = new BSTSet<>();
        double time1 = testSet(bstSet, fileName);
        System.out.println("BST Set:" + time1 + " s");
        System.out.println();

        LinkedListSet<String> linkedListSet = new LinkedListSet<>();
        double time2 = testSet(linkedListSet, fileName);
        System.out.println("LinkedList Set:" + time2 + " s");
        System.out.println();

        AVLSet<String> avlSet = new AVLSet<>();
        double time3 = testSet(avlSet, fileName);
        System.out.println("AVL Set:" + time3 + " s");
        System.out.println();
    }
}
