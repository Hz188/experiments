package C_字符流;

import java.io.UnsupportedEncodingException;
import java.nio.charset.StandardCharsets;
import java.util.Arrays;

//encoding & decoding
public class Demo1 {
    public static void main(String[] args) throws UnsupportedEncodingException {
        //encoding
        String s = "中国";
        byte[] bytes = s.getBytes(); //default UTF-8
        System.out.println(Arrays.toString(bytes)); //[-28, -72, -83, -27, -101, -67]

        byte[] bytes1 = s.getBytes(StandardCharsets.UTF_8);
        System.out.println(Arrays.toString(bytes1)); //[-28, -72, -83, -27, -101, -67]

        byte[] bytes2 = s.getBytes("GBK");
        System.out.println(Arrays.toString(bytes2)); //[-42, -48, -71, -6]

        //decoding
        String s1 = new String(bytes);
        System.out.println("s1 = " + s1);

        String s2 =new String(bytes1,StandardCharsets.UTF_8);
        System.out.println("s2 = " + s2);

        String s3 = new String(bytes2, "GBK");
        System.out.println("s3 = " + s3);

    }
}
