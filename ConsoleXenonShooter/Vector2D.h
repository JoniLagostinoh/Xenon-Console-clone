#pragma once
#include <cmath>


namespace ConsoleXenonShooter
{
    struct Vector2D
    {
        double x{0.0};
        double y{0.0};
    };
    
    
    
    
    //Operation Overloading (Exercise 1)
    
    inline Vector2D operator+=(Vector2D& valueA, Vector2D valueB)
    {
        
        valueA.x += valueB.x;
        valueA.y += valueB.y;
        
        return valueA;
    }
    
    
   inline  Vector2D operator+(Vector2D a, Vector2D b)
    {
        return Vector2D{a.x + b.x,   a.y + b.y};
    }
    
   inline Vector2D operator-(Vector2D a, Vector2D b)
    {
        return Vector2D{a.x - b.x,   a.y - b.y} ;
    }
    
   inline Vector2D operator*(Vector2D a, Vector2D b)
    {
        return Vector2D{a.x * b.x,   a.y * b.y};
    }
    
    inline Vector2D operator*(Vector2D a, double b)
    {
        return Vector2D{a.x * b, a.y * b};
    }
    
    
    
   inline bool operator==(Vector2D a, Vector2D b)
    {
        return a.x == b.x && a.y == b.y;
    }
    
   inline bool operator!=(Vector2D a, Vector2D b)
    {
        return !(a == b);
    }
    
    
  inline  double lenght(Vector2D vector)
    {
        return std::sqrt(vector.x * vector.x + vector.y * vector.y); //VEctor lenght is defined as the sqrt of the sum of squares of it's "dimentions" (I.e: v2D -> Sqrt (a^2+b^2), v3D -> (sqrt(a^2+b^2+c^2), etc...))
    }
}
