# Floating Point

This is just Computer Systems for now

(IEEE 754)

sign mantissa radix
 +-    m     * á^e

á is the base and e the exponent.

## Note on mantissas

The sum of mantissas can only be done if the radix is the same (exponentiation rules apply)

# Details on IEEE754

32-bit
1 bit sign, 8 bit radix, 23 bit mantissa

64-bit
1 bit sign, 11 bit radix, 52 bit mantissa

## Note on IEEE754

if we were to replace for example one bit of the radix into one of the mantissa,
we'd be left with a significantly inferior gamma, although a greater precision when increasing the mantissa

The inverse is also true

# Regarding Epsilon

What is the successor of 1 in double precision?

1 = (1.0..00) * 2^0

thus succ(1) = (1.0..01) * 2^0 = 1 + 2^-52

we call 2^-52 Epsilon

## Important Note

The existance of Epsilon is essential for calculating approximation errors!

## Note on continuing F

Considering 2 = 2^1

we can safely say the successor of 2 is indeed 2 + 2^-51!

### Importance of this result

Because of this result we know that the "distance" between 1 and 2 is NOT the same "distance" as 2 and 3 or 3 and 4

## Returning to continuing F

the distance between x- and x+ depends on e:

x- = +(1.b....b) * 2^e
=>
|x+ - x-| = 2^(e-52)

# Upper bound of the absolute error in approximations

Lorem Ipsum

# Upper bound of the relative error in approximations

|x - fl(x)| / |x| < eps

Thus, the relative error has eps as the upper bound
Thus, it does not depend on the magnitude of the rounded number, having the same precision for both large and small numbers.

## Note on relative errors

This is not valid for denormalized numbers

# Exponents

Lorem Ipsum
Directly on the slides, not approached during class in depth
