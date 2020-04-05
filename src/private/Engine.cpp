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
}

SSprite::SSprite(){
    eng = Engine::Instance();
    std::cout << "SPRITE CREATED -------------" << std::endl;
}

/// Draw with interpolation
sf::Vector2f SSprite::Draw(sf::Vector2f location, sf::Vector2f location_prev, double percent){
    float cX = location.x; // Current X
    float oX = location_prev.x; // Old X

    float cY = location.y; // Current Y
    float oY = location_prev.y; // Old Y

    float x = (cX-oX) * percent + oX;
    float y = (cY-oY) * percent + oY;

    this->setPosition(x,y);
    eng->getApp().draw(sfsprite);

    return sf::Vector2f(x,y);
}


/*/////////////////////////////////////////////////////////
\brief set the position of the object

This function completely overwrites the previous position.
See the move function to apply an offset based on the previous position instead.
The default position of a transformable object is (0, 0).

\param x X coordinate of the new position
\param y Y coordinate of the new position

\see move, getPosition

/////////////////////////////////////////////////////////*/
void SSprite::setPosition(double x, double y){
    sfsprite.setPosition(x, y);
}


/*/////////////////////////////////////////////////////////
\brief set the orientation of the object

This function completely overwrites the previous rotation.
See the rotate function to add an angle based on the previous rotation instead.
The default rotation of a transformable object is 0.

\param angle New rotation, in degrees

\see rotate, getRotation

/////////////////////////////////////////////////////////*/
void SSprite::setRotation(double angle){
    sfsprite.setRotation(angle);
}

/*/////////////////////////////////////////////////////////
\brief set the local origin of the object

The origin of an object defines the center point for
all transformations (position, scale, rotation).
The coordinates of this point must be relative to the
top-left corner of the object, and ignore all
transformations (position, scale, rotation).
The default origin of a transformable object is (0, 0).

\param x X coordinate of the new origin
\param y Y coordinate of the new origin

\see getOrigin

/////////////////////////////////////////////////////////*/
void SSprite::setOrigin(double x, double y){
    sfsprite.setOrigin(x, y);
}

/*/////////////////////////////////////////////////////////
\brief Set the sub-rectangle of the texture that the sprite will display

The texture rect is useful when you don't want to display
the whole texture, but rather a part of it.
By default, the texture rect covers the entire texture.

\param x, y, width, height
\

\see getTextureRect, setTexture

/////////////////////////////////////////////////////////*/
void SSprite::setTextureRect(double x, double y, double w, double h){
    sfsprite.setTextureRect(sf::IntRect(x, y, w, h));
}

/*/////////////////////////////////////////////////////////
\brief Set the sub-rectangle of the texture that the sprite will display

The texture rect is useful when you don't want to display
the whole texture, but rather a part of it.
By default, the texture rect covers the entire texture.

\param Rect rectangle to crop the texture

\see getTextureRect, setTexture

/////////////////////////////////////////////////////////*/
void SSprite::setTextureRect(sf::IntRect rect){
    sfsprite.setTextureRect(rect);
}

/*/////////////////////////////////////////////////////////
\brief set the scale factors of the object

This function completely overwrites the previous scale.
See the scale function to add a factor based on the previous scale instead.
The default scale of a transformable object is (1, 1).

\param factorX New horizontal scale factor
\param factorY New vertical scale factor

\see scale, getScale

/////////////////////////////////////////////////////////*/
void SSprite::setScale(double x, double y){
    sfsprite.setScale(x, y);
}

SSprite::~SSprite(){
 
}





/***********************
 * 
 * CLASS: ANIMATION
 * 
 * **********************/

Animation::Animation(sf::Sprite &target) : target(target) { 
    progress = totalLength = 0.0;
}
Animation::Animation(sf::Sprite &target, bool looping) : target(target) { 
    progress = totalLength = 0.0;
    loop = looping;
}
Animation::~Animation(){

}

/*/////////////////////////////////////////////////////////
\brief set a new frame to the animation array

\param frame FRAME struct to add

/////////////////////////////////////////////////////////*/
void Animation::addFrame(AnimFrame&& frame) {
    totalLength += frame.duration; 
    frames.push_back(std::move(frame)); 
}
void Animation::update(double elapsed) {
    progress += elapsed;
    double p = progress;
    for(size_t i = 0; i < frames.size(); i++) {
        p -= frames[i].duration;  

        // if we have progressed OR if we're on the last frame, apply and stop.
        if(p <= 0.0 || &(frames[i]) == &frames.back()){
            //progress = 0.0;
            target.setTextureRect(frames[i].rect);
            if(loop && &(frames[i]) == &frames.back()){
                progress = 0.0;
            }
            break; // we found our frame
        }

    }
}