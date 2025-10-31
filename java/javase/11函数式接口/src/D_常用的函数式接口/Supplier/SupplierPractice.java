package D_常用的函数式接口.Supplier;

import java.util.Arrays;
import java.util.function.Supplier;

public class SupplierPractice {
    public static void main(String[] args) {
        int[] arr = {19, 50, 28, 37, 46};
        int maxValue = getMax(() -> {
            int max = arr[0];
            for (int i = 0; i < arr.length; i++) {
                if (max < arr[i])
                    max = arr[i];
            }
            return max;
        });
        System.out.println(maxValue);
    }

    private static int getMax(Supplier<Integer> sup) {
        return sup.get();
    }
}
