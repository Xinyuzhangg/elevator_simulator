#pragma once
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include "elevator.h"
#include "texture.h"
#include <SDL_mixer.h>


extern int FloorNum;
extern int ElevatorNum;
const int WINDOW_WIDTH = 1080;
const int WINDOW_HEIGHT = 800;


class Building {
private:

	std::deque<BookedFloor> bookedFloors;
	std::map<int ,std::deque<Passenger>> passengersInBuilding;
	std::vector<Elevator> elevatorsInBuilding;

private:
	Mix_Music* gMusic;
	SDL_Renderer* gRenderer;
	SDL_Window* gWindow;
	TTF_Font* gFont;
	LTexture gTextTexture;
	LTexture gElevatorTexture;
	SDL_Rect  gClips[4];
	SDL_Window* window;
	SDL_GLContext gl_context;




private:
	bool Init();
	void LoadPassenagers();
	void ClearBuilding();
	bool RenderInit();
	bool LoadMedia();


public:
	Building();

public:

	void Execute();
	void Close();


};