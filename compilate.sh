if [ ! -d "./build" ]
then
    mkdir build
fi
cd build && conan install .. --build=missing && cmake .. -G "Unix Makefiles" && cmake --build .