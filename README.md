# Gauntlet Mini 2026 entries


Author: Joshua Ling Xian Le
## THEME : MALAYSIA DAY
## What is the game about:
Malaysia is our home, and our home also has a cute member. No it is not Kuching cat, it is Cicak the gecko. 

This is about the adventure the cicak embark everyday to grow stronger and stronger. Finally one day, he can discover the secret of the malaysia greatness.

## Instruction to build and run
This game is only available to linux/WSL.

run following steps on linux/WSL to built and play the game

- git clone (might take 10 minutes to download raylib submodule)

1. sudo apt update
2. sudo apt install -y build-essential libasound2-dev libx11-dev libxrandr-dev libxi-dev libxcursor-dev libxinerama-dev libgl1-mesa-dev
3. git clone --recurse-submodules https://github.com/rbserve/Pet-Gecko-Adventure
4. make
5. ./mygame

6. (in case no audio)
sudo apt install libasound2-dev libpulse-dev

## Tech used:
- c++ - main coding language
- raylib - for rendering components and window creation to audio system. It simplify the development process.


## c++ workshop application

I have apply const-correct, cleanly structured code of Week 1 Day 1 throughout my codebase. 

I have used smart pointers and vector to store varies class and encapsulate them with virtual function. For example, my entity class have 2 derived child class Gecko and flies. I can easily add new entity such as Cat or spider without duplicate codes. This is for day2 to day 4.

I have used facade from day 5 in varies place, when resetting gecko, resetting levelGenerator, drawing objects which order mattered.

Lastly, I have implement simple pathfinding algorithm for gecko that it will get the next step instead of knowing the whole route, because the target will change frequently.


## what I cut and what I'll do with more time
I cut A lot of stuff, I was planning to add more entity such as boss kuching the cat, and spider. 

The secret found in the game is also a placeholder. There is no secret so far in the game, was planning to add discoverable item that teach the player about Malaysia and decorate the cicak home as well.

On the technicall side of thing, the flies and gecko are not animated. I was planning to dynamically render cicak body to bend and twist, it will make it more intersting and realistic.

If I have more time, I will go ahead and complete secret discoverable items. However, plan doesn't always go well. I will add more entities as well to make the game more variety. I will said this game is 60% complete.

## demo video
https://drive.google.com/file/d/1BYyTsEU3VeOt9lim8OnXrC3Jfj9GcSOI/view?usp=sharing


# License
This project uses raylib, licensed under the [zlib/libpng license](https://github.com/raysan5/raylib/blob/master/LICENSE).

- [raylib](https://www.raylib.com/) — a simple and easy-to-use library to enjoy videogames programming, created by [Ramon Santamaria](https://github.com/raysan5) and [contributors](https://github.com/raysan5/raylib/graphs/contributors).

Background Music by <a href="https://pixabay.com/users/soundore-50821731/?utm_source=link-attribution&utm_medium=referral&utm_campaign=music&utm_content=366903">Soundore</a> from <a href="https://pixabay.com/music//?utm_source=link-attribution&utm_medium=referral&utm_campaign=music&utm_content=366903">Pixabay</a>