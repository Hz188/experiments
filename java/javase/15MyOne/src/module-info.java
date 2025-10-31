import space.hzzy.MyService;
import space.hzzy.impl.Service1;
import space.hzzy.impl.Service2;

module MyOne {
    exports space.hz;
    exports space.hzzy;
//    provides MyService with Service1;
    provides MyService with Service2;
}