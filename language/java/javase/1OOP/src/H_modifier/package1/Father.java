package H_modifier.package1;

/**
 * 同一个类 1 2 3 4 四个都可
 * 同一个包子类 无关类 2 3 4
 * 不同包 子类 3 4
 * 不同包 无关类 4
 */
public class Father {

    private void show1(){
        System.out.println("private method.");
    }

    void show2(){
        System.out.println("default method.");
    }

    protected void show3(){
        System.out.println("protected method.");
    }

    public void show4(){
        System.out.println("public method.");
    }

    public static void main(String[] args) {
        //四个都可以用
        Father f = new Father();
        f.show1();
        f.show2();
        f.show3();
        f.show4();
    }
}
