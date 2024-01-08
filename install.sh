# 本脚本是一个自动安装脚本，也可以自己手动编译

# 1.卸载旧版本
./uninstall.sh

# 2.通过CMake工具构建编译
if [ ! -d "build" ]; then
    mkdir build
fi

cd build
cmake ..
make

# 3.安装
sudo make install
