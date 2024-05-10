package I_多态.demo2;

public class Cat extends Animal {
    public int age = 20;
    public int weight = 10;

    @Override
    public void eat() {
        System.out.println("Cats eats fish.");
    }

    public void play(){
        System.out.println("Cats like playing.");
    }
}
