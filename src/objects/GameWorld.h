#ifndef O2DT_GAME_WORLD
#define O2DT_GAME_WORLD

#include <memory>
#include <vector>
#include <box2d/b2_world.h>
#include <box2d/b2_body.h>
#include <SFML/Graphics.hpp>
#include "GameObject.h"

namespace o2dt
{
    class GameWorld
    {
    public:
        GameWorld(sf::Vector2f gravity);
        ~GameWorld();

        void start(); // To be called right before starting gameloop logic.
        void tick();  // Steps simulation according to lapsed time since last tick.

        b2Body *createBody(b2BodyDef &bodyDef);
        b2Body *createBody(b2BodyType bodyType);
        b2Body *createBodyAt(b2BodyType bodyType, b2Vec2 spawnPoint);
        void destroyBody(b2Body *body);

        void transferGameObject(std::unique_ptr<GameObject> &&gameObject);
        void draw(sf::RenderWindow &window, bool debug);

    private:
        std::unique_ptr<b2World> worldSimulation;
        b2Vec2 gravity;
        b2BodyDef bodyMold;

        // Default recommended iterations
        // Lower for performance, increase for quality
        int32 velocityIterations = 8;
        int32 positionIterations = 3;

        sf::Clock deltaClock;
        sf::Time deltaTime;

        // Object Management
        std::vector<std::unique_ptr<GameObject>> gameObjects;
    };
}

#endif