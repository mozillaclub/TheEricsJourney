#pragma once
#include <Actor.h>


class Pawn: public Actor {
    public:
        Pawn();

        string texture_file;
        sf::Sprite sprite;

        Vector2f location;
        Vector2f direction;

        float movementSpeed;

        /************************************************************
         * ENEMIGO START
         * **************************************************/

        float health_MAX;
        float health_Current;

        float damage_Base;
        float damage_Multiplier; 


        void TakeDamage(float damage, string damage_type);
        bool IsAlive(); // This should go to an interface or to parent PAWN class

        // Adds movement to the desired direction
        void UpdateMovement(); 

        sf::CircleShape bala = sf::CircleShape(5);

        bool Attack();

        void Update(float delta);

    protected:
        Clock cD, cInterp, cMov;

        void PrepareSprite();

        // Apply dying effects
        void Die();
        // Apply hit effects on takeDamage()
        void ApplyHitEffects(string effect); // TODO: effect should be a class of type damage_type, not  astring
};