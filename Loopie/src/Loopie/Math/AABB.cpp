#include "AABB.h"
#include "Loopie/Math/OBB.h"

namespace Loopie {
    void AABB::SetNegativeInfinity() {
        MinPoint = vec3(std::numeric_limits<float>::max());
        MaxPoint = vec3(std::numeric_limits<float>::lowest());
    }

    void AABB::Enclose(const AABB& other) {
        MinPoint = min(MinPoint, other.MinPoint);
        MaxPoint = max(MaxPoint, other.MaxPoint);
    }

    void AABB::Enclose(const OBB& other) {
        auto corners = other.GetCorners();
        for (const auto& corner : corners) {
            Enclose(corner);
        }
    }

    void AABB::Enclose(const vec3& point) {
        MinPoint = min(MinPoint, point);
        MaxPoint = max(MaxPoint, point);
    }

    bool AABB::Intersects(const AABB& other) const {
        if (MaxPoint.x < other.MinPoint.x || MinPoint.x > other.MaxPoint.x) 
            return false;
        if (MaxPoint.y < other.MinPoint.y || MinPoint.y > other.MaxPoint.y) 
            return false;
        if (MaxPoint.z < other.MinPoint.z || MinPoint.z > other.MaxPoint.z) 
            return false;

        return true;
    }

    vec3 AABB::GetCenter() const {
        return (MinPoint + MaxPoint) * 0.5f;
    }

    vec3 AABB::GetExtents() const {
        return (MaxPoint - MinPoint) * 0.5f;
    }

    vec3 AABB::GetSize() const {
        return MaxPoint - MinPoint;
    }

    bool AABB::Contains(const vec3& point) const {
        bool insideX = point.x >= MinPoint.x && point.x <= MaxPoint.x;
        bool insideY = point.y >= MinPoint.y && point.y <= MaxPoint.y;
        bool insideZ = point.z >= MinPoint.z && point.z <= MaxPoint.z;

        return insideX && insideY && insideZ;
    }

    float AABB::GetVolume() const {
        vec3 size = GetSize();
        return size.x * size.y * size.z;
    }
    OBB AABB::ToOBB() const
    {
        OBB obb;

        obb.Center = GetCenter();
        obb.Extents = GetExtents();

        obb.Axes[0] = vec3(1.0f, 0.0f, 0.0f);
        obb.Axes[1] = vec3(0.0f, 1.0f, 0.0f);  
        obb.Axes[2] = vec3(0.0f, 0.0f, 1.0f);

        return obb;
    }
    AABB AABB::Transform(const matrix4& localToWorld) const
    {
        vec3 localMin = MinPoint;
        vec3 localMax = MaxPoint;

        vec3 basisX(localToWorld[0][0], localToWorld[0][1], localToWorld[0][2]);
        vec3 basisY(localToWorld[1][0], localToWorld[1][1], localToWorld[1][2]);
        vec3 basisZ(localToWorld[2][0], localToWorld[2][1], localToWorld[2][2]);

        vec3 translation(localToWorld[3][0], localToWorld[3][1], localToWorld[3][2]);

        vec3 xa = basisX * localMin.x;
        vec3 xb = basisX * localMax.x;
        vec3 ya = basisY * localMin.y;
        vec3 yb = basisY * localMax.y;
        vec3 za = basisZ * localMin.z;
        vec3 zb = basisZ * localMax.z;

        vec3 worldMin = translation + min(xa, xb) + min(ya, yb) + min(za, zb);
        vec3 worldMax = translation + max(xa, xb) + max(ya, yb) + max(za, zb);

        AABB worldAABB;
        worldAABB.MinPoint = worldMin;
        worldAABB.MaxPoint = worldMax;
        return worldAABB;
    }
}