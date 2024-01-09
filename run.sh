# 自动化测试脚本
if [ -d "build" ]; then
    rm -rf build
    echo "Build directory deleted, now creating a new one..."
fi

mkdir build
cd build
cmake ..
make -j6
