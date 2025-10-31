package C_this;
/**
 * this
 *      修饰的变量用来指代成员变量
 *      方法形参如果和成员变量同名，不带this修饰的变量是形参，而不是成员变量
 *      方法形参如果和成员变量不同名，则无影响
 *
 * 什么时候使用this？
 *      局部变量 隐藏 | hide 成员变量时
 *
 * this 代表所在类的对象的引用，方法被哪个对象调用，this就指向谁
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
