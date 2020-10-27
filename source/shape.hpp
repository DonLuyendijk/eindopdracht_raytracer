#include "Material.hpp"
#include "Ray.hpp"

class Shape {
    public:
        Material material;
        virtual bool intersect_ray(Ray ray, Vec3d &normal, double &hit_angle) = 0;
        Shape(Material material);
        Shape();
        virtual ~Shape();
};