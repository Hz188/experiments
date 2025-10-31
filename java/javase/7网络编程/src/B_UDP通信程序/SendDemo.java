package B_UDP通信程序;
/*
1. 创建发送端的Socket对象(DatagramSocket)
    new DatagramSocket()
2. 创建数据, 并把数据打包
    DatagramPacket(byte[] buf, int length, InetAddress address, int port)
3. 调用DatagramSocket对象的方法发送数据
    void send(DatagramPacket p)
4. 关闭发送端
    void close()
 */

import java.io.IOException;
import java.net.*;

public class SendDemo {
    public static void main(String[] args) throws IOException {
        DatagramSocket s = new DatagramSocket();

        //DatagramPacket(byte[] buf, int length, InetAddress address, int port)
        byte[] bys = "hello, udp, I'm coming!".getBytes();
//        int len = bys.length;
//        InetAddress add = InetAddress.getByName("169.254.192.131");
//        int port = 10086;
//        DatagramPacket dp = new DatagramPacket(bys, len, add,port);
        DatagramPacket dp = new DatagramPacket(bys, bys.length, InetAddress.getByName("169.254.192.131"),10086);

        s.send(dp);
        s.close();

    }
}
