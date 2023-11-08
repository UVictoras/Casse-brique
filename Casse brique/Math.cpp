#include "Math.h"
#include <cmath>
#include "GameObject.h"

void Math::Normalize(float* fX, float* fY)
{
	*fX /= sqrtf((*fX * *fX + *fY * *fY));
	*fY /= sqrtf((*fX * *fX + *fY * *fY));
}

float Math::Rotate(GameObject* gGameObject, float vLocalPositionX, float vLocalPositionY)
{
	return -atan2(vLocalPositionX - gGameObject->m_fX, vLocalPositionY - gGameObject->m_fY) * 180 / 3.14159;
}