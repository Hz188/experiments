package B_StringBuilder;

/**
 * 构造方法
 *      public StringBuilder()
 *      public StringBuilder(String str)
 *
 * 常用方法
 *      public StringBuilder append(anytype x)
 *      public StringBuilder reverse()
 */
public class SBDemo1 {
    public static void main(String[] args) {
        StringBuilder sb = new StringBuilder();
        System.out.println(sb.append(1).append(2).append("hello"));

        System.out.println(sb.reverse());
        System.out.println(sb.toString());
    }
}
