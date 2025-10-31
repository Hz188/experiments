package A_Hz.demo_02;

public class StudentTest {
    public static void main(String[] args) {
        Student s1 = new Student();
        Student s2 = new Student();
        s1.setAge(18);
        s2.setName("A_Hz");
        s1.doHomework();
        s2.study();
    }
}
