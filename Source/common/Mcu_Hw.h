/***********************************************************************************************************************************************************
 *	FILE DESCRIPTION
 *	------------------------------------------------------------------------------------------------------------------------------------------------------*/
/**		\file 	Mcu_Hw.h
 *		\brief 	MCU registers definition Header file
 *		\details
 *
 *
 *
 *********************************************************************************************************************************************************/
#ifndef MCU_HW_H
#define MCU_HW_H

/*********************************************************************************************************************************************************
 *	INCLUDES
 ********************************************************************************************************************************************************/

#include "STD_TYPES.h"

/*********************************************************************************************************************************************************
 *	GLOBAL DATA TYPES AND STRUCTURES
 ********************************************************************************************************************************************************/

/*Access reg by Bit-fileds*/
typedef struct
{
    u32 VECACT : 8;
    u32 : 3;
    u32 RETBASE : 1;
    u32 VECPEND : 8;
    u32 : 2;
    u32 ISRPEND : 1;
    u32 ISRPRE : 1;
    u32 : 1;
    u32 PENDSTCLR : 1;
    u32 PENDSTSET : 1;
    u32 UNPENDSV : 1;
    u32 PENDSV : 1;
    u32 : 2;
    u32 NMISET : 1;
} INTCTRL_REG;

/*Choose how to access the reg Write/Block*/
typedef union
{

    u32 Reg;
    INTCTRL_REG reg;
} INTCTRL_FIELD;

/*Access reg by Bit-fileds*/
typedef struct
{
    u32 : 10;
    u32 OFFSET : 22;
} VTABLE_REG;

/*Choose how to access the reg Write/Block*/
typedef union
{

    u32 Reg;
    VTABLE_REG B;
} VTABLE_FIELD;

/*Access reg by Bit-fileds*/
typedef struct
{
    u32 VECTREST : 1;
    u32 VECTCLRACT : 1;
    u32 SYSRESREQ : 1;
    u32 : 5;
    u32 PRIGROUP : 3;
    u32 : 4;
    u32 ENDIANESS : 1;
    u32 VECTKEY : 16;
} APINT_REG;

/*Choose how to access the reg Write/Block*/
typedef union
{

    u32 Reg;
    VTABLE_REG B;
} APINT_FIELD;


/*Access reg by Bit-fileds*/
typedef struct
{
    u32  : 5;
    u32 MEM : 3;
    u32  : 5;
    u32 : 5;
    u32 BUS : 3;
    u32 : 5;
    u32 USAGE:3;
    u32 : 8;
} SYSPRI1_REG;

/*Choose how to access the reg Write/Block*/
typedef union
{

    u32 Reg;
    SYSPRI1_REG B;
} SYSPRI1_FIELD;



/*Access reg by Bit-fileds*/
typedef struct
{
    u32  : 29;
    u32 SVC: 3;
} SYSPRI2_REG;

/*Choose how to access the reg Write/Block*/
typedef union
{

    u32 Reg;
    SYSPRI2_REG B;
} SYSPRI2_FIELD;

/*Access reg by Bit-fileds*/
typedef struct
{
    u32  :5;
    u32 DEBUG:3;
    u32 : 13;
    u32 PENDSV : 3;
    u32 : 5;
    u32 TICK :3;
} SYSPRI3_REG;

/*Choose how to access the reg Write/Block*/
typedef union
{

    u32 Reg;
    SYSPRI3_REG B;
} SYSPRI3_FIELD;


/*Access reg by Bit-fileds*/
typedef struct
{
    u32  MEMA :1;
    u32  BUSA :1;
    u32   :1;
    u32  USGA :1;
    u32  :3;
    u32  SVCA :1;
    u32  MON :1;
    u32   :1;
    u32  PNDSV :1;
    u32  TICK :1;
    u32  USAGEP :1;
    u32  MEMP :1;
    u32  BUSP :1;
    u32  SVC :1;
    u32  MEM :1;
    u32  BUS :1;
    u32  USAGE :1;
    u32   :13;
} SYSHNDCTRL_REG;

/*Choose how to access the reg Write/Block*/
typedef union
{

    u32 Reg;
    SYSHNDCTRL_REG B;
} SYSHNDCTRL_FIELD;

/*********************************************************************************************************************************************************
 *	GLOBAL CONSTANTS MACROS
 ********************************************************************************************************************************************************/


#define CORTEXM4_BASE_ADDR 0xE000E000


/*********************************      SCB    *********************************/

#define APINT_OFFSET 0xD0C
#define INTCTRL_OFFSET 0xD04
#define VTABLE_OFFSET 0xD08
#define SYSPRI1_OFFSET 0xD18
#define SYSPRI2_OFFSET 0xD1C
#define SYSPRI3_OFFSET 0xD20

#define SYSHNDCTRL_OFFSET 0xD24

#define APIN_VECTKEY 0x05F

