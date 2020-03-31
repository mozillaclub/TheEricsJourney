#include "../public/Tile.h"


Tile::Tile(string nombreSprite, float x, float y, float widthSprite, float heightSprite) : Actor(){ 
    width = widthSprite;
    height = heightSprite;
    texture_file = nombreSprite;


    faction = neutral; //Por ahora pongo neutral pero si fuese danyino deberia ser otro tipo

    setActorLocation(Vector2f(y,x)); //las posiciones en sfml primer y luego x

    PrepareSprite();
}

void Tile::PrepareSprite(){
    // float scale = 0.4;
    //float sizeX = 430.0, sizeY = 519.0;
    float sizeX = width, sizeY = height;
    float offsetX = sizeX / 2.0;
    float offsetY = sizeY / 2.0;

    sprite = new SSprite(texture_file);
    //sprite->setOrigin(offsetX, offsetY);
    //sprite->setTextureRect( 0, 0, sizeX*scale, sizeY*scale );

    //sprite->setScale(scale,scale);
    //sprite->setPosition(getActorLocation().x, getActorLocation().y);
    
    double playrate = 5000.0;
    

    //Rect<int> t = sprite->getSprite().getTextureRect();
    Rect<float> bb = sprite->getSprite().getLocalBounds();
    //bb.left = bb.left-offsetX;
    //bb.top = bb.top-offsetY;

    //setBoundingBox( Rect<float>( getActorLocation().x-offsetX, getActorLocation().y-offsetY, bb.width, bb.height ) ); // make the actor bounds be the same as the sprite used here.

    // animation = new Animation(sprite->getSpriteR());
    // animation->addFrame({sf::IntRect(0,0,sizeX,sizeY), playrate});
    // animation->addFrame({sf::IntRect(430,0,sizeX,sizeY), playrate});
    // animation->addFrame({sf::IntRect(860,0,sizeX,sizeY), playrate});
    // animation->addFrame({sf::IntRect(1290,0,sizeX,sizeY), playrate});
    // animation->addFrame({sf::IntRect(1720,0,sizeX,sizeY), playrate});
    // animation->addFrame({sf::IntRect(2150,0,sizeX,sizeY), playrate});
    // animation->addFrame({sf::IntRect(2580,0,sizeX,sizeY), playrate});
    // animation->addFrame({sf::IntRect(3010,0,sizeX,sizeY), playrate});
    // animation->addFrame({sf::IntRect(3440,0,sizeX,sizeY), playrate});
    // animation->addFrame({sf::IntRect(3870,0,sizeX,sizeY), playrate});
    // animation->addFrame({sf::IntRect(4300,0,sizeX,sizeY), playrate});
    // animation->addFrame({sf::IntRect(4730,0,sizeX,sizeY), playrate});
    // animation->addFrame({sf::IntRect(5160,0,sizeX,sizeY), playrate});
    // animation->addFrame({sf::IntRect(5590,0,sizeX,sizeY), playrate});
    // animation->addFrame({sf::IntRect(6020,0,sizeX,sizeY), playrate});
}


void Tile::Update(float delta){
    std::cout << "Iniciamos UPDATE() de Tile" << std::endl;
}

void Tile::Draw(double percent, double delta){
    //animation->update(delta);
    //Vector2f currentLoc = sprite->Draw(percent, delta); // Location of sprite during interpolation
    Actor::Draw(percent, delta);
}

void Tile::OnActorOverlap(Actor *otherActor){

}






