#pragma once
#include "Loopie/Math/MathTypes.h"
#include "Loopie/Math/AABB.h"
#include "Loopie/Components/Camera.h"
namespace Loopie
{
	class Camera;
	enum BillboardType
	{   CAMERA_FACING, 
		AXIS_ALIGNED, 
		SCREEN_ALIGNED
	};
	class Billboard //determines correct particle orientation vectors given a camera. 
	{               //Does not Update particles or itself.just calculates vector math
		
		private:
			BillboardType Btype;
			vec3 axisLimits;
			AABB Bbox;

		public:
			Billboard();
			Billboard(BillboardType t);

			vec3 CalcVecOriention(const Camera& camera, const vec3& particleWorldPos, vec2& billboardSize, vec2& vertex);
			void DrawDebug();

			//getters/setters
			BillboardType GetType()const;
			void SetType(BillboardType t);
			AABB* GetAABB();
			
	};
}