# Pi-With-Box-Collisions
Approximating digits of PI with box Collisions in C++ visualized using SDL2. 

This is one of my first Coding Projects in C++, so it's far from perfect.

Libraries Used: SDL2, SDL_Image, SDL_Mixer, SDL_ttf, vector, time.

The goal is to approximate N digits of Pi by calculating the amount of perfectly elastic collisions of a 1kg Box with a 100^(N-1)Kg box and a wall.

Real perfectly elastic collisions are calculated and it's optimized to perform faster with bigger masses. 

There's music that I thought fit well with the project but it can easily be removed by deleting all SDL_Mixer related code.

## Full Run-Through
https://github.com/achaval-tomas/Pi-With-Box-Collisions/assets/134091945/66264de8-5f13-4a7d-bd42-e61c81512b85


Play with (Windows, mingw32)
````
start bin/release/main
````
Compile with
````
g++ -c src/*.cpp -std=c++14 -O3 -Wall -m64 -I include -I /bin/release && g++ *.o -o bin/release/main -s -L /bin/release -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer
````

**Necessary Libraries are included in bin/release. If this doesn't work for you, you may need to [Download and install SDL](https://www.libsdl.org/) and/or [mingw](https://www.mingw-w64.org/)**
