#ifndef O2DT_MATH_DEFINITIONS
#define O2DT_MATH_DEFINITIONS

#include <SFML/Graphics.hpp>
#include <math.h>
namespace o2dt
{
    static const float PI = 3.14159265358979323846f;

    class MathDefinitions
    {
    public:
        static float radianToDegree(float radians)
        {
            return radians * (180.0f / PI);
        }

        static sf::Vector2f lerp(sf::Vector2f a, sf::Vector2f b, float f)
        {
            return sf::Vector2f((a.x * (1.0 - f)) + (b.x * f),
                                (a.y * (1.0 - f)) + (b.y * f));
        }

        static float distance(sf::Vector2f a, sf::Vector2f b)
        {
            return std::sqrt(((a.x - b.x) * (a.x - b.x)) +
                             ((a.y - b.y) * (a.y - b.y)));
        }
    };
}

#endif