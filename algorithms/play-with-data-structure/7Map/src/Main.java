import java.util.ArrayList;

public class Main {
    public static double testMap(Map<String, Integer> map, String fileName) {
        long startTime = System.nanoTime();

        System.out.println(fileName);
        ArrayList<String> words = new ArrayList<>();
        if (FileOperation.readFile(fileName, words)) {
            System.out.println("Total words: " + words.size());
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
        long endTime = System.nanoTime();

        return (endTime - startTime) / 1.0e9;
    }

    public static void main(String[] args) {
        String fileName = "7Map/pride-and-prejudice.txt";

        BSTMap<String, Integer> bstMap = new BSTMap<>();
        double time1 = testMap(bstMap, fileName);
        System.out.println("BST Map: " + time1 + "s");
        System.out.println("--------------------------");

        LinkedListMap<String, Integer> linkedListMap = new LinkedListMap<>();
        double time2 = testMap(linkedListMap, fileName);
        System.out.println("Linked List Map: " + time2 + "s");

        AVLMap<String, Integer> avlMap = new AVLMap<>();
        double time3 = testMap(avlMap, fileName);
        System.out.println("AVL Map: " + time3 + "s");


    }
}
