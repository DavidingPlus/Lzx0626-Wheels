if [ ! -d "build" ]; then
    mkdir build
    echo "Build directory deleted, now creating a new one..."
fi

cd build
cmake -DENABLE_GTEST=OFF ..
make -j6

# TODO
# make install
