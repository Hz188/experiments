package C_TCPDemo;

import java.io.IOException;
import java.io.OutputStream;
import java.net.InetAddress;
import java.net.Socket;

public class ClientDemo {
    public static void main(String[] args) throws IOException {
//        Socket​(InetAddress host, int port, boolean stream)
//        Socket s = new Socket(InetAddress.getByName("169.254.192.131"),10000);

//        Socket​(String host, int port)
        Socket s =new Socket("169.254.192.131",10000);
        OutputStream os = s.getOutputStream();
        os.write("hello, TCP, I'm coming!".getBytes());


        s.close();
    }
}
