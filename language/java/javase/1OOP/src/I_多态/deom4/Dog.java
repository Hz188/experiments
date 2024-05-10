package I_多态.deom4;

public class Dog extends Animal {
    @Override
    public void eat() {
        System.out.println("Dogs eats meat.");
    }

    public void lookDoor(){
        System.out.println("狗看门");
    }
}
