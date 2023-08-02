#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <iostream>
#include <vector>
#include <time.h>

#include "RenderWindow.hpp"
#include "Utils.hpp"
#include "Text.hpp"
#include "Math.hpp"
#include "Physics.hpp"
#include "Constants.hpp"

int main(int argc, char* args[]){
	if (SDL_Init(SDL_INIT_VIDEO) > 0)
		std::cout << "HEY.. SDL_Init HAS FAILED. SDL_ERROR: " << SDL_GetError() << std::endl; 

	if (!(IMG_Init(IMG_INIT_PNG)))
		std::cout << "IMG_Init HAS FAILED. Error: " << SDL_GetError() << std::endl;

	if (TTF_Init() == -1)
		std::cout << "TTF_Init HAS FAILED. Error: " << SDL_GetError() << std::endl;

	if (Mix_Init(0) == -1)
		std::cout << "Mix_Init HAS FAILED. Error: " << SDL_GetError() << std::endl;

	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024);
    Mix_Music* instrumental  = Mix_LoadMUS("res/sfx/instrumental.wav");
    Mix_VolumeMusic(30);
    Mix_PlayMusic(instrumental, -1);

	RenderWindow window("Approximating Pi with physics", 1280, 720);
	SDL_Renderer* renderer = window.getRenderer();

	SDL_Texture* collisionHitTex     = window.loadTexture("res/gfx/collisionHit.png"     );

	SDL_Texture* oneKgTex             = window.loadTexture("res/gfx/1KgNew.png"          );
	SDL_Texture* oneHundredKgTex      = window.loadTexture("res/gfx/1HundredKg.png"      );
	SDL_Texture* tenThousandKgTex     = window.loadTexture("res/gfx/10Thousandkg.png"    );
	SDL_Texture* oneMillionKgTex      = window.loadTexture("res/gfx/1MillionKg.png"      );
	SDL_Texture* hundredMillionKgTex  = window.loadTexture("res/gfx/100MillionKg.png"    );
	SDL_Texture* tenBillionKgTex      = window.loadTexture("res/gfx/10BillionKg.png"     );
	SDL_Texture* oneTrillionKgTex     = window.loadTexture("res/gfx/1TrillionKg.png"     );
	SDL_Texture* hundredTrillionKgTex = window.loadTexture("res/gfx/100TrillionKg.png"   );
	SDL_Texture* tenQuadrillionKgTex  = window.loadTexture("res/gfx/10QuadrillionKg.png" );
	SDL_Texture* oneQuintillionKgTex  = window.loadTexture("res/gfx/1QuintillionKg.png"  );

	SDL_Texture* backOneKgTex             = window.loadTexture("res/gfx/background1kg.png"          );
	SDL_Texture* backOneHundredKgTex      = window.loadTexture("res/gfx/background100kg.png"      );
	SDL_Texture* backTenThousandKgTex     = window.loadTexture("res/gfx/background10000kg.png"    );
	SDL_Texture* backOneMillionKgTex      = window.loadTexture("res/gfx/background1000000kg.png"      );
	SDL_Texture* backHundredMillionKgTex  = window.loadTexture("res/gfx/background100000000kg.png"    );
	SDL_Texture* backTenBillionKgTex      = window.loadTexture("res/gfx/background10000000000kg.png"     );
	SDL_Texture* backOneTrillionKgTex     = window.loadTexture("res/gfx/background1000000000000kg.png"     );
	SDL_Texture* backHundredTrillionKgTex = window.loadTexture("res/gfx/background100000000000000kg.png"   );
	SDL_Texture* backTenQuadrillionKgTex  = window.loadTexture("res/gfx/background10000000000000000kg.png" );
	SDL_Texture* backOneQuintillionKgTex  = window.loadTexture("res/gfx/background1000000000000000000kg.png"  );

	Box oneKg(Vector2f(SMALLBOX_INIT_POSX, 561), oneKgTex, 1, 0);

	Box oneKgMove         (Vector2f(BIGBOX_INIT_POSX, 561), oneKgTex            ,                   1, -1);
	Box oneHundredKg      (Vector2f(BIGBOX_INIT_POSX, 536), oneHundredKgTex     ,                 100, -1);
	Box tenThousandKg     (Vector2f(BIGBOX_INIT_POSX, 511), tenThousandKgTex    ,               10000, -1);
	Box oneMillionKg      (Vector2f(BIGBOX_INIT_POSX, 411), oneMillionKgTex     ,             1000000, -1);
	Box hundredMillionKg  (Vector2f(BIGBOX_INIT_POSX, 311), hundredMillionKgTex ,           100000000, -1);
	Box tenBillionKg 	  (Vector2f(BIGBOX_INIT_POSX, 211), tenBillionKgTex     ,         10000000000, -1);
	Box oneTrillionKg     (Vector2f(BIGBOX_INIT_POSX, 111), oneTrillionKgTex    ,       1000000000000, -1);
	Box hundredTrillionKg (Vector2f(BIGBOX_INIT_POSX, 111), hundredTrillionKgTex,     100000000000000, -1);
	Box tenQuadrillionKg  (Vector2f(BIGBOX_INIT_POSX, 111), tenQuadrillionKgTex ,   10000000000000000, -1);
	Box oneQuintillionKg  (Vector2f(BIGBOX_INIT_POSX, 111), oneQuintillionKgTex , 1000000000000000000, -1);

	Box smallBox = oneKg;
	Box bigBox = oneKgMove;

	std::vector <Box> bigBoxes = {oneKgMove, oneHundredKg, tenThousandKg, oneMillionKg,
								  hundredMillionKg, tenBillionKg, oneTrillionKg, hundredTrillionKg,
								  tenQuadrillionKg, oneQuintillionKg };

	Entity backOneKg             (Vector2f(), backOneKgTex             );
	Entity backOneHundredKg      (Vector2f(), backOneHundredKgTex      );
	Entity backTenThousandKg     (Vector2f(), backTenThousandKgTex     );
	Entity backOneMillionKg      (Vector2f(), backOneMillionKgTex      );
	Entity backHundredMillionKg  (Vector2f(), backHundredMillionKgTex  );
	Entity backTenBillionKg      (Vector2f(), backTenBillionKgTex      );
	Entity backOneTrillionKg     (Vector2f(), backOneTrillionKgTex     );
	Entity backHundredTrillionKg (Vector2f(), backHundredTrillionKgTex );
	Entity backTenQuadrillionKg  (Vector2f(), backTenQuadrillionKgTex  );
	Entity backOneQuintillionKg  (Vector2f(), backOneQuintillionKgTex  );

	std::vector <Entity> backgrounds = {backOneKg, backOneHundredKg, backTenThousandKg, 
										backOneMillionKg, backHundredMillionKg, backTenBillionKg,
										backOneTrillionKg, backHundredTrillionKg, backTenQuadrillionKg,
										backOneQuintillionKg };

	Entity background = backOneKg;

	Entity collisionHit(Vector2f(-10, -10), collisionHitTex);

	// INITIALIZE KEYBOARD INPUTS ARRAY
	const Uint8* keyboard = SDL_GetKeyboardState(NULL);

	long long int collisionCounter = 0;
	int i = 0;

	float currentTime    = utils::hireTimeInSeconds();
	float lastReset      = currentTime;
	float lastTextTime   = currentTime;

	long double smallBoxX = smallBox.getPos().x;
	long double bigBoxX   = bigBox.getPos().x;

	bool simulationStarted = true;
	SDL_Event event;

