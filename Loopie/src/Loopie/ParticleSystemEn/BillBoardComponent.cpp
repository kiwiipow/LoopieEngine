#include "BillBoardComponent.h"


namespace Loopie
{
	
	Billboard::Billboard()
	{
		axisLimits = vec3(0,90,0);
	}
	Billboard::Billboard(BillboardType t)
	{
		Btype = t;
		axisLimits = vec3(0, 90, 0);
	}

	vec3 Billboard::CalcVecOriention(const Camera& camera, const vec3& particleWorldPos, vec2& billboardSize, vec2& vertex)
	{
		switch (Btype)
		{
		case Loopie::CAMERA_FACING:
		{

			const matrix4& viewMatrix = camera.GetViewMatrix();
			vec3 cameraRightWorldspace = vec3(viewMatrix[0][0], viewMatrix[1][0], viewMatrix[2][0]);
			vec3 cameraUpWorldspace = vec3(viewMatrix[0][1], viewMatrix[1][1], viewMatrix[2][1]);

			vec3 vertexPositionWordspace =
				particleWorldPos +
				cameraRightWorldspace * vertex.x * billboardSize.x +
				cameraUpWorldspace * vertex.y * billboardSize.y;

			return vertexPositionWordspace;

		}
		break;
		case Loopie::AXIS_ALIGNED:
		{
			//calculos

		}
		break;
		case Loopie::SCREEN_ALIGNED:
		{
			//calculos
		}
		break;
		default:
			break;
		}
	}

	BillboardType Billboard::GetType()const
	{
		return Btype;
	}
	void Billboard::SetType(BillboardType t)
	{
		Btype = t;
	}
	AABB* Billboard::GetAABB()
	{
		return &Bbox;
	}
	
}