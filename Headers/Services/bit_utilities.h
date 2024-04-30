#ifndef Bit_Utilies
#define Bit_Utilies

#define READ_REG(reg)        (reg&0xff)

#define SET(reg,val)          reg |= val

#define CLEAR(reg,val)        reg &=~val


#define SET_BIT(REG,BIT_POSN)       (REG |= (1 << BIT_POSN))
#define CLEAR_BIT(REG,BIT_POSN)     (REG &= ~(1 << BIT_POSN))
#define TOGGLE_BIT(REG,BIT_POSN)    (REG ^= (1 << BIT_POSN))
#define READ_BIT(REG,BIT_POSN)      ( (REG>>BIT_POSN) & (uint8_t)1 )

#endif
