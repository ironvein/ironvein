#ifndef IRONVEIN_UTIL_GENERATION
#define IRONVEIN_UTIL_GENERATION

namespace IronVein
{
	namespace Util
	{
		namespace Generation
		{
			float Lerp(float a, float b, float x);

			float GetRand2D(int x, int y);
			float GetRand3D(int x, int y, int z);

			float Noise2D(float x, float y);
			float Noise3D(float x, float y, float z);

			float ValueNoise2D(float x, float y, float amplitude, float wavelength, int octaves = 3, float factor = 0.5f);
			float ValueNoise2D(float x, float y, float z, float amplitude, float wavelength, int octaves = 3, float factor = 0.5f);
		}
	}
}

#endif
