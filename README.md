# Pi-With-Box-Collisions
Approximating digits of PI with box Collisions in C++ visualized using SDL2. 

This is one of my first Coding Projects in C++, so it's far from perfect.

Libraries Used: SDL2, SDL_Image, SDL_Mixer, SDL_ttf, vector, time.

The goal is to approximate N digits of Pi by calculating the amount of perfectly elastic collisions of a 1kg Box with a 100^(N-1)Kg box and a wall.

Real perfectly elastic collisions are calculated and it's optimized to perform faster with bigger masses. 

There's music that I thought fit well with the project but it can easily be removed by deleting all SDL_Mixer related code.

![2023-08-02 (1)](https://github.com/achaval-tomas/Pi-With-Box-Collisions/assets/134091945/d32a7b07-58d2-4f13-a62e-5a18b02e87cd)

Play with (Windows, mingw32)
````
start bin/release/main
````
Compile with
````
g++ -c src/*.cpp -std=c++14 -O3 -Wall -m64 -I include -I C:/SDL2-w64/include && g++ *.o -o bin/release/main -s -L C:/SDL2-w64/lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer
````
