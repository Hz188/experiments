package F_Object;

public class demo1 {
    public static void main(String[] args) {
        Student s1 = new Student();
        s1.setAge(19);
        s1.setName("Hz");
        System.out.println(s1);

        Student s2 = new Student();
        s2.setAge(19);
        s2.setName("Hz");

        System.out.println(s1==s2);
        System.out.println(s1.equals(s2));
    }
}
