#pragma once
#include <cmath>


namespace ConsoleXenonShooter
{
    struct Vector2D
    {
        double x{0.0};
        double y{0.0};
    };
    
    
    
    
    //Operation OVerloading (Exercise 1)
    
    Vector2D& operator+=(Vector2D other)
    {
        return other;
    }
    
    Vector2D operator+(Vector2D a, Vector2D b)
    {
        return a + b;
    }
    
    Vector2D operator-(Vector2D a, Vector2D b)
    {
        return a-b;
    }
    
    Vector2D operator*(Vector2D a, Vector2D b)
    {
        return a*b;
    }
    
    bool operator==(Vector2D a, Vector2D b)
    {
        return a.x == b.x && a.y == b.y;
    }
    
    bool operator!=(Vector2D a, Vector2D b)
    {
        return a.x != b.x || a.y != b.y;
    }
    
    
    double lenght(Vector2D vector)
    {
        return sqrt(vector.x * vector.x + vector.y * vector.y); //VEctor lenght is defined as the sqrt of the sum of squares of it's "dimentions" (I.e: v2D -> Sqrt (a^2+b^2), v3D -> (sqrt(a^2+b^2+c^2), etc...))
    }
}
