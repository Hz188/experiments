package B_UDP通信程序;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;

public class RecvDemo {
    public static void main(String[] args) throws IOException {

        DatagramSocket s = new DatagramSocket(10086);

        //DatagramPacket(byte[] buf, int length)
        byte[] bys = new byte[1024];
        DatagramPacket recvData = new DatagramPacket(bys, bys.length);

        s.receive(recvData);
        byte[] data = recvData.getData();
        int len = recvData.getLength();
//        String data1 = new String(data);
        String data1 = new String(data,0,len);
        System.out.println(data1);
        s.close();
    }
}
