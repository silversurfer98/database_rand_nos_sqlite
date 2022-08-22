#include "rand.h"
#include<trig.h>
#include<power.h>

struct Ran
{
	unsigned long long int u, v, w;
	Ran(unsigned long long int j) : v(4101842887655102017LL), w(1)
	{
		u = j ^ v; 
		int64();

		v = u; 
		int64();

		w = v; 
		int64();
	}

	inline unsigned long long int int64()
	{
		u = u * 2862933555777941757LL + 7046029254386353087LL;
		v ^= v >> 17; 
		v ^= v << 31; 
		v ^= v >> 8;
		w = 4294957665U * (w & 0xffffffff) + (w >> 32);
		unsigned long long int x = u ^ (u << 21); 
		x ^= x >> 35; 
		x ^= x << 4;
		return (x + v) ^ w;
	}

	inline double doub()
	{
		return 5.42101086242752217E-20 * int64();
	}
	inline unsigned int int32()
	{
		return (unsigned int)int64();
	}

};


float* gauss_random(size_t x, float a, float b, float sd, unsigned long long int seed)
{

	Ran r(seed);
	trignometry t(MAX_PRECISION_TRIG, 'r');
	float* gauss_dev = new float[x];

	float sq, trig, temp, U1, U2, mean = (a + b) / 2;
	for (size_t i = 0; i < x/2; i++)
	{
		do
		{
			U1 = (float)r.doub();
			U2 = (float)r.doub();

			sq = mysq(-2.0 * mln(U1));
			temp = 2.0 * t.PI * U2;
			trig = t.cos(temp);
			*(gauss_dev + (i * 2)) = ((sq * trig) * sd) + mean;
			trig = t.sin(temp);
			*(gauss_dev + (i * 2) + 1) = ((sq * trig) * sd) + mean;

		} while (*(gauss_dev + (i * 2)) < a || *(gauss_dev + (i * 2) + 1) < a);

	}

	return gauss_dev;
}