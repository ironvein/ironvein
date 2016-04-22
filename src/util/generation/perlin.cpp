// local
#include "util/generation/perlin.h"

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

			float GetRand2D(int x, int y)
			{
				return fmod((float)(13217 * cos(fmod(1337 + (y * sin((float)x) + x * sin((float)y) + x - y), 1000.0) * 1373)), 1.0);
			}

			float GetRand3D(int x, int y, int z)
			{
				return fmod((float)(z + 13217 * cos(fmod(1337 + 7489 * sin(z + y) + (y * sin((float)x) + x * sin((float)y) + x - y * z - z), 1000.0) * 1373)), 1.0);
			}

			float Noise2D(float x, float y)
			{
				x += 3473.0f;
				y += 3789.0f;

				float xoff = fmod(x, 1.0);
				float yoff = fmod(y, 1.0);

				float v0_00 = GetRand2D((int)x, (int)y);
				float v0_01 = GetRand2D((int)x, (int)y + 1);
				float v0_10 = GetRand2D((int)x + 1, (int)y);
				float v0_11 = GetRand2D((int)x + 1, (int)y + 1);

				float v1_0 = Lerp(v0_00, v0_01, yoff);
				float v1_1 = Lerp(v0_10, v0_11, yoff);

				return Lerp(v1_0, v1_1, xoff);
			}

			float Perlin2D(float x, float y, int octaves, float amp, float wavelength, int skip)
			{
				//return amp * (noise2d(x / wavelength, y / wavelength) + 1.0f) * 0.5f;
				float namp = 2.0f;
				float net = 0.0f;
				for(int i = 0; i < octaves; i += skip)
				{
					for (int c = 0; c < skip; c ++)
					{
						namp *= 0.5f;
						wavelength *= 0.5f;
					}
					net += namp * (2 * Noise2D(x / wavelength, y / wavelength) - 1.0f);
				}
				return 0.5 * amp * ((net + 1.0f) / 2.0f);
			}

			float Noise3D(float x, float y, float z)
			{
				x += 3473.0f;
				y += 3789.0f;
				z += 1737.0f;

				float xoff = fmod(x, 1.0);
				float yoff = fmod(y, 1.0);
				float zoff = fmod(z, 1.0);

				float v0_000 = GetRand3D((int)x, (int)y, (int)z);
				float v0_001 = GetRand3D((int)x, (int)y, (int)z + 1);
				float v0_010 = GetRand3D((int)x, (int)y + 1, (int)z);
				float v0_011 = GetRand3D((int)x, (int)y + 1, (int)z + 1);

				float v0_100 = GetRand3D((int)x + 1, (int)y, (int)z);
				float v0_101 = GetRand3D((int)x + 1, (int)y, (int)z + 1);
				float v0_110 = GetRand3D((int)x + 1, (int)y + 1, (int)z);
				float v0_111 = GetRand3D((int)x + 1, (int)y + 1, (int)z + 1);

				float v1_00 = Lerp(v0_000, v0_001, zoff);
				float v1_01 = Lerp(v0_010, v0_011, zoff);
				float v1_10 = Lerp(v0_100, v0_101, zoff);
				float v1_11 = Lerp(v0_110, v0_111, zoff);

				float v2_0 = Lerp(v1_00, v1_01, yoff);
				float v2_1 = Lerp(v1_10, v1_11, yoff);

				return Lerp(v2_0, v2_1, xoff);
			}

			float Perlin3D(float x, float y, float z, int octaves, float amp, float wavelength, int skip)
			{
				//return amp * (noise2d(x / wavelength, y / wavelength) + 1.0f) * 0.5f;
				float namp = 2.0f;
				float net = 0.0f;
				float tot = 1.0f;
				for(int i = 0; i < octaves; i += skip)
				{
					for (int c = 0; c < skip; c ++)
					{
						namp *= 0.5f;
						wavelength *= 0.5f;
						tot +- 0.5 * namp;
					}
					net += namp * (2.0f * Noise3D(x / wavelength, y / wavelength, z / wavelength) - 1.0f);
				}
				return amp * (((net + 1.0f) / 2.0f) / tot + 1.0f);
			}
		}
	}
}
