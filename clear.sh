# 删除build目录
if [ ! -d "build" ]; then
    echo "Build directory not found..."
else 
    rm -rf build
    echo "Build directory deleted..."
fi
