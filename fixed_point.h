#ifndef __THREAD_FIXED_POINT_H
#define __THREAD_FIXED_POINT_H

/* Basic definitions of fixed point. */
typedef int real;
/* 16 LSB used for fractional part. */
#define real_shift_value 16

/* Some helpful macros. */
/* Convert a value to fixed-point value. */
#define real_const(x) ((real)(x << real_shift_value))
/* Add two fixed-point value. */
#define real_add(x,y) (x + y)
/* Add a fixed-point value A and an int value B. */
#define real_add_int(x,y) (x + (y << real_shift_value))
/* Substract two fixed-point value. */
#define real_sub(x,y) (x - y)
/* Substract an int value B from a fixed-point value A */
#define real_sub_int(x,y) (x - (y << real_shift_value))
/* Multiply a fixed-point value A by an int value B. */
#define real_mult_int(x,y) (x * y)
/* Divide a fixed-point value A by an int value B. */
#define real_div_int(x,y) (x / y)
/* Multiply two fixed-point value. */
#define real_mult(x,y) ((real)(((int64_t) x) * y >> real_shift_value))
/* Divide two fixed-point value. */
#define real_div(x,y) ((real)((((int64_t) x) << real_shift_value) / y))
/* Get integer part of a fixed-point value. */
#define real_int(x) (x >> real_shift_value)
/* Get rounded integer of a fixed-point value. */
#define real_round(x) (x >= 0 ? ((x + (1 << (real_shift_value - 1))) >> real_shift_value) \
                            : ((x - (1 << (real_shift_value - 1))) >> real_shift_value))

#endif /* thread/fixed_point.h */