#define APINT *((volatile APINT_FIELD *)(CORTEXM4_BASE_ADDR + APINT_OFFSET))
#define INTCTRL *((volatile INTCTRL_FIELD *)(CORTEXM4_BASE_ADDR + INTCTRL_OFFSET))
#define VTABLE *((volatile VTABLE_FIELD *)(CORTEXM4_BASE_ADDR + VTABLE_OFFSET))

#define SYSPRI1 *((volatile SYSPRI1_FIELD *)(CORTEXM4_BASE_ADDR + SYSPRI1_OFFSET))
#define SYSPRI2 *((volatile SYSPRI2_FIELD *)(CORTEXM4_BASE_ADDR + SYSPRI2_OFFSET))
#define SYSPRI3 *((volatile SYSPRI3_FIELD *)(CORTEXM4_BASE_ADDR + SYSPRI3_OFFSET))
#define SYSHNDCTRL *((volatile SYSHNDCTRL_FIELD *)(CORTEXM4_BASE_ADDR + SYSHNDCTRL_OFFSET))


/*********************************      NVIC    *********************************/

/***************      Enable    ***************/

#define EN0_OFFSET 0x100
#define EN1_OFFSET 0x104
#define EN2_OFFSET 0x108
#define EN3_OFFSET 0x10C
#define EN4_OFFSET 0x110


#define EN0 *((volatile u32 * )(CORTEXM4_BASE_ADDR + EN0_OFFSET))
#define EN1 *((volatile u32 * )(CORTEXM4_BASE_ADDR + EN1_OFFSET))
#define EN2 *((volatile u32 * )(CORTEXM4_BASE_ADDR + EN2_OFFSET))
#define EN3 *((volatile u32 * )(CORTEXM4_BASE_ADDR + EN3_OFFSET))
#define EN4 *((volatile u16 * )(CORTEXM4_BASE_ADDR + EN4_OFFSET))


/***************      Disable    ***************/

#define DIS0_OFFSET 0x180
#define DIS1_OFFSET 0x184
#define DIS2_OFFSET 0x188
#define DIS3_OFFSET 0x18C
#define DIS4_OFFSET 0x190


#define DIS0 *((volatile u32 * )(CORTEXM4_BASE_ADDR + DIS0_OFFSET))
#define DIS1 *((volatile u32 * )(CORTEXM4_BASE_ADDR + DIS1_OFFSET))
#define DIS2 *((volatile u32 * )(CORTEXM4_BASE_ADDR + DIS2_OFFSET))
#define DIS3 *((volatile u32 * )(CORTEXM4_BASE_ADDR + DIS3_OFFSET))
#define DIS4 *((volatile u16 * )(CORTEXM4_BASE_ADDR + DIS4_OFFSET))


/***************      Pinding    ***************/

#define PEND0_OFFSET 0x200
#define PEND1_OFFSET 0x204
#define PEND2_OFFSET 0x208
#define PEND3_OFFSET 0x20C
#define PEND4_OFFSET 0x210


#define PEND0 *((volatile u32 * )(CORTEXM4_BASE_ADDR + PEND0_OFFSET))
#define PEND1 *((volatile u32 * )(CORTEXM4_BASE_ADDR + PEND1_OFFSET))
#define PEND2 *((volatile u32 * )(CORTEXM4_BASE_ADDR + PEND2_OFFSET))
#define PEND3 *((volatile u32 * )(CORTEXM4_BASE_ADDR + PEND3_OFFSET))
#define PEND4 *((volatile u16 * )(CORTEXM4_BASE_ADDR + PEND4_OFFSET))


/***************      UnPinding    ***************/

#define UNPEND0_OFFSET 0x280
#define UNPEND1_OFFSET 0x284
#define UNPEND2_OFFSET 0x288
#define UNPEND3_OFFSET 0x28C
#define UNPEND4_OFFSET 0x290


#define UNPEND0 *((volatile u32 * )(CORTEXM4_BASE_ADDR + UNPEND0_OFFSET))
#define UNPEND1 *((volatile u32 * )(CORTEXM4_BASE_ADDR + UNPEND1_OFFSET))
#define UNPEND2 *((volatile u32 * )(CORTEXM4_BASE_ADDR + UNPEND2_OFFSET))
#define UNPEND3 *((volatile u32 * )(CORTEXM4_BASE_ADDR + UNPEND3_OFFSET))
#define UNPEND4 *((volatile u16 * )(CORTEXM4_BASE_ADDR + UNPEND4_OFFSET))



/***************      Active    ***************/

#define ACTIVE0_OFFSET 0x300
#define ACTIVE1_OFFSET 0x304
#define ACTIVE2_OFFSET 0x308
#define ACTIVE3_OFFSET 0x30C
#define ACTIVE4_OFFSET 0x310


