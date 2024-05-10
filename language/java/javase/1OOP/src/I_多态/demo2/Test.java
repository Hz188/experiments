package I_多态.demo2;

public class Test {
    public static void main(String[] args) {
        Animal ani = new Cat();
        System.out.println(ani.age);
//        System.out.println(ani.weight); //error

        ani.eat();
//        ani.play();   //error
    }
}
