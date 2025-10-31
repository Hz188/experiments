package I_包装类;

import java.util.Arrays;

public class Demo2 {
    public static void main(String[] args) {
        String str = "91 27 46 38 50";
        String[] s = str.split(" ");
        int[] x = new int[s.length];
        int i = 0;
        for (String s2 : s) {
            x[i] = Integer.parseInt(s2);
            i++;
        }
        Arrays.sort(x);
        System.out.println(Arrays.toString(x));
    }
}
