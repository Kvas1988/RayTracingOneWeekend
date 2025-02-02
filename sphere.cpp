#include "sphere.h"

bool sphere::hit(const ray& r, double tmin, double tmax, hit_record& rec) const {
    vec3 oc = r.origin() - center;
    auto a = r.direction().length_squared();
    auto half_b = dot(oc, r.direction()); //auto b = 2.0 * dot(oc, r.direction());
    auto c = oc.length_squared() - radius*radius; // c = dot(oc, oc) - radius*radius;
    auto discriminant = half_b*half_b - a*c;// discriminant = b*b-4*a*c;
    
    if (discriminant > 0) {
        auto root = sqrt(discriminant);
        
        auto temp = (-half_b - root) / a;
        if (temp < tmax && temp > tmin) {
            rec.t = temp;
            rec.p = r.at(rec.t); // ??
            //rec.normal = (rec.p - center) / radius;
            vec3 outward_normal = (rec.p - center) / radius;
            rec.set_face_normal(r, outward_normal);
            rec.mat_ptr = mat_ptr;
            return true;
        }
        
        temp = (-half_b + root) / a;
        if (temp < tmax && temp > tmin) {
            rec.t = temp;
            rec.p = r.at(rec.t); // ??
            //rec.normal = (rec.p - center) / radius;
            vec3 outward_normal = (rec.p - center) / radius;
            rec.set_face_normal(r, outward_normal);
            rec.mat_ptr = mat_ptr;
            return true;
        }
    }
    
    return false;
}
