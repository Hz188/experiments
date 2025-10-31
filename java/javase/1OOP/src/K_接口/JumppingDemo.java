package K_接口;

public class JumppingDemo {
    public static void main(String[] args) {
        Jumpping j = new Cat();
        j.jump();
        System.out.println(j.num);
        System.out.println(j.num2);
        System.out.println(Jumpping.num2);
        System.out.println(Jumpping.num);
        //说明接口中的成员变量是静态的
    }
}
