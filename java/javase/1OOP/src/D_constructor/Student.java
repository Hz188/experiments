package D_constructor;

/**
 * 构造方法功能
 *      创建对象
 *      完成对象的初始化
 *
 * 格式
 *      修饰符 | 一般 public 类名(参数) {
 *      }
 *
 *      没给任何构造的时候，系统默认给出无参构造
 *      若给出有参，也不会再给无参构造了，所以要自己给出无参构造
 *
 *      建议 都手工书写构造方法
 */
public class Student {
    private String name;
    private int age;

    public Student() {
        System.out.println("无参构造方法");
    }

    public Student(String name, int age) {
        System.out.println("有参构造方法");
        this.name = name;
        this.age = age;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        if(age < 0 || age > 120){
            System.out.println("Illegal age value.");
        } else{
            this.age = age;
        }
    }

    @Override
    public String toString() {
        return "Student{" +
                "name='" + name + '\'' +
                ", age=" + age +
                '}';
    }

    public void study(){
        System.out.println("learn method");
    }
    public void doHomework(){
        System.out.println("Do homework");
    }
}
