#pragma once
#ifndef ENGINE_H
#define ENGINE_H

#include <SFML/Graphics.hpp>
//#include <Actor.h>
#include <iostream>
//#include <algorithm>

using namespace std;

struct AnimFrame {
   sf::IntRect rect;
   double duration; // in milliseconds
};

enum Faction { enemy=2, allie=1, neutral=0 };
enum ObjectType { worldstatic=0, worlddynamic=1, pawn=2, projectile=3, trap=4, blocker=5 }; // NOTA: Parece que c++ no permite que los nombres de una enum tengan mayusculas!!

/***********************
 * 
 * CLASS: ENGINE
 * 
 * **********************/
class Engine
{
    public:
        static Engine* Instance();
        void init(/*char*, int*/);
        sf::RenderWindow &getApp(){ return app; }
        sf::RenderWindow &CreateApp(sf::VideoMode vm, string wn);
        std::string getObjectType(ObjectType type) { if(type <= sizeof(oTypeNames)) { return oTypeNames[type]; } };
        void setView(float centerY, float borderX);
    protected:
        Engine();
        Engine(const Engine &);
        Engine &operator= (const Engine &);
        virtual ~Engine();
        //std::map<std::string, sf::Texture> LoadedTextures;
    private:
        static Engine* pInstance;
        sf::RenderWindow app;
        std::string oTypeNames[5] = {"WorldStatic", "WorldDynamic", "Pawn", "Projectile", "Trap"};
        sf::View vista;
};



/***********************
 * 
 * CLASS: SPRITE
 * 
 * **********************/
// Super Sprite (interface class)
class SSprite
{
    public:
        SSprite(string TexturePath);
        SSprite();
        ~SSprite();
        void setRotation(double angle);
        void setPosition(double x, double y);
        // Returns a pointer to the SFML sprite
        sf::Sprite getSprite(){ return sfsprite; }
        // Returns a ref to the SFML sprite
        sf::Sprite &getSpriteR(){ return sfsprite; }
        sf::Vector2f Draw();
        sf::Vector2f Draw(sf::Vector2f location, sf::Vector2f location_prev, double percent);
        void setOrigin(double x, double y);
        void setTextureRect(double x, double y, double w, double h);
        void setTextureRect(sf::IntRect rect);
        void setScale(double x, double y);
        sf::FloatRect getGlobalBounds();
        sf::FloatRect getBounds();
        sf::FloatRect setBounds(float newScale);
    protected:
        sf::Texture texture;
        sf::Sprite sfsprite;
    private:
        Engine *eng;
        sf::FloatRect GlobalBounds;
        std::string TextPath; // Used for debug, to check whther we are loading a specific texture file

};



/***********************
 * 
 * CLASS: ANIMATION
 * 
 * **********************/
// Bsed on source: https://github.com/SFML/SFML/wiki/Easy-Animations-With-Spritesheets
class Animation {
    std::vector<AnimFrame> frames;
    double totalLength;
    int progress;
    sf::Sprite &target;
    int duration;
    int currentFrame;

    public:
        Animation(sf::Sprite &target, int length);
        Animation(sf::Sprite &target, int length, bool looping);
        virtual ~Animation();
        void Reset();
        void addFrame(AnimFrame&& frame); // TODO: Could forget about this if we add a standard size for the rect in the constructor, and a default rate.
        void update(double elapsed); 
        double getLength() const { return totalLength; }
    private:
        bool loop = false;
};



/***********************
 * 
 * CLASS: CASCADE. Very Basic particle system
 * This class spawns a animated ssprite with some specific parameters.
 * Does not have movement capabilities.
 * Determined lifespan since creation.
 * 
 * **********************/
class Cascade : public SSprite {
    public:
        Cascade();
        
        // Total lifetime of the emitter
        void SetLifetime(int time) { Lifetime = time; };
        
        // By default = true. Sets if the particle should loop infinite time
        void SetAuto(bool Auto) { AutoDestroy = Auto; };
        virtual ~Cascade();
    protected:
        SSprite Sprite;
        sf::Clock Remaining;
    private:
        bool AutoDestroy;
        int Lifetime;
};



#endif 