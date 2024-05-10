package E_Lambda与匿名内部类的区别;

public class LambdaDemo {
    public static void main(String[] args) {
        test1();
        test2();
    }

    private static void useStudent(Student s) {
        s.study();
    }

    private static void useInter(Inter i) {
        i.show();
    }

    private static void useAnimal(Animal a) {
        a.method();
    }

    //匿名内部类
    private static void test1() {
        useInter(new Inter() {
            @Override
            public void show() {
                System.out.println("Interface");
            }
        });

        useAnimal(new Animal() {
            @Override
            public void method() {
                System.out.println("Abstract class");
            }
        });

        useStudent(new Student() {
            @Override
            public void study() {
                System.out.println("Specific class");
            }
        });
    }

    //Lambda
    private static void test2() {
        useInter(() -> System.out.println("Interface"));
        //error : Target type of a lambda conversion must be an interface
//        useAnimal(() -> System.out.println("Abstract class"));

        //error : Target type of a lambda conversion must be an interface
//        useStudent(() -> System.out.println("Specific class"));

    }

}
