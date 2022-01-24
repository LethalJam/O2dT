#include "GameLoop.h"
#include "../objects/PolygonGameObject.h"
#include "../objects/CircleGameObject.h"
#include <box2d/b2_world.h>
#include <box2d/b2_body.h>
#include <box2d/b2_polygon_shape.h>
#include <box2d/b2_fixture.h>

namespace o2dt
{

    GameLoop::GameLoop()
    {
        window = std::make_unique<sf::RenderWindow>(sf::VideoMode(defaultSize.x, defaultSize.y), title);
        resourceManager = std::make_unique<o2dt::ResourceManager>();
        gameWorld = std::make_unique<o2dt::GameWorld>(sf::Vector2f(0.0f, 100.0f));
    }

    GameLoop::~GameLoop()
    {
    }

    void GameLoop::start()
    {
        sf::Texture zoggs = resourceManager->getTexture("Zoggs.png");
        sf::Texture paprika = resourceManager->getTexture("Paprika.png");
        sf::Texture invis = resourceManager->getTexture("invis.png");
        std::unique_ptr<o2dt::PolygonGameObject> plane = std::make_unique<o2dt::PolygonGameObject>(invis, gameWorld->createBody(b2BodyType::b2_staticBody), 500.0f, 10.0f);
        plane->setPositionAndAngle(b2Vec2(window->getSize().x / 2, 700.0f), 0.5f);

        gameWorld->transferGameObject(std::make_unique<PolygonGameObject>(zoggs, gameWorld->createBodyAt(b2BodyType::b2_dynamicBody, b2Vec2(0.0f, 0.0f))));
        gameWorld->transferGameObject(std::make_unique<CircleGameObject>(paprika, gameWorld->createBodyAt(b2BodyType::b2_dynamicBody, b2Vec2(window->getSize().x / 2, 0.0f))));
        gameWorld->transferGameObject(std::move(plane));

        gameWorld->start();
        // run the program as long as the window is open
        while (window->isOpen())
        {
            // check all the window's events that were triggered since the last iteration of the loop
            sf::Event event;
            while (window->pollEvent(event))
            {
                // "close requested" event: we close the window
                if (event.type == sf::Event::Closed)
                    window->close();
            }

            gameWorld->tick();
            // clear the window with black color
            window->clear(sf::Color::Black);
            gameWorld->draw(*window.get(), true);

            // end the current frame
            window->display();
        }
    }
}