#include "vec3.h"
#include "rtweekend.h"

inline vec3 vec3::random() { // static ???
    return vec3(random_double(), random_double(), random_double());
}

inline vec3 vec3::random(double min, double max) { // static ???
    return vec3(random_double(min, max), random_double(min, max), random_double(min, max));
}

// vec Utility Functions
/*inline*/ std::ostream& operator<<(std::ostream& out, const vec3& v) {
    return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
}
 
/*inline*/ vec3 operator+ (const vec3& u, const vec3& v) {
    return vec3(u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2]);
}

/*inline*/ vec3 operator- (const vec3& u, const vec3& v) {
    return vec3(u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2]);
}

/*inline*/ vec3 operator* (const vec3& u, const vec3& v) {
    return vec3(u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2]);
}

/*inline*/ vec3 operator* (double t, const vec3& v) {
    return vec3(t * v.e[0], t * v.e[1], t * v.e[2]);
}

/*inline*/ vec3 operator* (const vec3& v, double t) {
    return t * v;
}

/*inline*/ vec3 operator/ (const vec3 v, double t) {
    return (1/t)*v;
}

/*inline*/ double dot(const vec3& u, const vec3& v) {
    return u.e[0]*v.e[0] + u.e[1]*v.e[1] + u.e[2]*v.e[2];
}

/*inline*/ vec3 cross(const vec3 &u, const vec3& v) {
    return vec3(u.e[1]*v.e[2] - u.e[2]*v.e[1],
                u.e[2]*v.e[0] - u.e[0]*v.e[2],
                u.e[0]*v.e[1] - u.e[1]*v.e[0]);
}

/*inline*/ vec3 unit_vector(vec3 v) {
    return v / v.length();
}

vec3 random_in_unit_sphere() {
    while (true) {
        auto p = vec3::random(-1, 1);
        if (p.length_squared() >= 1) continue;
        return p;
    }
}

vec3 random_unit_vector() {
    auto a = random_double(0, 2*pi);
    auto z = random_double(-1, 1);
    auto r = sqrt(1 - z*z);
    return vec3(r*cos(a), r*sin(a), z);
}

vec3 reflect(const vec3& v, const vec3& n) {
    return v - 2*dot(v,n)*n; // *n ???
}
