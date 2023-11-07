#include "Math.h"
#include <cmath>

void Math::Normalize(float* fX, float* fY)
{
	float fTX = *fX;
	float fTY = *fY;
	float fLength = fTX * fTX + fTY * fTY;
	float fMagnitude = sqrtf(fLength);
	*fX = *fX / fMagnitude;
	*fY = *fY / fMagnitude;
}