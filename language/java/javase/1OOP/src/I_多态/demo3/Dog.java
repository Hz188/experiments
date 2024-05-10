package I_多态.demo3;

import I_多态.demo3.Animal;

public class Dog extends Animal {
    @Override
    public void eat() {
        System.out.println("Dogs eats meat.");
    }

    public void lookDoor(){
        System.out.println("狗看门");
    }
}
