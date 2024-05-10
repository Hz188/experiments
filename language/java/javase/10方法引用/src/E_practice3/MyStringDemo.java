package E_practice3;

public class MyStringDemo {
    public static void main(String[] args) {
        //1.
        useMyString((s, x, y) -> s.substring(x, y));

        //2.
        useMyString(String::substring);
        //Lambda表达式被类的实例方法替代时候
        //第一个参数作为调用者
        //后面的参数全部传递给该方法作为参数
    }

    private static void useMyString(MyString my) {
        String s = my.mySubString("helloworld", 0, 5);
        System.out.println(s);
    }
}
