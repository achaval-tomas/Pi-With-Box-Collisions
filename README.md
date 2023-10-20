# Pi-With-Box-Collisions
Approximating digits of PI with box Collisions in C++ visualized using SDL2. 

This is one of my first Coding Projects in C++, so it's far from perfect.

Libraries Used: SDL2, SDL_Image, SDL_Mixer, SDL_ttf, vector, time.

The goal is to approximate N digits of Pi by calculating the amount of perfectly elastic collisions of a 1kg Box with a 100^(N-1)Kg box and a wall.

Real perfectly elastic collisions are calculated and it's optimized to perform faster with bigger masses. 

There's music that I thought fit well with the project but it can easily be removed by deleting all SDL_Mixer related code.

![2023-08-02 (1)](https://github.com/achaval-tomas/Pi-With-Box-Collisions/assets/134091945/d32a7b07-58d2-4f13-a62e-5a18b02e87cd)

Run the visualization with with
````
g++ -o play -I include src/*.cpp \`sdl2-config --cflags --libs\` -lSDL2 -lSDL2_mixer -lSDL2_image -lSDL2_ttf
./play
````
Install necessary libraries:
````
sudo apt-get install libsdl2-dev
sudo apt-get install libsdl2-ttf-dev
sudo apt-get install libsdl2-mixer-dev
````
