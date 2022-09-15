/*
 *@Name: STD_Types.h
 *@authors: Belkasy
 *@Date: 12 Sep 2022
*/

/** @def header guard */
#ifndef __STD_TYPES_H__
#define __STD_TYPES_H__

/*
--------------------------------------------------------------------------------------------------
!-                                      Standard Types                                          -
--------------------------------------------------------------------------------------------------
*/

#define NULL (void *)(0)

/** @defgroup signed */
typedef signed char         s8;
typedef signed short int    s16;
typedef signed long  int    s32;
typedef signed long         s64;

/** @defgroup const signed */
typedef const signed char         cs8;
typedef const signed short int    cs16;
typedef const signed long  int    cs32;
typedef const signed long         cs64;

/** @defgroup unsigned */
typedef unsigned char       u8;
typedef unsigned short int  u16;
typedef unsigned long  int  u32;
typedef unsigned long       u64;

/** @defgroup const unsigned */
typedef const unsigned char       cu8;
typedef const unsigned short int  cu16;
typedef const unsigned long  int  cu32;

typedef const unsigned long       cu64;
/** @defgroup decimal point */
typedef float               f32;
typedef double              f64;
typedef long double         f128;

/** @defgroup const decimal point */
typedef const float               cf32;
typedef const double              cf64;
typedef const long double         cf128;

/** @defgroup PINS */
#define BIT0    0
#define BIT1    1
#define BIT2    2
#define BIT3    3
#define BIT4    4
#define BIT5    5
#define BIT6    6
#define BIT7    7

/** @defgroup bools */
#define FALSE    0
#define TRUE   1

/** @defgroup Signals */
#define LOW    0
#define HIGH   1

/** @defgroup Directions */
#define INPUT      0
#define OUTPUT     1

/** @defgroup PINS */
#define PIN0    0
#define PIN1    1
#define PIN2    2
#define PIN3    3
#define PIN4    4
#define PIN5    5
#define PIN6    6
#define PIN7    7

#endif /* __STD_TYPES_H__ */
