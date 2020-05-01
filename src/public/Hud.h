#pragma once
#ifndef HUD_H
#define HUD_H

#include <iostream>
#include <list>
#include <iterator>
#include <SFML/Graphics.hpp>
#include <algorithm>

#include <Engine.h>
#include <Player.h>
#include <Enemy.h>
#include <Mejora.h>

using namespace std;
using namespace sf;

class Hud
{
    public:
        static Hud* Instance();
        void setMaxHealth(float health);
        void setCurrentHealth(float health);


        void setPlayer(Player* player);
        void addMejora(Mejora mejora);
        void Update();
        void Draw();


    protected:
    private:
        Hud();
        virtual ~Hud();
        static Hud* pInstance;
        Engine* eng;
        Font fontHud;

        //Barra de vida del jugador
        Player* jugador;
        RectangleShape playerHealth;
        float currentHealth;
        float maxHealth;
        float height, width;
        float percent; //Porcentaje vidaActual/vidaTotal
        Color colorHealth100, colorHealthLess50, colorHealthLess25; 

        //Datos de los powerups adquiridos - TO DO: una vez gestionemos powerups
        float separacion = 25.f;
        vector<Mejora*> vMejoras;
        Text txtHealth, txtMovSpeed, txtAttackSpeed, txtAttackMore;
        int vecesMejora1 = 0;
        int vecesMejora2 = 0;
        int vecesMejora3 = 0;
        int vecesMejora4 = 0;
        vector<Sprite*> spritesMejoras;
        vector<Texture> texturasMejoras;

        //Barras de vida de los enemigos
        vector<RectangleShape*> enemyHealthBars;
};

#endif // Hud_H


