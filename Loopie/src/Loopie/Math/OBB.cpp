#include "OBB.h"
#include "Loopie/Math/AABB.h"

namespace Loopie {
	void OBB::ApplyTransform(const matrix4& transform)
    {
        Center = vec3(transform * vec4(Center, 1.0f));

        matrix3 rotationMatrix = matrix3(transform);
        for (int i = 0; i < 3; i++)
            Axes[i] = normalize(rotationMatrix * Axes[i]);

        vec3 scale(length(vec3(transform[0])), length(vec3(transform[1])), length(vec3(transform[2])));
        Extents *= scale;

        SetCornersDirty();
    }

    AABB OBB::ToAABB() const {
        AABB aabb;
        aabb.SetNegativeInfinity();

        auto corners = GetCorners();
        for (const auto& corner : corners) {
            aabb.Enclose(corner);
        }

        return aabb;
    }

    bool OBB::Contains(const vec3& point) const {
        vec3 localPoint = point - Center;

        for (int i = 0; i < 3; i++) {
            float projection = dot(localPoint, Axes[i]);
            if (abs(projection) > Extents[i]) {
                return false;
            }
        }
        return true;
    }

    const std::array<vec3, 8>& OBB::GetCorners() const
    {
        if (_cornersDirty) {
            vec3 xAxis = Axes[0] * Extents.x;
            vec3 yAxis = Axes[1] * Extents.y;
            vec3 zAxis = Axes[2] * Extents.z;

            _cachedCorners[0] = Center - xAxis - yAxis - zAxis;
            _cachedCorners[1] = Center + xAxis - yAxis - zAxis;
            _cachedCorners[2] = Center + xAxis + yAxis - zAxis;
            _cachedCorners[3] = Center - xAxis + yAxis - zAxis;
            _cachedCorners[4] = Center - xAxis - yAxis + zAxis;
            _cachedCorners[5] = Center + xAxis - yAxis + zAxis;
            _cachedCorners[6] = Center + xAxis + yAxis + zAxis;
            _cachedCorners[7] = Center - xAxis + yAxis + zAxis;

            _cornersDirty = false;
        }
        return _cachedCorners;
    }
}
