#include "pch.h"
#include "Game.h"

//const int thickness = 15;
//const float paddleH = 100.0f;
const int windowW = 1024;
const int windowH = 768;


Game::Game()
	:mWindow(nullptr)
	, mRenderer(nullptr)
	, mTicksCount(0)
	, mIsRunning(true)
	//, mPaddleDir(0)
{

}

bool Game::Initialize()
{
	int sdlResult = SDL_Init(SDL_INIT_VIDEO);
	if (sdlResult != 0)
	{
		SDL_Log("SDL cannot be initialized : %s", SDL_GetError());
		return false;
	}
	mWindow = SDL_CreateWindow(
		"Game",
		100,
		100,
		windowW,
		windowH,
		0
	);
	if (!mWindow)
	{
		SDL_Log("Cannot create a window : %s", SDL_GetError());
		return false;
	}
	mRenderer = SDL_CreateRenderer(
		mWindow,
		-1,
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
	);
	if (!mRenderer)
	{
		SDL_Log("Cannot initalize renderer : %s", SDL_GetError());
		return false;
	}

	/*//Initalize game obj
	mBallPos.x = windowH / 2.0f;
	mBallPos.y = windowW / 2.0f;
	mPaddlePos.x = thickness;
	mPaddlePos.y = windowH / 2.0f;
	mBallVel.x = -200.f;
	mBallVel.y = 235.f;
	*/
	return true;
}


void Game::RunLoop()
{
	while (mIsRunning)
	{
		ProcessInput();
		UpdateGame();
		GenerateOutput();
	}
}

void Game::ProcessInput()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			mIsRunning = false;
			break;
		}
	}

	const Uint8* state = SDL_GetKeyboardState(NULL);
	if (state[SDL_SCANCODE_ESCAPE])
	{
		mIsRunning = false;
	}
	/*
		//Paddle move
	mPaddleDir = 0;

	if (state[SDL_SCANCODE_W])
	{
		mPaddleDir -= 1;
	}

	if (state[SDL_SCANCODE_S])
	{
		mPaddleDir += 1;
	}
	*/


}

void Game::UpdateGame()
{
	while (!SDL_TICKS_PASSED(SDL_GetTicks(), mTicksCount + 16));
	float deltaTime = (SDL_GetTicks() - mTicksCount) / 1000.0f;
	mTicksCount = SDL_GetTicks();
	if (deltaTime > 0.05f)
	{
		deltaTime = 0.05f;
	}

	/*if (mPaddleDir != 0)
	{
		mPaddlePos.y += mPaddleDir * 300.0f*deltaTime;
		if (mPaddlePos.y < (paddleH / 2.0f + thickness))
		{
			mPaddlePos.y = paddleH / 2.0f + thickness;
		}
		else if (mPaddlePos.y > (768.0f - paddleH / 2.0f - thickness))
		{
			mPaddlePos.y = 768.0f - paddleH / 2.0f - thickness;
		}
	}

	//mBallPos.x = mBallVel.x += deltaTime;
	//mBallPos.y = mBallVel.y += deltaTime;
	*/
}

void Game::GenerateOutput()
{
	/*SDL_SetRenderDrawColor(mRenderer,0,0,255,255);
	SDL_RenderClear(mRenderer);
	SDL_SetRenderDrawColor(mRenderer, 255, 255, 255, 255);
	//top wall
	SDL_Rect wall{
		0,0,1024,thickness
	};
	SDL_RenderFillRect(mRenderer, &wall);
	//bottom wall
	wall.y = 768 - thickness;
	SDL_RenderFillRect(mRenderer, &wall);
	//right wall	
	wall.x = 1024 - thickness;
	wall.y = 0;
	wall.w = thickness;
	wall.h = 1024;
	SDL_RenderFillRect(mRenderer, &wall);

	SDL_Rect ball{
		static_cast<int>(mBallPos.x-thickness/2),
		static_cast<int>(mBallPos.y-thickness/2),
		thickness,
		thickness,
	};
	SDL_RenderFillRect(mRenderer, &ball);

	SDL_Rect paddle{
		static_cast<int>(mPaddlePos.x),
		static_cast<int>(mPaddlePos.y),
		thickness,
		paddleH
	};
	SDL_RenderFillRect(mRenderer, &paddle);

	SDL_RenderPresent(mRenderer);*/
}

void Game::Shutdown()
{
	SDL_DestroyRenderer(mRenderer);
	SDL_DestroyWindow(mWindow);
	SDL_Quit();
}

/*void Game::AddActor(Actor* actor)
{
	if (mUpdatingActor)
	{
		mActors.emplace_back(actor);
	}
	else
	{
		mPendingActors.emplace_back(actor);
	}
}*/