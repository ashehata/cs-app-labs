/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* 
 * bitAnd - x&y using only ~ and | 
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 *   Max ops: 8
 *   Rating: 1
 */
int bitAnd(int x, int y) {
  /* Compute bitwise AND of arguments using bitwise OR and bitwise NEGATION */
  return ~(~x | ~y);
}


/* 
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n) {
  /* Right shift x by n bytes and perform bitwise AND with 0xff to get byte */
  return (x >> (n << 3)) & 0xff;
}
/* 
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3 
 */
int logicalShift(int x, int n) {
  /* Perform logical shift by n bits and set most significant n bits to 0*/
  int y;
  x = x >> n;
  y = ~(~0 << n) << (33 + ~n);
  return (x & ~y);
}
/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */
int bitCount(int x) {
  /* Implementation of Hamming Weight */
  int bits1, bits2, bits4, bits8, bits16, temp, temp2, temp3, temp4, temp5;
  bits1 = (0x55 << 8) + 0x55;
  bits1 = (bits1 << 16) + bits1;  // 0b01010101010101010101010101010101
  bits2 = (0x33 << 8) + 0x33;
  bits2 = (bits2 << 16) + bits2;  // 0b00110011001100110011001100110011
  bits4 = (0x0f << 8) + 0x0f;
  bits4 = (bits4 << 16) + bits4;  // 0b00001111000011110000111100001111
  bits8 = (0xff << 16) + 0xff;    // 0b00000000111111110000000011111111
  bits16 = (0xff << 8) + 0xff;    // 0b00000000000000001111111111111111
  temp = (x & bits1) + ((x >> 1) & bits1);
  temp2 = (temp & bits2) + ((temp >> 2) & bits2);
  temp3 = (temp2 & bits4) + ((temp2 >> 4) & bits4);
  temp4 = (temp3 & bits8) + ((temp3 >> 8) & bits8);
  temp5 = (temp4 & bits16) + ((temp4 >> 16) & bits16);
  return temp5;
}
/* 
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int bang(int x) {
  /* Perform bitwise negation of two's complement and restore most significant
   * byte. MSB holds the value of bang.
   */ 
  int y;
  y = (x & (0xff << 24));
  x = ~((~x) + 1);
  x = x & (~y);
  return ((x >> 31) & 0x1);
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
  /* Return result of 0b10000000 left shifted 24 times */
  return (0x80 << 24);
}
/* 
 * fitsBits - return 1 if x can be represented as an 
 *  n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int fitsBits(int x, int n) {
  /*
   *  if x < 0
   *    x = abs(x - 1);
   *  if x < (pow(2, n) - 1)
   *    return 1
   *  else
   *    return 0;
   * I have used 1's complement in statements 4 and 7 since the + 1 of 2's
   * complement is redundant and not to exceed maximum possible operators.
   */
  int temp, temp2, temp3, temp4;
  temp = x >> 31;
  temp2 = temp;
  temp = x + ~temp + 1;
  temp = (temp2 ^ temp) + ~temp2;
  temp4 = ~0;
  temp3 = (1 << (n + temp4)) + temp4;
  temp = ((temp3 + ~temp) >> 31);
  return (temp + 1);
}
/* 
 * divpwr2 - Compute x/(2^n), for 0 <= n <= 30
 *  Round toward zero
 *   Examples: divpwr2(15,1) = 7, divpwr2(-33,4) = -2
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int divpwr2(int x, int n) {
  /*
   *  if num >= 0
   *    return x / pow(2, n)
   *  else
   *    return (x + pow(2, n) + 1) / pow(2,n)
   */
  int temp, temp2;
  temp = (1 << n) + ~0;
  temp2 = (x >> 31);
  x = x + (temp & temp2);
  return (x >> n);
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  /* Return 2's complement of the number */
  return (~x + 1);
}
/* 
 * isPositive - return 1 if x > 0, return 0 otherwise 
 *   Example: isPositive(-1) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 3
 */
int isPositive(int x) {
  /* Bitwise AND of double bang of x and sign bit of x */
  return (~(x >> 31) & 0x1) & !(!x);
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
  /*
   * If sign bits are different
   *    return sign bit of x
   * else
   *    return sign bit of (x - y - 1).
   */
  int temp, temp2, temp3, temp4, ret;
  temp = (x >> 31);
  temp2 = (y >> 31);
  temp3 = (temp ^ temp2);
  ret = (temp3 & temp) & 0x1;
  temp4 = ((x + ~y) >> 31) & 0x1;
  ret = ret + (~temp3 & temp4);
  return ret;
}
/*
 * ilog2 - return floor(log base 2 of x), where x > 0
 *   Example: ilog2(16) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 90
 *   Rating: 4
 */
int ilog2(int x) {
  /*
   * Source: http://graphics.stanford.edu/~seander/bithacks.html.
   * I implemented '>' using a combination of subtraction(addition with 2's
   * complement and isPositive() code above.
   */
  int temp, temp2, temp3, res;
  temp3 = (0xff << 8) + 0xfe;
  temp = (x + ~temp3);
  temp = (~(temp >> 31) & 0x1) & !(!temp);
  res = temp << 4;
  x = x >> res;
  temp = (x + ~0xfe);
  temp = (~(temp >> 31) & 0x1) & !(!temp);
  temp2 = temp << 3;
  x = x >> temp2;
  res = res | temp2;
  temp = (x + ~0xe);
  temp = (~(temp >> 31) & 0x1) & !(!temp);
  temp2 = temp << 2;
  x = x >> temp2;
  res = res | temp2;
  temp = (x + ~0x2);
  temp = (~(temp >> 31) & 0x1) & !(!temp);
  temp2 = temp << 1;
  x = x >> temp2;
  res = res | temp2;
  res = res | (x >> 1);
  return res;
}
/* 
 * float_neg - Return bit-level equivalent of expression -f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_neg(unsigned uf) {
 return 2;
}
/* 
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_i2f(int x) {
  return 2;
}
/* 
 * float_twice - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_twice(unsigned uf) {
  return 2;
}
