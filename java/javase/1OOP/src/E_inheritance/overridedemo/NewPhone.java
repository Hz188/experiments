package E_inheritance.overridedemo;

/**
 * 私有方法不能被重写 | 父类成员没被继承
 *  * 重写方法 修饰符权限要大于等于父类
 */
public class NewPhone extends Phone {
    @Override
    public void call(String name) {
        System.out.println("NewPhone:call()");
        super.call(name);

    }
}
