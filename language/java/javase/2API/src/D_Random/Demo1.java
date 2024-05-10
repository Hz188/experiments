package D_Random;

import java.util.Random;

public class Demo1 {
    public static void main(String[] args) {
        Random r = new Random();
        int i;
        for (int j = 0; j < 5; j++) {
            i = r.nextInt(10);
            System.out.println(i);
        }
    }
}
