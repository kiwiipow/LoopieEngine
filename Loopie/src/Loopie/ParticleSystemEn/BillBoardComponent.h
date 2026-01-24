#pragma once
#include "Loopie/Math/MathTypes.h"
#include "Loopie/Math/AABB.h"
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
		
		private:  //ALL CODE FROM TUTORIAL USING EULER ANGLES
		/*	BillboardType Btype;
			vec3 axisLimits;
			AABB Bbox;*/

			BillboardType Btype;
			vec3 m_position;
			matrix4 m_transform;

		public:
			Billboard(vec3 pos, BillboardType t);
			matrix4  UpdateCalc(vec3 cameraPos);
			/*Billboard(BillboardType t);*/

			//vec3 CalcVecOriention(const Camera& camera, const vec3& particleWorldPos, vec2& billboardSize, vec2& vertex);
			//void DrawDebug();

			//getters/setters
			BillboardType GetType()const;
			void SetType(BillboardType t);
			/*AABB* GetAABB();*/
			
	};
}