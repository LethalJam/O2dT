#include "GameWorld.h"
#include "../helpers/mathDefinitions.h"

namespace o2dt
{
    GameWorld::GameWorld(sf::Vector2f gravity, o2dt::InputManager &inputManager)
        : inputManager(inputManager)
    {
        this->gravity = b2Vec2(gravity.x, gravity.y);
        worldSimulation = std::make_unique<b2World>(this->gravity);
    }
    GameWorld::~GameWorld()
    {
    }

    void GameWorld::start()
    {
        deltaClock.restart();
    }
    void GameWorld::tick()
    {
        player->updateInput(inputManager.getInputData(InputContext::IN_GAME));
        if (deltaClock.getElapsedTime().asSeconds() >= step)
        {
            worldSimulation->Step(step, velocityIterations, positionIterations);
            deltaClock.restart();
        }
    }

    b2Body *GameWorld::createBody(b2BodyDef &bodyDef)
    {
        return worldSimulation->CreateBody(&bodyDef);
    }
    b2Body *GameWorld::createBody(b2BodyType bodyType)
    {
        bodyMold.type = bodyType;
        bodyMold.position.Set(0.0f, 0.0f);
        bodyMold.linearDamping = globalFloorDamping;
        return worldSimulation->CreateBody(&bodyMold);
    }
    b2Body *GameWorld::createBodyAt(b2BodyType bodyType, b2Vec2 spawnPoint)
    {
        bodyMold.type = bodyType;
        bodyMold.position = spawnPoint;
        bodyMold.linearDamping = globalFloorDamping;
        return worldSimulation->CreateBody(&bodyMold);
    }

    void GameWorld::destroyBody(b2Body *body)
    {
        worldSimulation->DestroyBody(body);
    }

    // Transfers the ownership of the data to GameWorld instance.
    void GameWorld::transferGameObject(std::unique_ptr<GameObject> &&gameObject)
    {
        gameObjects.push_back(std::move(gameObject));
    }
    void GameWorld::setPlayer(std::unique_ptr<PlayerObject> &&playerObject)
    {
        player = std::move(playerObject);
        playerView = sf::View(player->getSprite().getPosition(), sf::Vector2f(1600, 900));
        playerView.zoom(1.5f);
    }

    void GameWorld::draw(sf::RenderWindow &window, bool debug)
    {

        sf::Vector2f source = playerView.getCenter();
        sf::Vector2f target = player->getSprite().getPosition();

        sf::Vector2f lerpedPos = MathDefinitions::lerp(source, target, lerpClock.getElapsedTime().asSeconds());
        playerView.setCenter(lerpedPos);
        if (target != source)
        {
            lerpClock.restart();
        }

        window.setView(playerView);

        for (int i = 0; i < gameObjects.size(); i++)
        {
            if (debug)
            {
                window.draw(gameObjects.at(i)->getBodyShape());
            }

            window.draw(gameObjects.at(i)->getSprite());
        }

        window.draw(player->getSprite());
    }
}