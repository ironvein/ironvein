// local
#include "util/generation/noise.h"

// standard
#include "cmath"

namespace IronVein
{
	namespace Util
	{
		namespace Generation
		{
			float Lerp(float a, float b, float x)
			{
				return a + (b - a) * x;
			}

			float GetRand2D(int x, int y, int seed)
			{
				return ((((x * 37 - 3472 + seed) ^ (y * 73 - 2473 - seed)) << 3 + (seed ^ x ^ y)) % 20000 - 10000) / 10000.0f;
			}

			float GetRand3D(int x, int y, int z, int seed)
			{
				return ((((x * 37 - 3472 + seed) ^ (y * 73 - 2473 - seed) ^ (z * 53 - 1933 + seed)) << 3 + (seed ^ x ^ y ^ z)) % 20000 - 10000) / 10000.0f;
			}

			float Noise2D(float x, float y, int seed)
			{
				float xoff = fmod(x, 1.0);
				float yoff = fmod(y, 1.0);

				float v0_00 = GetRand2D((int)x, (int)y, seed);
				float v0_01 = GetRand2D((int)x, (int)y + 1, seed);
				float v0_10 = GetRand2D((int)x + 1, (int)y, seed);
				float v0_11 = GetRand2D((int)x + 1, (int)y + 1, seed);

				float v1_0 = Lerp(v0_00, v0_01, yoff);
				float v1_1 = Lerp(v0_10, v0_11, yoff);

				return Lerp(v1_0, v1_1, xoff);
			}

			float Noise3D(float x, float y, float z, int seed)
			{
				x += 3473.0f;
				y += 3789.0f;
				z += 1737.0f;

				float xoff = fmod(x, 1.0);
				float yoff = fmod(y, 1.0);
				float zoff = fmod(z, 1.0);

				float v0_000 = GetRand3D((int)x, (int)y, (int)z, seed);
				float v0_001 = GetRand3D((int)x, (int)y, (int)z + 1, seed);
				float v0_010 = GetRand3D((int)x, (int)y + 1, (int)z, seed);
				float v0_011 = GetRand3D((int)x, (int)y + 1, (int)z + 1, seed);

				float v0_100 = GetRand3D((int)x + 1, (int)y, (int)z, seed);
				float v0_101 = GetRand3D((int)x + 1, (int)y, (int)z + 1, seed);
				float v0_110 = GetRand3D((int)x + 1, (int)y + 1, (int)z, seed);
				float v0_111 = GetRand3D((int)x + 1, (int)y + 1, (int)z + 1, seed);

				float v1_00 = Lerp(v0_000, v0_001, zoff);
				float v1_01 = Lerp(v0_010, v0_011, zoff);
				float v1_10 = Lerp(v0_100, v0_101, zoff);
				float v1_11 = Lerp(v0_110, v0_111, zoff);

				float v2_0 = Lerp(v1_00, v1_01, yoff);
				float v2_1 = Lerp(v1_10, v1_11, yoff);

				return Lerp(v2_0, v2_1, xoff);
			}

			float ValueNoise2D(float x, float y, float amplitude, float wavelength, int octaves, float factor, int seed)
			{
				float sum = 0.0f;
				float range_adjust = 0.0f;
				float temp_amp = 1.0f;

				for(int i = 0; i < octaves; i ++)
				{
					sum += temp_amp * Noise2D(x / wavelength, y / wavelength, seed);
					wavelength *= factor;
					temp_amp *= factor;
					range_adjust += temp_amp;
				}

				return amplitude * (sum / range_adjust);
			}

			float ValueNoise3D(float x, float y, float z, float amplitude, float wavelength, int octaves, float factor, int seed)
			{
				float sum = 0.0f;
				float range_adjust = 0.0f;
				float temp_amp = 1.0f;

				for(int i = 0; i < octaves; i ++)
				{
					sum += temp_amp * Noise3D(x / wavelength, y / wavelength, z / wavelength, seed);
					wavelength *= factor;
					temp_amp *= factor;
					range_adjust += temp_amp;
				}

				return amplitude * (sum / range_adjust);
			}
		}
	}
}