#define ACTIVE0 *((volatile u32 * )(CORTEXM4_BASE_ADDR + ACTIVE0_OFFSET))
#define ACTIVE1 *((volatile u32 * )(CORTEXM4_BASE_ADDR + ACTIVE1_OFFSET))
#define ACTIVE2 *((volatile u32 * )(CORTEXM4_BASE_ADDR + ACTIVE2_OFFSET))
#define ACTIVE3 *((volatile u32 * )(CORTEXM4_BASE_ADDR + ACTIVE3_OFFSET))
#define ACTIVE4 *((volatile u16 * )(CORTEXM4_BASE_ADDR + ACTIVE4_OFFSET))



/***************      Priorities    ***************/

typedef union {
    u32 : 5;
    u32 INTA :3;
    u32 : 5;
    u32 INTB :3;
    u32 :5;
    u32 INTC :3;
    u32 : 5;
    u32 INTD :3;
}intPriority_Type;

#define PRI0 *((volatile u32 * )(CORTEXM4_BASE_ADDR + 0x400))
#define PRI1 *((volatile u32 * )(CORTEXM4_BASE_ADDR + 0x404))
#define PRI2 *((volatile u32 * )(CORTEXM4_BASE_ADDR + 0x408))
#define PRI3 *((volatile u32 * )(CORTEXM4_BASE_ADDR + 0x40C))
#define PRI4 *((volatile u32 * )(CORTEXM4_BASE_ADDR + 0x410))
#define PRI5 *((volatile u32 * )(CORTEXM4_BASE_ADDR + 0x414))

#define PRI6 *((volatile u32 * )(CORTEXM4_BASE_ADDR + 0x418))
#define PRI7 *((volatile u32 * )(CORTEXM4_BASE_ADDR + 0x41C))
#define PRI8 *((volatile u32 * )(CORTEXM4_BASE_ADDR + 0x420))
#define PRI9 *((volatile u32 * )(CORTEXM4_BASE_ADDR + 0x424))
#define PRI10 *((volatile u32 * )(CORTEXM4_BASE_ADDR + 0x428))

#define PRI11 *((volatile u32 * )(CORTEXM4_BASE_ADDR + 0x42C))
#define PRI12 *((volatile u32 * )(CORTEXM4_BASE_ADDR + 0x430))
#define PRI13 *((volatile u32 * )(CORTEXM4_BASE_ADDR + 0x434))
#define PRI14 *((volatile u32 * )(CORTEXM4_BASE_ADDR + 0x438))
#define PRI15 *((volatile u32 * )(CORTEXM4_BASE_ADDR + 0x43C))

#define PRI16 *((volatile u32 * )(CORTEXM4_BASE_ADDR + 0x440))
#define PRI17 *((volatile u32 * )(CORTEXM4_BASE_ADDR + 0x444))
#define PRI18 *((volatile u32 * )(CORTEXM4_BASE_ADDR + 0x448))
#define PRI19 *((volatile u32 * )(CORTEXM4_BASE_ADDR + 0x44C))
#define PRI20 *((volatile u32 * )(CORTEXM4_BASE_ADDR + 0x450))

#define PRI21 *((volatile u32 * )(CORTEXM4_BASE_ADDR + 0x454))
#define PRI22 *((volatile u32 * )(CORTEXM4_BASE_ADDR + 0x458))
#define PRI23 *((volatile u32 * )(CORTEXM4_BASE_ADDR + 0x45C))
#define PRI24 *((volatile u32 * )(CORTEXM4_BASE_ADDR + 0x460))
#define PRI25 *((volatile u32 * )(CORTEXM4_BASE_ADDR + 0x464))

#define PRI26 *((volatile u32 * )(CORTEXM4_BASE_ADDR + 0x468))
#define PRI27 *((volatile u32 * )(CORTEXM4_BASE_ADDR + 0x46C))
#define PRI28 *((volatile u32 * )(CORTEXM4_BASE_ADDR + 0x470))
#define PRI29 *((volatile u32 * )(CORTEXM4_BASE_ADDR + 0x474))
#define PRI30 *((volatile u32 * )(CORTEXM4_BASE_ADDR + 0x478))

#define PRI31 *((volatile u32 * )(CORTEXM4_BASE_ADDR + 0x47C))
#define PRI32 *((volatile u32 * )(CORTEXM4_BASE_ADDR + 0x480))
#define PRI33 *((volatile u32 * )(CORTEXM4_BASE_ADDR + 0x484))
#define PRI34 *((volatile u32 * )(CORTEXM4_BASE_ADDR + 0x488))


/***************      SW Trigger    ***************/

#define SWTRIG *((volatile u8 * )(CORTEXM4_BASE_ADDR + 0xF00))


/*********************************************************************************************************************************************************
 *	GLOBAL FUNCTION MACROS
 ********************************************************************************************************************************************************/

/*********************************************************************************************************************************************************
 *	GLOBAL DATA PROTOTYPES
 ********************************************************************************************************************************************************/

#endif /*Mcu_Hw.h*/
/*********************************************************************************************************************************************************
 *	END OF FILE Mcu_Hw.h
 ********************************************************************************************************************************************************/