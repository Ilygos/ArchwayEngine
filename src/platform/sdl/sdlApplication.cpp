#include "sdlApplication.hpp"
#include "core/common.hpp"
#include "math/vector.hpp"
#include <SDL2/SDL.h>
#include "input/InputMgr.h"

uint32 SDLApplication::numInstances = 0;

SDLApplication* SDLApplication::create()
{
	const uint32 flags = SDL_INIT_AUDIO | SDL_INIT_VIDEO | SDL_INIT_EVENTS;
	uint32 initialized = SDL_WasInit(flags);
	if(initialized != flags &&
			SDL_Init(flags) != 0) {
		DEBUG_LOG("SDLApplication", LOG_ERROR, "SDL_Init: %s", SDL_GetError());
		return nullptr;
	}

	return new SDLApplication();
}

SDLApplication::SDLApplication()
{
	numInstances++;
	isAppRunning = true;
}

SDLApplication::~SDLApplication()
{
	numInstances--;
	if(numInstances == 0) {
		SDL_Quit();
	}
}

void SDLApplication::processMessages(double delta)
{
	SDL_Event e;
	(void)delta;
	
	while(SDL_PollEvent(&e)) {
		switch(e.type){
		case SDL_KEYDOWN:
			INPUT_MGR->OnKeyDown(e.key.keysym.scancode, e.key.repeat != 0);
			break;
		case SDL_KEYUP:
			INPUT_MGR->OnKeyUp(e.key.keysym.scancode, e.key.repeat != 0);
			break;
		case SDL_MOUSEBUTTONDOWN:
			INPUT_MGR->OnMouseDown(e.button.button, e.button.clicks);
			break;
		case SDL_MOUSEBUTTONUP:
			INPUT_MGR->OnMouseUp(e.button.button, e.button.clicks);
			break;
		case SDL_MOUSEMOTION:
			INPUT_MGR->OnMouseMove(Vector2f(e.motion.x, e.motion.y), Vector2f(e.motion.xrel, e.motion.yrel));
			break;
		case SDL_QUIT:
			isAppRunning = false;
			break;
		default:
			break;
		};
	}
}

bool SDLApplication::isRunning()
{
	return isAppRunning;
}

