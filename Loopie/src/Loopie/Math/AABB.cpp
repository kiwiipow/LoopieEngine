#include "AABB.h"
#include "Loopie/Math/OBB.h"

namespace Loopie {
    void AABB::SetNegativeInfinity() {
        minPoint = vec3(std::numeric_limits<float>::max());
        maxPoint = vec3(std::numeric_limits<float>::lowest());
    }

    void AABB::Enclose(const AABB& other) {
        minPoint = min(minPoint, other.minPoint);
        maxPoint = max(maxPoint, other.maxPoint);
    }

    void AABB::Enclose(const OBB& other) {
        auto corners = other.GetCorners();
        for (const auto& corner : corners) {
            Enclose(corner);
        }
    }

    void AABB::Enclose(const vec3& point) {
        minPoint = min(minPoint, point);
        maxPoint = max(maxPoint, point);
    }

    bool AABB::Intersects(const AABB& other) const {
        if (maxPoint.x < other.minPoint.x || minPoint.x > other.maxPoint.x) 
            return false;
        if (maxPoint.y < other.minPoint.y || minPoint.y > other.maxPoint.y) 
            return false;
        if (maxPoint.z < other.minPoint.z || minPoint.z > other.maxPoint.z) 
            return false;

        return true;
    }

    vec3 AABB::GetCenter() const {
        return (minPoint + maxPoint) * 0.5f;
    }

    vec3 AABB::GetExtents() const {
        return (maxPoint - minPoint) * 0.5f;
    }

    vec3 AABB::GetSize() const {
        return maxPoint - minPoint;
    }

    bool AABB::Contains(const vec3& point) const {
        bool insideX = point.x >= minPoint.x && point.x <= maxPoint.x;
        bool insideY = point.y >= minPoint.y && point.y <= maxPoint.y;
        bool insideZ = point.z >= minPoint.z && point.z <= maxPoint.z;

        return insideX && insideY && insideZ;
    }

    float AABB::GetVolume() const {
        vec3 size = GetSize();
        return size.x * size.y * size.z;
    }
    OBB AABB::ToOBB() const
    {
        OBB obb;

        obb.center = GetCenter();
        obb.extents = GetExtents();

        obb.axes[0] = vec3(1.0f, 0.0f, 0.0f);
        obb.axes[1] = vec3(0.0f, 1.0f, 0.0f);  
        obb.axes[2] = vec3(0.0f, 0.0f, 1.0f);

        return obb;
    }
}