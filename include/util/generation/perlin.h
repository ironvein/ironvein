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
			
			float Perlin2D(float x, float y, int octaves, float amp, float wavelength, int skip = 1);
			float Perlin3D(float x, float y, float z, int octaves, float amp, float wavelength, int skip = 1);
		}
	}
}

#endif
