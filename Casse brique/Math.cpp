#include "Math.h"
#include <cmath>

void Math::Normalize(float* fX, float* fY)
{
	*fX /= sqrtf((*fX * *fX + *fY * *fY));
	*fY /= sqrtf((*fX * *fX + *fY * *fY));
}