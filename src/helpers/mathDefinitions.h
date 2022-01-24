#ifndef O2DT_MATH_DEFINITIONS
#define O2DT_MATH_DEFINITIONS

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
    };
}

#endif