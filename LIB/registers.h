/**
 *@brief    registers.h
 *@author   Belkasy
 *@date     12 Sep 2022
*/

#ifndef _REGISTER_H_
#define _REGISTER_H_



/*
************************************************************
!-                      DIO registers 
************************************************************
*/
#define PORTA       *((u8 *)(0x3B))
#define PORTB       *((u8 *)(0x38))
#define PORTC       *((u8 *)(0x35))
#define PORTD       *((u8 *)(0x32))

#define DDRA        *((u8 *)(0x3A))
#define DDRB        *((u8 *)(0x37))
#define DDRC        *((u8 *)(0x34))
#define DDRD        *((u8 *)(0x31))

#define PINA        *((volatile u8 *)(0x39))
#define PINB        *((volatile u8 *)(0x36))
#define PINC        *((volatile u8 *)(0x33))
#define PIND        *((volatile u8 *)(0x30))

/*
************************************************************
!-                      GIE registers 
************************************************************
*/
#define SREG        *((volatile u8 *)(0x5F))

/*
************************************************************
!-                      INT registers 
************************************************************
*/
#define MCUCR           *((u8 *)(0x55))
#define MCUCSR          *((u8 *)(0x54))
#define GICR            *((u8 *)(0x5B))
#define GIFR            *((u8 *)(0x5A))

/*
************************************************************
!-                    TIMERs registers 
************************************************************
*/
/* TIMERs  */
#define TIMSK       *((u8 *)(0x59))
#define TIFR        *((u8 *)(0x58))
#define SFIOR       *((u8 *)(0x50))

/* TIMER 0 */   
#define TCCR0       *((u8 *)(0x53))
#define TCNT0       *((u8 *)(0x52))
#define OCR0        *((u8 *)(0x5C))

/* TIMER 1 */   
#define TCCR1A      *((u8 *)(0x4F))
#define TCCR1B      *((u8 *)(0x4E))
#define TCNT1H      *((u8 *)(0x4D))
#define TCNT1L      *((u8 *)(0x4C))
#define OCR1AH      *((u8 *)(0x4B))
#define OCR1AL      *((u8 *)(0x4A))
#define OCR1BH      *((u8 *)(0x49))
#define OCR1BL      *((u8 *)(0x48))
#define ICR1H       *((u8 *)(0x47))
#define ICR1L       *((u8 *)(0x46))

/* TIMER 2 */   
#define TCCR2       *((u8 *)(0x45))
#define TCNT2       *((u8 *)(0x44))
#define OCR2        *((u8 *)(0x43))


#endif /** @endif _REGISTER_H_ */