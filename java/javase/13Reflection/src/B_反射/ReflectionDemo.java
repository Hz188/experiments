package B_反射;

/**
 * 反射：就是通过class文件对象去操作该文件中的成员变量 方法 构造方法
 * 1、先得到class文件，也就是Class类的对象
 * Class类 ：
 * 成员变量    Field
 * 构造方法    Constructor
 * 成员方法    Method
 * <p>
 * 获取class文件对象的方法
 * A、Object getClass() 方法
 * B、数据类型的静态属性class
 * C、Class类中的静态方法 public static Class forName(String className)
 * <p>
 * 注意：
 * 1、自己玩
 * 第一种、第二种
 * 2、开发 用第三种
 * 因为第三种传递的是字符串，我们可以把这样的字符串配置到配置文件中
 */
public class ReflectionDemo {


    public static void main(String[] args) throws ClassNotFoundException {

        Class<Student> c1 = Student.class;
        System.out.println(c1);
        Class<Student> c2 = Student.class;
        System.out.println(c1 == c2);
        System.out.println("--------");

        Student s = new Student();
        Class<? extends Student> c3 = s.getClass();
        System.out.println(c3 == c1);
        System.out.println("--------");

        Class<?> c4 = Class.forName("B_反射.Student");
        System.out.println(c4 == c1);
    }
}
