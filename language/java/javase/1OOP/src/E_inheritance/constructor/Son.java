package E_inheritance.constructor;

/**
 * 子类构造方法第一句默认是 super()
 */
public class Son extends Father {
    public Son(){
        System.out.println("Son()");
    }
    public Son(int age){
        super(age);
        System.out.println("Son(int age)");
    }
}
