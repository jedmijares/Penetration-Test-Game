#include "structs.h"

bool checkCollision(Entity e1, Entity e2)
{
    float top1 = e1.position.y;
    float bottom2 = e2.position.y + e2.h;
    if (bottom2 <= top1)
    {
        return false;
    }

    float top2 = e2.position.y;
    float bottom1 = e1.position.y + e1.h;
    if (bottom1 <= top2)
    {
        return false;
    }

    float left1 = e1.position.x;
    float right2 = e2.position.x + e2.w;
    if (right2 <= left1)
    {
        return false;
    }

    float left2 = e2.position.x;
    float right1 = e1.position.x + e1.w;
    if (right1 <= left2)
    {
        return false;
    }
    return true;
}

void keepOnscreen(Entity *entity)
{
    if (entity->position.x < 0)
        entity->position.x = 0;
    else if (entity->position.x + entity->w > SCREEN_WIDTH)
        entity->position.x = SCREEN_WIDTH - entity->w;
    if (entity->position.y < 0)
        entity->position.y = 0;
    else if (entity->position.y + entity->h > SCREEN_HEIGHT)
        entity->position.y = SCREEN_HEIGHT - entity->h;
}