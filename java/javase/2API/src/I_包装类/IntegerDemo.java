package I_包装类;

public class IntegerDemo {
    public static void main(String[] args) {
        //构造方法过时了 不推荐使用 建议使用valueOf
        Integer i1 = Integer.valueOf(100);
        Integer i2 = Integer.valueOf("1");


        System.out.println(i1.byteValue());
        System.out.println(Integer.bitCount(0b1100));

        /* int -> String */
        String s = String.valueOf(1);

        /* int -> Integer -> String */
        Integer i = Integer.valueOf(1);
        String s1 = i.toString();

        /* String -> Integer -> int */
        Integer integer = Integer.valueOf("100");
        int i4 = integer.intValue();

        /* String -> int */
        int x = Integer.parseInt("100");

        //自动装箱与拆箱
        Integer ii = 100;
        int xx = ii;
    }
}
