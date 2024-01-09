# 自动化测试脚本
if [ ! -d "build" ]; then
    mkdir build
    echo "Build directory deleted, now creating a new one..."
fi

cd build
cmake -Denable_snippet=ON -Denable_gtest=ON ..
make -j6
