package D_constructor;

public class StudentTest {
    public static void main(String[] args) {
        Student s = new Student("Hz",18);
        System.out.println(s);

        Student s2 = new Student();
        System.out.println(s2);
    }
}
