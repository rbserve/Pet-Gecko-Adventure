# Gauntlet Mini 2026 entries
## THEME : MALAYSIA DAY

Author: Joshua Ling Xian Le

## What is the game about:
- blah blah blah

## Instruction to build and run
### run following steps on linux/WSL after git clone 
1. sudo apt update
2. sudo apt install -y libraylib-dev

install raylib 

If that package isn't available:

git clone --depth 1 https://github.com/raysan5/raylib.git
cd raylib/src
make PLATFORM=PLATFORM_DESKTOP
sudo make install PLATFORM=PLATFORM_DESKTOP
cd ../..

3. git clone --recurse-submodules https://github.com/yourusername/mygame.git
4. cd mygame
5. make
6. ./mygame

### run following steps on windows after git clone
1. Install w64devkit 
Download: https://github.com/skeeto/w64devkit/releases
2. Grab the latest w64devkit-x.x.x.zip
3. Extract to C:\w64devkit
4. Run w64devkit.exe inside that folder — this opens a terminal with everything ready

5.  Download prebuilt raylib
Go to: https://github.com/raysan5/raylib/releases
Download raylib-X.X.X_win64_mingw-w64.zip (must match the mingw compiler w64devkit uses)

6. Extract it to C:\raylib (so it becomes C:\raylib\include and C:\raylib\lib — matches the Makefile's RAYLIB_PATH)


## Tech used:
- c++ (main coding language)
- raylib (for rendering components and window creation)

ps which library you chose and why, and what you built yourself versus what the library gave you

## stuff
-- a short "where Week 1 shows up in this code" map: const correctness, ownership/RAII, class design, containers, any pattern, any algorithm, tests

## stuff
-- what you cut and what you'd do differently with more time

-- demo 10 minutes 


# License
This project uses raylib, licensed under the [zlib/libpng license](https://github.com/raysan5/raylib/blob/master/LICENSE).

- [raylib](https://www.raylib.com/) — a simple and easy-to-use library to enjoy videogames programming, created by [Ramon Santamaria](https://github.com/raysan5) and [contributors](https://github.com/raysan5/raylib/graphs/contributors).