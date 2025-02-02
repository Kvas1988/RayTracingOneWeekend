#ifndef VEC3_H // ifndef ???
#define VEC3_H // define ??

#include <cmath>
#include <iostream>
//#include "rtweekend.h"

using std::sqrt;

class vec3 {
public:
    vec3() : e{0,0,0} {}
    vec3(double e0, double e1, double e2) : e{e0, e1, e2} {}
    
    double x() const { return e[0]; }
    double y() const { return e[1]; }
    double z() const { return e[2]; }
    
    vec3 operator-() const {
        return vec3(-e[0], -e[1], -e[2]);
    }
    
    double operator[](int i) const {
        return e[i];
    }
    double& operator[](int i) {
        return e[i];
    }
    
    vec3 operator +=(const vec3& v) {
        e[0] += v.e[0];
        e[1] += v.e[1];
        e[2] += v.e[2];
        return *this; // *this ???
    }
    
    vec3& operator *=(const double t) {
        e[0] *= t;
        e[1] *= t;
        e[2] *= t;
        return *this;
    }
    
    vec3& operator /=(const double t) {
        return *this*=1/t; //blown%))
    }
    
    double length() const {
        return sqrt(length_squared() );
    }
    
    double length_squared() const {
        return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];
    }
    
    /*inline*/ static vec3 random(); // static ???
    
    /*inline*/ static vec3 random(double min, double max);
    
    double e[3];
};

//Type aliases for vec3
using point3 = vec3; // 3D point
using color = vec3; // RGB color

#endif // ???

// vec3 Utility Functions

// inline ??
inline std::ostream& operator<<(std::ostream& out, const vec3& v);
 
/*inline*/ vec3 operator+ (const vec3& u, const vec3& v);

/*inline*/ vec3 operator- (const vec3& u, const vec3& v);

/*inline*/ vec3 operator* (const vec3& u, const vec3& v);

/*inline*/ vec3 operator* (double t, const vec3& v);

/*inline*/ vec3 operator* (const vec3& v, double t);

/*inline*/ vec3 operator/ (const vec3 v, double t);

/*inline*/ double dot(const vec3& u, const vec3& v);

/*inline*/ vec3 cross(const vec3 &u, const vec3& v);

/*inline*/ vec3 unit_vector(vec3 v) ;

vec3 random_in_unit_sphere();

vec3 random_unit_vector();

vec3 reflect(const vec3& v, const vec3& n);

vec3 refract(const vec3& uv, const vec3& n, double etai_over_etat);

vec3 random_in_unit_disk();
