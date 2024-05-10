package I_多态.demo1;

public class Test {
    public static void main(String[] args) {
        Animal ani = new Cat();
        ani.eat();
        ani = new Dog();
        ani.eat();
    }
}
