#include "../public/Engine.h"

/***********************
 * 
 * CLASS: ENGINE
 * 
 * **********************/

Engine* Engine::pInstance = NULL;
Engine* Engine::Instance() {
    if(pInstance == NULL) { // If not created earlier, create a new instance and return it
        pInstance = new Engine();
    } 
    return pInstance;
}
Engine::Engine()
{
    //gameinstance = game::Instance();
    std::cerr << "Engine loaded()" << std::endl;
}
Engine::~Engine(){

}
sf::RenderWindow &Engine::CreateApp(sf::VideoMode vm, string wn){
    app.create(vm, wn);
    return app;
}








/***********************
 * 
 * CLASS: SPRITE
 * 
 * **********************/
SSprite::SSprite(string path){
    eng = Engine::Instance();
    if (!texture.loadFromFile(path)) {
        std::cerr << "Error cargando la imagen sprites.png" << std::endl;
        exit(0);
    }
    //Create spriteSheet from texture
    sfsprite.setTexture(texture);

    //Set centroid
    sfsprite.setOrigin(75 / 2, 75 / 2);
    //Cut desired area from texture
    sfsprite.setTextureRect(sf::IntRect(3 * 85, 0 * 75, 75, 75));
}
SSprite::SSprite(){
    eng = Engine::Instance();
    std::cout << "SPRITE CREATED -------------" << std::endl;
}

// TODO: Create supercharge for Draw(Actor actor) so we only pass an object
/// Draw with interpolation
void SSprite::Draw(sf::Vector2f location, sf::Vector2f location_prev, double percent){
    float cX = location.x; // Current X
    float oX = location_prev.x; // Old X

    float cY = location.y; // Current Y
    float oY = location_prev.y; // Old Y

    float x = (cX-oX) * percent + oX;
    float y = (cY-oY) * percent + oY;

    this->setPosition(x,y);
    eng->getApp().draw(sfsprite);
}

void SSprite::setPosition(double x, double y){
    sfsprite.setPosition(x, y);
}

void SSprite::setRotation(double angle){
    sfsprite.setRotation(angle);
}

void SSprite::setOrigin(double x, double y){
    sfsprite.setOrigin(x, y);
}
void SSprite::setTextureRect(double xx, double xy, double yx, double yy){
    sfsprite.setTextureRect(sf::IntRect(xx, yx, yx, yy));
}
void SSprite::setScale(double x, double y){
    sfsprite.setScale(x, y);
}

SSprite::~SSprite(){
 
}

