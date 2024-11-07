// GitHub Account: GitHub.com/AliRezaJoodi

#ifndef _UTILITY_INCLUDED
#define _UTILITY_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif


#define SetBit(ADDRESS, BIT) 								ADDRESS = (ADDRESS) | (0b1UL<<(BIT));
#define SetBit_NoLastStatus(ADDRESS, BIT) 	ADDRESS = 0b1UL<<(BIT);
#define ClearBit(ADDRESS, BIT) 							ADDRESS = (ADDRESS) & (~(0b1UL<<(BIT)));
#define ClearBit_NoLastStatus(ADDRESS, BIT) ADDRESS = ~(0b1UL<<(BIT));
#define ToggleBit(ADDRESS, BIT)        			ADDRESS = (ADDRESS) ^ (0b1UL<<(BIT));
#define ToggleData(ADDRESS)        					ADDRESS = ~(ADDRESS);

#define WriteBit(ADDRESS, FROM, VALUE)			ADDRESS = ((ADDRESS) & (~(0b1UL<<(FROM)))) 			| ((0b1UL&(VALUE)) << (FROM));
#define Write2Bit(ADDRESS, FROM, VALUE)			ADDRESS = ((ADDRESS) & (~(0b11UL<<(FROM)))) 		| ((0b11UL&(VALUE)) << (FROM));
#define Write3Bit(ADDRESS, FROM, VALUE)			ADDRESS = ((ADDRESS) & (~(0b111UL<<(FROM)))) 		| ((0b111UL&(VALUE)) << (FROM));
#define Write4Bit(ADDRESS, FROM, VALUE)			ADDRESS = ((ADDRESS) & (~(0b1111UL<<(FROM)))) 	| ((0b1111UL&(VALUE)) << (FROM));
#define Write5Bit(ADDRESS, FROM, VALUE)			ADDRESS = ((ADDRESS) & (~(0b11111UL<<(FROM)))) 	| ((0b11111UL&(VALUE)) << (FROM));

#define GetBit(ADDRESS, FROM)           		(((ADDRESS) >> (FROM)) 	& 0b1)
#define Get2Bit(ADDRESS, FROM)           		(((ADDRESS) >> (FROM)) 	& 0b11)
#define Get3Bit(ADDRESS, FROM)           		(((ADDRESS) >> (FROM)) 	& 0b111)
#define Get4Bit(ADDRESS, FROM)           		(((ADDRESS) >> (FROM)) 	& 0b1111)
#define Get5Bit(ADDRESS, FROM)           		(((ADDRESS) >> (FROM)) 	& 0b11111)

#ifdef __cplusplus
}
#endif

#endif	// _UTILITY_INCLUDED
