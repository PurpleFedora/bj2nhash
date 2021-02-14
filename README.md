# bj2nhash
Hashing function that takes 2 32 bit unsigned integer based on DJB2a

It uses uint32_t as numbers. It gets the type from stdint.h, if available or if uint32_t is not defined as a macro it defines it with limits.h
