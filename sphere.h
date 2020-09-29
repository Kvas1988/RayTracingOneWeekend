#ifndef SPHERE_H
#define SPHERE_H

#include "hittable.h"
#include "vec3.h"

class sphere : public hittable {
public:
    sphere() {}
    sphere(point3 cen, double r) : center(cen), radius(r) {};
    
    virtual bool hit(const ray& r, double tmin,
                     double tmax, hit_record& rec) const override;
    
public:
    point3 center;
    double radius;
};

#endif /* sphere_h */
