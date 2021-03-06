#include "SDL2/SDL.h"
#include "init.h"
#include "draw.h"
#include "input.h"
#include "player.h"
#include "wall.h"
#include "goal.h"
#include "stage.h"

App app;

static void logic(void);
static void draw(void);
// static void reset(void);

int main(int argc, char *argv[])
{
	memset(&app, 0, sizeof(App));
	initSDL();
	atexit(cleanup);
	app.delegate.logic = logic;
	app.delegate.draw = draw;

	// initPlayer();
	// Entity wallEntity;
	// wallEntity.position.x = SCREEN_WIDTH / 3;
	// wallEntity.position.y = SCREEN_HEIGHT / 3;
	// wallEntity.h = 300;
	// wallEntity.w = 200;
	// initWall(wallEntity);
	// initGoal();
	initStage0();

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
	updatePlayer();
	updateGoal();
}

static void draw(void)
{
	drawWalls();
	drawKillzones();
	drawGoal();
	drawPlayer();
}

// static void reset(void)
// {
// }