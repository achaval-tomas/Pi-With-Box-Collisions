# Pi-With-Box-Collisions
Approximating digits of PI with box Collisions in C++ visualized using SDL2. 

This is one of my first Coding Projects in C++, so it's far from perfect. Feel free to **contribute improvements and optimizations** via Pull Requests.

The goal is to **approximate N digits of Pi** by calculating the amount of **[perfectly elastic collisions](https://en.wikipedia.org/wiki/Elastic_collision) of a 1kg Box with a 100^(N-1)Kg box** and a wall.

Real perfectly elastic collisions are calculated and it's optimized to perform faster with bigger masses. 

There's music that I thought fit well with the project but it can easily be removed by deleting all SDL_Mixer related code.

## Full Run-Through
https://github.com/achaval-tomas/Pi-With-Box-Collisions/assets/134091945/66264de8-5f13-4a7d-bd42-e61c81512b85

## How to run the simulation
On windows
````
start bin/release/main
````
On Linux, or WSL
````
./bin/release/mainLinux
````

## How to re-compile it
On windows with [mingw](https://www.mingw-w64.org/)
````
g++ -c src/*.cpp -std=c++14 -O3 -Wall -m64 -I include -I /bin/release && g++ *.o -o bin/release/main -s -L /bin/release -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer
````
On Linux, or [WSL](https://learn.microsoft.com/es-es/windows/wsl/install)
````
g++ -c src/*.cpp -std=c++14 -O3 -Wall -m64 -I include -I /bin/release && g++ *.o -o bin/release/mainLinux -s -L /bin/release -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer
````

<ins>**Note:**</ins> **Necessary Libraries are included in bin/release. If this doesn't work for you, you may need to [Download and install SDL](https://www.libsdl.org/) and/or [mingw](https://www.mingw-w64.org/)**
