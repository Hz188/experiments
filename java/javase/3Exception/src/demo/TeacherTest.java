package demo;

import java.util.Scanner;

public class TeacherTest {
    public static void main(String[] args) {
        Teacher t = new Teacher();
        Scanner sc =new Scanner(System.in);
        int score = sc.nextInt();
        try {
            t.checkScore(score);
        } catch (ScoreException e) {
            e.printStackTrace();
        }
    }
}
