#pragma once
#include "Loopie/Math/MathTypes.h"

namespace Loopie{
    struct OBB;

    struct AABB {
        vec3 MinPoint;
        vec3 MaxPoint;

        void SetNegativeInfinity();
        void Enclose(const AABB& other);
        void Enclose(const OBB& other);
        void Enclose(const vec3& point);
        bool Intersects(const AABB& other) const;

        vec3 GetCenter() const;
        vec3 GetExtents() const;
        vec3 GetSize() const;
        bool Contains(const vec3& point) const;
        float GetVolume() const;

        OBB ToOBB() const;
        AABB Transform(const matrix4& localToWorld) const;
    };
}
