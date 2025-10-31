package J_抽象类;

public abstract class Animal {
    private int age = 20;
    private final String name = "Animal";

    public Animal() {
        System.out.println("父类构造");
    }

    public Animal(int age) {
        this.age = age;
        System.out.println("父类带参数构造");
    }

    public abstract void eat();

    public void sleep() {
        System.out.println("sleep");
    }

    public void show(){
        age = 40;
//        name = "Dog";
        System.out.printf("%d --- %s",age,name);
    }
}
