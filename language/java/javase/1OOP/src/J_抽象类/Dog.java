package J_抽象类;

public class Dog extends Animal {
    public Dog() {
        System.out.println("子类构造");
    }

    @Override
    public void eat() {
        System.out.println("狗吃骨头");
    }
}
