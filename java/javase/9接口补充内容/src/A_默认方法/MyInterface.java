package A_默认方法;

public interface MyInterface {
    void show1();
    void show2();

    //如果我们想要扩充接口功能，就要添加方法，所有实现类都要重写，如果有的实现类不需要这个新功能呢？所以这不利于程序的维护
//    void show3();

    //After Java8 提供了默认方法
    default void show3(){
        System.out.println("show3");
    }

}
