<<<<<<< HEAD
<<<<<<< HEAD
/* Auther: AHMED SAMIR */
/* Date: 16/7/2022 */
/* Version: V01 */

#ifndef BIT_MATH_H
#define BIT_MATH_H

#define SET_BIT(VAR,BIT)       VAR |= (1 << (BIT))
#define CLR_BIT(VAR,BIT)       VAR &= ~(1 << (BIT))
#define GET_BIT(VAR,BIT)       ((VAR >> BIT) & 1)
#define TOG_BIT(VAR,BIT)       VAR ^= (1 << (BIT))


/*check if a specified Bit is Set*/
#define BIT_IS_SET(REG,BIT)      ((REG>>BIT)&1)
/*Check if a specified BIT is Clear*/
#define BIT_IS_CLEAR(REG,BIT)  (!((REG>>BIT)&1))
=======
/*
 * File:   BIT_MATH.h
 * Author: Mohamed_Nagy
 * https://github.com/Ged0oo
 * https://www.linkedin.com/in/mohamednagyofficial/
 * Created on February 16, 2023, 8:41 PM
 */
>>>>>>> a50749486543186b42231336da2f32bf6effdd55


#ifndef BIT_MATH_H
#define BIT_MATH_H

<<<<<<< HEAD
=======
#define SET_BIT(VAR,BIT)       VAR |= (1 << (BIT))
#define CLEAR_BIT(VAR,BIT)       VAR &= ~(1 << (BIT))
#define GET_BIT(VAR,BIT)       ((VAR >> BIT) & 1)
#define TOG_BIT(VAR,BIT)       VAR ^= (1 << (BIT))

/*check if a specified Bit is Set*/
#define BIT_IS_SET(REG,BIT)      ((REG>>BIT)&1)
/*Check if a specified BIT is Clear*/
#define BIT_IS_CLEAR(REG,BIT)  (!((REG>>BIT)&1))


>>>>>>> a50749486543186b42231336da2f32bf6effdd55
#endif
=======
<<<<<<< HEAD
/* Auther: AHMED SAMIR */
/* Date: 16/7/2022 */
/* Version: V01 */

#ifndef BIT_MATH_H
#define BIT_MATH_H

#define SET_BIT(VAR,BIT)       VAR |= (1 << (BIT))
#define CLR_BIT(VAR,BIT)       VAR &= ~(1 << (BIT))
#define GET_BIT(VAR,BIT)       ((VAR >> BIT) & 1)
#define TOG_BIT(VAR,BIT)       VAR ^= (1 << (BIT))


/*check if a specified Bit is Set*/
#define BIT_IS_SET(REG,BIT)      ((REG>>BIT)&1)
/*Check if a specified BIT is Clear*/
#define BIT_IS_CLEAR(REG,BIT)  (!((REG>>BIT)&1))
=======
/*
 * File:   BIT_MATH.h
 * Author: Mohamed_Nagy
 * https://github.com/Ged0oo
 * https://www.linkedin.com/in/mohamednagyofficial/
 * Created on February 16, 2023, 8:41 PM
 */
>>>>>>> a50749486543186b42231336da2f32bf6effdd55


#ifndef BIT_MATH_H
#define BIT_MATH_H

<<<<<<< HEAD
=======
#define SET_BIT(VAR,BIT)       VAR |= (1 << (BIT))
#define CLEAR_BIT(VAR,BIT)       VAR &= ~(1 << (BIT))
#define GET_BIT(VAR,BIT)       ((VAR >> BIT) & 1)
#define TOG_BIT(VAR,BIT)       VAR ^= (1 << (BIT))

/*check if a specified Bit is Set*/
#define BIT_IS_SET(REG,BIT)      ((REG>>BIT)&1)
/*Check if a specified BIT is Clear*/
#define BIT_IS_CLEAR(REG,BIT)  (!((REG>>BIT)&1))


>>>>>>> a50749486543186b42231336da2f32bf6effdd55
#endif
>>>>>>> 1f8e90be1367598cf8577562d82a56c1e775a7a5
