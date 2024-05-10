package F_practice4;

public class Test {
    public static void main(String[] args) {
        //1.
        useStudentBuilder((name, age) -> new Student(name, age));

        //2.
        useStudentBuilder(Student::new);

        //Lambda表达式被构造器替代的时候，它的形式参数全部传递给构造器作为参数
    }

    private static void useStudentBuilder(StudentBuilder sb) {
        Student s = sb.build("haozhe", 19);
        System.out.println(s);
    }
}
