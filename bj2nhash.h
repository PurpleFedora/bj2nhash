#ifndef BJ2NHASH_H_
	#define BJ2NHASH_H_

	#ifndef uint32_t
		#if defined __STDC_VERSION__ && __STDC_VERSION__ >= 199901L
			#include <stdint.h>
		#else
			#include <limits.h>

			#if USHRT_MAX >= 0xFFFFFFFF
				#define uint32_t unsigned short int
			#elif UINT_MAX >= 0xFFFFFFFF
				#define uint32_t unsigned int
			#elif ULONG_MAX >= 0xFFFFFFFF
				#define uint32_t unsigned long int
			#else
				#error No <stdint.h> available and 32 bit integer could not be found in <limits.h>
			#endif
			
			#define BJ2NHASH_UINT32_FOUND
		#endif
	#endif


	uint32_t bj2nhash(uint32_t n, uint32_t n2) {
		uint32_t hash = 5381;
		{
		int c;
			while ((c = n>>=2))
				hash = hash * 33 ^ c;
			while ((c = n2<<=2))
				hash = hash * 33 ^ c;
		}

		return hash;
	}

	#ifdef BJ2NHASH_UINT32_FOUND
		#undef BJ2NHASH_UINT32_FOUND
		#undef uint32_t
	#endif

#endif
