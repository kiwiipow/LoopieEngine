#pragma once
#include "Loopie/Math/MathTypes.h"

#include <array>


namespace Loopie {

    struct AABB;

    struct OBB {
        vec3 Center;
        vec3 Extents;
        vec3 Axes[3];

        mutable std::array<vec3, 8> _cachedCorners;
        mutable bool _cornersDirty = true;

        void ApplyTransform(const matrix4& transform);

        AABB ToAABB() const;
        bool Contains(const vec3& point) const;

        const std::array<vec3, 8>& GetCorners() const;
        void SetCornersDirty() { _cornersDirty = true; }
    };
}
