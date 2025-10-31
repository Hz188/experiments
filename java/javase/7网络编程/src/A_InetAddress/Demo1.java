package A_InetAddress;

import java.net.InetAddress;
import java.net.UnknownHostException;

public class Demo1 {
    public static void main(String[] args) throws UnknownHostException {
//        InetAddress address = InetAddress.getByName("DESKTOP-OGMQKRF");
        InetAddress address = InetAddress.getByName("169.254.192.131");
        String name = address.getHostName();
        String ip = address.getHostAddress();
        System.out.println("name = " + name);
        System.out.println("ip = " + ip);

    }
}
