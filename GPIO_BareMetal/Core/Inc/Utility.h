// GitHub Account: GitHub.com/AliRezaJoodi

#ifndef _UTILITY_INCLUDED
    #define _UTILITY_INCLUDED

#define SetBit(ADDRESS,BIT) 								ADDRESS= ADDRESS | (0b1UL<<BIT);
#define SetBit_NoLastStatus(ADDRESS,BIT) 		ADDRESS= 0b1UL<<BIT;
#define ClearBit(ADDRESS,BIT) 							ADDRESS= ADDRESS & ~(0b1UL<<BIT);
#define ClearBit_NoLastStatus(ADDRESS,BIT) 	ADDRESS= ~(0b1UL<<BIT);
#define ToggleBit(ADDRESS,BIT)        			ADDRESS= ADDRESS ^ (0b1UL<<BIT);
#define WriteBit(ADDRESS,BIT,STATUS)				ADDRESS= (ADDRESS & ~(0b1UL << BIT)) | ((STATUS&0b1UL) << BIT);
#define Write2Bit(ADDRESS,FROM,VALUE)				ADDRESS= (ADDRESS & ~(0b11UL << FROM)) | ((VALUE&0b11UL) << FROM);
#define Write3Bit(ADDRESS,FROM,VALUE)				ADDRESS= (ADDRESS & ~(0b111UL << FROM)) | ((VALUE&0b111UL) << FROM);
#define Write4Bit(ADDRESS,FROM,VALUE)				ADDRESS= (ADDRESS & ~(0b1111UL << FROM)) | ((VALUE&0b1111UL) << FROM);
#define GetBit(ADDRESS,BIT)           			((ADDRESS >> BIT) & 0b1UL) 
#define Get2Bit(ADDRESS,FROM)           		((ADDRESS >> FROM) & 0b11UL)
#define Get3Bit(ADDRESS,FROM)           		((ADDRESS >> FROM) & 0b111UL)
#define Get4Bit(ADDRESS,FROM)           		((ADDRESS >> FROM) & 0b1111UL)

#endif

