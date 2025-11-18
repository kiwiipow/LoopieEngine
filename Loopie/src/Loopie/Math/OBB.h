#include "Loopie/Math/MathTypes.h"

#include <array>


namespace Loopie {

    struct AABB;

    struct OBB {
        vec3 center;
        vec3 extents;
        vec3 axes[3];

        mutable std::array<vec3, 8> cachedCorners;
        mutable bool cornersDirty = true;

        OBB Transform(const matrix4& transform) const;
        const std::array<vec3, 8>& GetCorners() const;

        void MarkCornersDirty() { cornersDirty = true; }

        AABB ToAABB() const;
        bool Contains(const vec3& point) const;
    };
}
