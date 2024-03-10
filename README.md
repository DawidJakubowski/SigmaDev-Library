
# SigmaDev-Library

SigmaDev Library is an experimental tool I'm writing for my self for my game development. 

It's based on 
 - **SFML** (For Rendering Engine), 
 - **LibCURL** (For Networking Handling), 
 - **Sol2** (For Scripting), 
 - **json** (for handling configuration files)

It also uses google test for testing purposes.

It's currently developed by ***Dawid Jakubowski*** (me) and is going to be used further on development of his own video game(s), including (his first project) ***XenFight***.

Library is free to use, [under the MIT License.](./LICENSE) 

## Documentation

Documentation is going to be available under the [docs/ directory](docs/)

## How to build this library?

1. Clone this repository to a directory.
2. Open the terminal and go to this directory.
3. Create subdirectory named build/ (i.e. `mkdir build/`)
4. Enter this directory (`cd build/`)
5. Initialize CMake Script (For Unix systems: `cmake -G"Unix Makefiles" ../`)
6. Run make (`make -j2`)

## Further information

This library documentation, tutorials, and its code itself is going to be developed (I hope - almost every day), so the library is ready for use in no time. For me it's important that this library is developed as soon as possible, that's why I've decided that I'm working on it every day