#include "BillBoardComponent.h"
#include "Loopie/Components/Camera.h"

namespace Loopie
{
	
	/*Billboard::Billboard()
	{
		axisLimits = vec3(0,90,0);
	}*/
	/*Billboard::Billboard(BillboardType t)
	{
		Btype = t;
		axisLimits = vec3(0, 90, 0);
	}*/
	Billboard::Billboard(vec3 pos, BillboardType t)
	{
		Btype = t;
		m_position = pos;
		m_transform = matrix4(1.0f);
	}
	matrix4  Billboard::UpdateCalc(Camera* cam)
	{
		//SHOULD ADD SWITCH HERE DEPENDING ON BILLBOARD TYPE

		//https://learnopengl.com/Getting-started/Camera

		//THIS WOULD BE CAMERA ALIGNED 
		vec3 billboardPos = m_position;
		vec3 cameraPos = cam->GetPosition();
		vec3 cameraUp = cam->GetUp();

		matrix4 lookAtMatrix = glm::lookAt(billboardPos, cameraPos, cameraUp);

		m_transform = glm::inverse(lookAtMatrix);
		
		return m_transform;
	}
	//vec3 CalcVecOriention(const Camera& camera, const vec3& particleWorldPos, vec2& billboardSize, vec2& vertex, BillboardType Btype)
	//{
	//	switch (Btype)
	//	{
	//	case Loopie::CAMERA_FACING:
	//		const matrix4& viewMatrix = camera.GetViewMatrix();
	//		vec3 cameraRightWorldspace = vec3(viewMatrix[0][0], viewMatrix[1][0], viewMatrix[2][0]);
	//		vec3 cameraUpWorldspace = vec3(viewMatrix[0][1], viewMatrix[1][1], viewMatrix[2][1]);

	//		vec3 vertexPositionWordspace =
	//			particleWorldPos +
	//			cameraRightWorldspace * vertex.x * billboardSize.x +
	//			cameraUpWorldspace * vertex.y * billboardSize.y;

	//		return vertexPositionWordspace;
	//		break;
	//	case Loopie::AXIS_ALIGNED:
	//		//calculos
	//		break;
	//	case Loopie::SCREEN_ALIGNED:
	//		//calculos
	//		break;
	//	default:
	//		break;
	//	}
	//}

	BillboardType Billboard::GetType()const
	{
		return Btype;
	}
	void Billboard::SetType(BillboardType t)
	{
		Btype = t;
	}
	vec3 Billboard::GetPosition()
	{
		return m_position;
	}
	void Billboard::SetPosition(vec3 pos)
	{
		m_position = pos;
	}
	/*AABB* Billboard::GetAABB()
	{
		return &Bbox;
	}*/
	
}