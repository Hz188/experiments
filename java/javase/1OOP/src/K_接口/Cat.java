package K_接口;

public class Cat implements Jumpping {
    public Cat() {
        super(); // -> 访问的是Object的无参构造了 接口无构造
    }

    @Override
    public void jump() {
        System.out.println("有的猫会跳高");
    }
}
