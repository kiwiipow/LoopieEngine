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
	void Billboard::CalcVecOriention(const Camera& camera, const vec3& worldPos, vec3 normal)
	{
		switch (Btype)
		{
		case Loopie::CAMERA_FACING:
			//calculos
			break;
		case Loopie::AXIS_ALIGNED:
			//calculos
			break;
		case Loopie::SCREEN_ALIGNED:
			//calculos
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
	
}