import java.util.ArrayList;

public class Demo7 {
    public static void main(String[] args) {
        ArrayList<String> list = new ArrayList<>();
        list.add("10");
        list.add("20");
        list.add("30");
        list.add("40");
        list.add("50");

        //string -> int  output
//        list.stream().map(Integer::parseInt).forEach(System.out::println);

        //同样功能 但是返回的是要给 IntStream  有一个 sum()方法
        list.stream().mapToInt(Integer::parseInt).forEach(System.out::println);
        int sum = list.stream().mapToInt(Integer::parseInt).sum();
        System.out.println(sum);


    }
}
