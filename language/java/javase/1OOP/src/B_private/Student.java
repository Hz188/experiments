package B_private;
/**
 * 封装的目的
 * 不让外界直接访问成员
 * 通过访问器方法，可以自己添加一些判断条件
 * 防止出现无意义的数据值
 * 比如 年龄值不可能为负数
 * private
 *      是一个权限修饰符
 *      可以修饰成员
 *      保护成员不被别的类使用，只有在本类内部可以使用
 */
public class Student {
    private String name;
    private int age;

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
