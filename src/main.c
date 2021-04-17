#include "SDL2/SDL.h"
#include "init.h"
#include "draw.h"
#include "input.h"
#include "player.h"
#include "wall.h"

App app;
static Entity *player;

static void logic(void);

static void draw(void);

static void reset(void);

int main(int argc, char *argv[])
{
	memset(&app, 0, sizeof(App));
	initSDL();
	atexit(cleanup);
	app.delegate.logic = logic;
	app.delegate.draw = draw;

	player = initPlayer();
	Entity wallEntity;
	wallEntity.position.x = SCREEN_WIDTH / 2;
	wallEntity.position.y = SCREEN_HEIGHT / 2;
	wallEntity.h = 100;
	wallEntity.w = 100;
	initWall(wallEntity);

	while (1)
	{
		prepareScene();
		updateInput();
		app.delegate.logic();
		app.delegate.draw();
		presentScene();
	}

	return 0;
}

static void logic(void)
{
	updatePlayer(player);
}

static void draw(void)
{
	drawPlayer(*player);
	drawWalls();
}

static void reset(void)
{
}