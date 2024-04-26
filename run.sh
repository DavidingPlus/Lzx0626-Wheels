# 自动化测试脚本
if [ ! -d "build" ]; then
    mkdir build
    echo "Build directory deleted, now creating a new one..."
fi

cd build
cmake -DENABLE_GTEST=ON ..
make -j 6
