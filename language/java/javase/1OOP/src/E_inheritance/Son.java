package E_inheritance;

/**
 * 使用变量时候
 *      先在子类方法局部找
 *      再去子类成员里面找
 *      再去父类里面找
 *
 * 使用方法
 *      子类成员范围找
 *      父类成员范围找
 *      无，报错（考虑一层继承）
 *
 * 方法重写
 *      出现和父类一样的方法声明
 *      为了扩充功能
 *
 * Java支持单继承和多层继承
 *      不支持多继承
 */
public class Son extends Father {
    public int height = 180;
    public int age = 20;
    public void method(){
        System.out.println("Son method()");
    }

    @Override
    public void show() {
        super.show();
        System.out.println("Son show()");
    }
}
