#pragma once
#include "pch.h"
#include <SDL.h>
#include <vector>
#include "Game.h"



class Actor
{
public:
	enum State
	{
		EActive,
		EPaused,
		EDead
	};
	Actor(class Game* game);
	virtual ~Actor();

	void Update(float deltaTime);
	void UpdateComponents(float deltaTime);
	virtual void UpdateActor(float deltaTime);

	void AddComponents(class Component* component);
	void RemoveComponent(class Component* component);

private:
	State mState;
	Vector2 mPosition;
	float mScale;
	float mRotation;

	std::vector<class Component*> mComponents;
	class Game* mGame;
};