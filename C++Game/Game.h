#pragma once
#include <SDL.h>
//#include "Actor.h"
#include "SpriteComponent.h"
#include <vector>


struct Vector2
{
	float x;
	float y;
};

class Game
{
public:
	Game();
	bool Initialize();
	void RunLoop();
	void Shutdown();
	//void AddActor(Actor* actor);
	void AddSprite(SpriteComponent* sprite);

private:
	void ProcessInput();
	void UpdateGame();
	void GenerateOutput();

	SDL_Window* mWindow;
	bool mIsRunning;
	SDL_Renderer* mRenderer;
	Uint32 mTicksCount;

	/*Vector2 mPaddlePos;
	int mPaddleDir;
	Vector2 mBallPos;
	Vector2 mBallVel;*/

	//std::vector<Actor> mActors;
	//std::vector<Actor> mPendingActors;
	bool mUpdatingActor;

};