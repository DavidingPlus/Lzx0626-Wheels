# 本脚本是一个自动安装脚本，也可以自己手动编译

# 1.卸载旧版本
# 删除/usr/include/lzx0626目录
sudo rm -rf /usr/include/lzx0626
echo "Delete header file successfully."

# 删除/lib64目录中的liblzx0626*.a文件
sudo rm -rf /lib64/liblzx0626*.a
echo "Delete static library successfully."

# 2.通过CMake工具构建编译
if [ ! -d "build" ]; then
    mkdir build
fi

cd build
cmake -DENABLE_GTEST=OFF ..
make

# 3.安装
sudo make install
