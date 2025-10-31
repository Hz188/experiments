import paddle

def share_buffer_demo():
    print("=== 张量内存缓冲区共享演示 ===\n")
    
    # 创建源张量并填充数据
    src_tensor = paddle.to_tensor([1.0, 2.0, 3.0], stop_gradient=True)
    print("1. 创建源张量:")
    print("   源张量初始值:", src_tensor.numpy())
    print("   源张量内存地址:", src_tensor.data_ptr())
    
    # 创建目标张量（未初始化）
    dst_tensor = paddle.to_tensor([0.0, 0.0, 0.0], stop_gradient=True)
    print("\n2. 创建目标张量:")
    print("   目标张量初始值:", dst_tensor.numpy())
    print("   目标张量内存地址:", dst_tensor.data_ptr())
    
    # 共享内存缓冲区
    print("\n3. 执行 _share_buffer_to 操作...")
    src_tensor._share_buffer_to(dst_tensor)
    
    # 验证共享结果
    print("\n4. 共享缓冲区后:")
    print("   源张量值:", src_tensor.numpy())
    print("   源张量内存地址:", src_tensor.data_ptr())
    print("   目标张量值:", dst_tensor.numpy())
    print("   目标张量内存地址:", dst_tensor.data_ptr())
    
    # 验证内存地址是否相同
    if src_tensor.data_ptr() == dst_tensor.data_ptr():
        print("   ✅ 内存地址相同，缓冲区共享成功！")
    else:
        print("   ❌ 内存地址不同，共享失败")
    
    # 通过非原地操作修改源张量
    print("\n5. 通过赋值操作修改源张量...")
    new_src = paddle.to_tensor([10.0, 20.0, 30.0], stop_gradient=True)
    src_tensor.assign(new_src, )
    
    print("   修改后源张量:", src_tensor.numpy())
    print("   修改后目标张量:", dst_tensor.numpy())

    print("\n=== 演示完成 ===")

if __name__ == "__main__":
    share_buffer_demo()
