// GitHub Account: GitHub.com/AliRezaJoodi

#ifndef _UTILITY_INCLUDED
    #define _UTILITY_INCLUDED

#define SetBit(ADDRESS,BIT) 								ADDRESS= ADDRESS | (0b1U<<BIT);
#define SetBit_NoLastStatus(ADDRESS,BIT) 		ADDRESS= 0b1U<<BIT;
#define ClearBit(ADDRESS,BIT) 							ADDRESS= ADDRESS & ~(0b1U<<BIT);
#define ClearBit_NoLastStatus(ADDRESS,BIT) 	ADDRESS= ~(0b1U<<BIT);
#define ToggleBit(ADDRESS,BIT)        			ADDRESS= ADDRESS ^ (0b1U<<BIT);
#define EqualBit(ADDRESS,BIT,STATUS)				ADDRESS= (ADDRESS & ~(0b1UL << BIT)) | ((STATUS&0b1UL) << BIT);
#define GetBit(ADDRESS,BIT)           			((ADDRESS >> BIT) & 0b1U) 

#endif
