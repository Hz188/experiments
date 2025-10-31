package D_特殊操作流.PropertiesDemo;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Properties;

// 与 IO相结合
public class Demo3 {
    public static void main(String[] args) throws IOException {
        //把集合中的数据保存到文件
//        myStore();


        //把文件中的数据加载到集合
        myLoad();
    }

    private static void myLoad() throws IOException {
        Properties prop = new Properties();
        //    public synchronized void load(Reader reader)

        FileReader fr = new FileReader("IO\\src\\D_特殊操作流\\PropertiesDemo\\fw.txt");
        prop.load(fr);

        System.out.println(prop);

        fr.close();
    }

    private static void myStore() throws IOException {
        Properties prop = new Properties();

        prop.setProperty("001","demo1");
        prop.setProperty("002","demo2");
        prop.setProperty("003","demo3");

        //    public void store(Writer writer, String comments)
        FileWriter fw = new FileWriter("IO\\src\\D_特殊操作流\\PropertiesDemo\\fw.txt");
        prop.store(fw, null);
        fw.close();

    }
}
