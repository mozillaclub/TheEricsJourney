#pragma once
#include <Enemy.h>
#include <Projectile.h>
#include <Player.h>
#include "game.h"

using namespace std;
using namespace sf;

class Fixedenemy: public Enemy{
    public:
        Fixedenemy();
        void Init();
        bool Attack();
        void PrepareSprite();
        void Update(float delta);
        void Draw(double percent, double delta );

        sf::Clock relojMark;
        void Die();
    protected:
    
        void SetAnimation();
    private:
        string texture_file;
};