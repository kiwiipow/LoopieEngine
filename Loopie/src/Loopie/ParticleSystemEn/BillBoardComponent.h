#pragma once
#include "Loopie/Math/MathTypes.h"

namespace Loopie
{
	class Camera;
	enum BillboardType
	{   CAMERA_FACING, 
		AXIS_ALIGNED, 
		SCREEN_ALIGNED
	};
	class Billboard //determines correct particle orientation vectors given a camera. Does not Update particles or itself. just calculates vector math
	{
		private:
			BillboardType Btype;
			vec3 axisLimits;
		public:
			Billboard();
			Billboard(BillboardType t);

			void CalcVecOriention(const Camera &camera, const vec3 &worldPos, vec3 normal);

			//getters/setters
			BillboardType GetType()const;
			void SetType(BillboardType t);
	};
}