/*                              GAME LOOP STARTS                                     */
	while (simulationStarted){

		currentTime = utils::hireTimeInSeconds();

		if (SDL_PollEvent(&event)){
			if (event.type == SDL_QUIT){
				simulationStarted = false;
			}
		}

		/*          COLLISIONS LOGIC HANDLING            */

		if (smallBox.checkCollision(&smallBox, &bigBox)){
			smallBox.handleCollision(&smallBox, &bigBox);
			++collisionCounter;
			collisionHit.setPos(Vector2f(smallBox.getPos().x + 45, 556));
		} else if (smallBox.getPos().x <= 110){
			smallBox.setVel(-smallBox.getVel());
			++collisionCounter;
			collisionHit.setPos(Vector2f(105, 556));
		}

		smallBox.handleMomentum(&smallBox, &bigBox);

		if (bigBox.getPos().x >= 160){

			if ( (keyboard[SDL_SCANCODE_SPACE] && (currentTime-lastReset > 0.5f) ) || bigBox.getPos().x > 1280){
				bigBox = bigBoxes[++i%10];
				background = backgrounds[i%10];
				collisionCounter = 0;
				smallBox = oneKg;
				bigBox.setVel(-1);
				collisionHit.setPos(Vector2f(-10, -10));
				lastReset = utils::hireTimeInSeconds();
			}

			window.clear();

			Text collisions(COLLISION_PARAMS);
			collisions.displayText(210, 11, renderer);
			collisions.destroyText();

			window.render(smallBox);
			window.render(bigBox);
			window.render(background);
			window.render(collisionHit);

			window.display();

		} else if (currentTime - lastTextTime > 0.033f){     // COMMENT THIS OUT FOR FASTER PERFORMANCE

			lastTextTime = currentTime;
			window.clear();

			smallBoxX = smallBox.getPos().x;
			bigBoxX = bigBox.getPos().x;

			smallBox.setPos(Vector2f(110 + rand()%6, smallBox.getPos().y));
			bigBox.setPos(Vector2f(165, bigBox.getPos().y));
			window.render(smallBox);
			window.render(bigBox);
			smallBox.setPos(Vector2f(smallBoxX, smallBox.getPos().y));
			bigBox.setPos(Vector2f(bigBoxX, bigBox.getPos().y));

			window.render(background);
			window.render(collisionHit);

			Text collisions(COLLISION_PARAMS);
			collisions.displayText(210, 11, renderer);
			collisions.destroyText();


			window.display();

		}

	}

	Mix_HaltMusic();
	window.cleanUp(); // DELETE EVERYTHING ON SCREEN
 	
 	Mix_Quit();
	TTF_Quit();     // QUIT ALL PROCESSES
	SDL_Quit(); 

	return 0;
}