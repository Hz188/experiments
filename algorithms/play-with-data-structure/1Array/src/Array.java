public class Array<E> {

    private E[] data;
    private int size;

    //构造函数，传入数组的容量capacity构造Array
    public Array(int capacity) {
        data = (E[]) new Object[capacity];
        size = 0;
    }

    // 无参构造函数，默认capacity为10
    public Array() {
        this(10); // 通过this调用其他的构造函数
    }

    // 获取数组元素个数
    public int getSize() {
        return size;
    }

    // 获取数组容量
    public int getCapacity() {
        return data.length;
    }

    // 判断数组是否为空
    public boolean isEmpty() {
        return size == 0;
    }

    // 向指定index位置插入元素
    // size指向的位置是没有元素的空位置
    // 比如 size = 3 [1,1,1,size] 所以size就是addLast添加的元素的位置
    public void add(int index, E e) {

        if (index < 0 || index > size) {
            throw new IllegalArgumentException("Add failed. Require index >= 0 and index < size");
        }
        if (size == data.length) {
            // throw new IllegalArgumentException("AddLast failed. Array is full.");
            resize(2 * data.length);
        }
        for (int i = size - 1; i >= index; i--) {
            data[i + 1] = data[i];
        }
        data[index] = e;
        size++;
    }

    // 添加元素到开头
    public void addFirst(E e) {
        add(0, e);
    }

    // 添加元素到最后
    public void addLast(E e) {
        add(size, e);
    }

    // 得到index处的元素
    public E get(int index) {
        if (index < 0 || index >= size) {
            throw new IllegalArgumentException("Get failed. Index is illegal.");
        }
        return data[index];
    }

    // 修改index处的元素
    public void set(int index, E e) {
        if (index < 0 || index >= size) {
            throw new IllegalArgumentException("Set failed. Index is illegal.");
        }
        data[index] = e;
    }

    // 查找数组中是否含有元素e
    public boolean contains(E e) {
        for (int i = 0; i < size; i++) {
            if (data[i].equals(e)) {
                return true;
            }
        }
        return false;
    }

    // 查找索引，不存在返回-1
    public int find(E e) {
        for (int i = 0; i < size; i++) {
            if (data[i].equals(e)) {
                return i;
            }
        }
        return -1;
    }

    // 查找元素e的所有索引
    public int findAll(int e) {

        return 0;
    }

    //删除index处的元素，并返回删除的元素
    public E remove(int index) {
        if (index < 0 || index >= size) {
            throw new IllegalArgumentException("Remove failed. Index is illegal.");
        }
        E ret = data[index];
        for (int i = index + 1; i < size; i++) {
            data[i - 1] = data[i];
        }
        size--;
        data[size] = null;  // loitering objects != memory leak
        if (size == data.length / 4 && data.length / 2 != 0)  // 不能 new 一个长度为1的数组
            resize(data.length / 2);
        return ret;
    }

    // 删除第一个元素，并返回删除的元素
    public E removeFirst() {
        return remove(0);
    }

    // 删除最后一个元素，并返回删除的元素
    public E removeLast() {
        return remove(size - 1);
    }

    // 看是否有e元素，若有则删除，但是此方法目前仅仅删除一个元素
    public void removeElement(E e) {
        int index = find(e);
        if (index != -1)
            remove(index);
    }

    // 删除所有元素e
    public void removeAllElement(E e) {
        for (int index = find(e); index != -1; index = find(e)) {
            remove(index);
        }
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(String.format("Array: size = %d , capacity = %d\n", size, data.length));
        sb.append("[");
        for (int i = 0; i < size; i++) {
            sb.append(data[i]);
            if (i != size - 1) {
                sb.append(", ");
            }
        }
        sb.append("]");
        return sb.toString();
    }

    private void resize(int newCapacity) {
        E[] newData = (E[]) new Object[newCapacity];
        for (int i = 0; i < size; i++) {
            newData[i] = data[i];
        }
        data = newData;
    }
}
