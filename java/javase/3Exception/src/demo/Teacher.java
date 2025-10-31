package demo;

public class Teacher {
    public static void main(String[] args) {

    }
    public void checkScore(int score) throws ScoreException{
        if (score<0 || score>100) {
//            throw new ScoreException();
            throw new ScoreException("分数有误，应该在 0 - 100 之间");
        } else {
            System.out.println("分数正常");
        }
    }
}
