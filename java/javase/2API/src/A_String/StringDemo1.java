package A_String;

/**
 * 构造方法
 * <blockquote><pre>
 *       public String();
 *       public String(char[] chs);
 *       public String(byte[] bys);
 *       String s = "abc";
 * </pre></blockquote><p>
 *
 */
public class StringDemo1 {
    public static void main(String[] args) {
        String s  = new String();
        String s1 = new String(new char[]{'c','b','a'});
        String s2 = new String(new byte[]{97,98,99});
        String s3 = "987";
        System.out.println(s);
        System.out.println(s1);
        System.out.println(s2);
        System.out.println(s3);

    }
}
