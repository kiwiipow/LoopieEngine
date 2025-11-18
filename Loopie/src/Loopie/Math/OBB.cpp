#include "OBB.h"
#include "Loopie/Math/AABB.h"

namespace Loopie {
	OBB OBB::Transform(const matrix4& transform) const
	{
        OBB result;

        result.center = vec3(transform * vec4(center, 1.0f));

        matrix3 rotationMatrix = matrix3(transform);
        for (int i = 0; i < 3; i++) {
            result.axes[i] = normalize(rotationMatrix * axes[i]);
        }

        vec3 scale(length(vec3(transform[0])), length(vec3(transform[1])), length(vec3(transform[2])));

        result.extents = extents * scale;
        result.cornersDirty = true;
        return result;
	}

	const std::array<vec3, 8>& OBB::GetCorners() const
	{
        if (cornersDirty) {
            vec3 xAxis = axes[0] * extents.x;
            vec3 yAxis = axes[1] * extents.y;
            vec3 zAxis = axes[2] * extents.z;

            cachedCorners[0] = center - xAxis - yAxis - zAxis;
            cachedCorners[1] = center + xAxis - yAxis - zAxis;
            cachedCorners[2] = center + xAxis + yAxis - zAxis;
            cachedCorners[3] = center - xAxis + yAxis - zAxis;
            cachedCorners[4] = center - xAxis - yAxis + zAxis;
            cachedCorners[5] = center + xAxis - yAxis + zAxis;
            cachedCorners[6] = center + xAxis + yAxis + zAxis;
            cachedCorners[7] = center - xAxis + yAxis + zAxis;

            cornersDirty = false;
        }
        return cachedCorners;
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
        vec3 localPoint = point - center;

        for (int i = 0; i < 3; i++) {
            float projection = dot(localPoint, axes[i]);
            if (abs(projection) > extents[i]) {
                return false;
            }
        }
        return true;
    }
}
