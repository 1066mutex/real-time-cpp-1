
# using make files in ref_app/target/app/make

```sh
cd real-time-cpp
cd ref_app
./target/build/build.sh avr rebuild
```

# this uses the make files not cmake.

/////////////////////////////////////////////////

# using cmake:

```sh
cd real-time-cpp
mkdir build
cd build
cmake ../ref_app -DTRIPLE=arm-none-eabi -DTARGET=stm32f446 -DCMAKE_TOOLCHAIN_FILE=../ref_app/cmake/gcc-toolchain.cmake
make -j ref_app
```

# this method use the cmake files in: 
ref_app/cmake
ref_app
main project directory
