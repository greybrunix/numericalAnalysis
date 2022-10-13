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

# Note on Overflows

Matlab (and Octave) handle overflows by calling any number greater than 2^1023, "Inf".

# Note on Underflows

Matlab (and Octave) handle underflows by denormalizing any number smaller than 2^-1022 and such having less precision

Thus, Matlab has a gradual underflow.

# Rounding

```Matlab
system_dependant('setround','Inf')
system_dependant('setround','-Inf')
system_dependant('setround','0')
system_dependant('setround','nearest')
```

# Significant digits

There are always 53 significant bits in a normalized representation of a floating point number (IEEE-754)

## Correct significant digits

-x- = (0.d...d-t) * 10^e

mantissa with t digits, then |x - -x-| < 10^(e-t).

When rounding to the closest:

        |x - -x-| <=

### Matlab Examples

Check slides

# Subtractive Cancellation

This phenomenon occurs when, due to subtracting numbers, you lose significant digits.

## How to detect when Subtractive Cancellation might occurr

When the order of the result is much smaller than the order of the operands

# Subtractive Cancellation (2)

Despite not necessarily having a great absolute error, the relative error is of a greater magnitude.

This relative error can and will result in a propagation of the error and exponentiating the absolute error.

# Conditioning a Function

Lorem Ipsum

# Absolute Condition of a Function in a Point

Formula of Taylor is the formula for f(x + delta x)

thus such is |f' (x)|

## Truncation Error

Are the terms that are ignored

# Notes for class on the 3rd of October

Mainly just analysis/Calculus II reminders, a.k.a. convergent series

But adding some notes on Taylor's Series

# Sum of Convergent Series ( Truncation Error )
## Sum of Geometric Convergent Series

Let us consider the series with ratio 0.1 and 1st term 1

1 + 10^-1 + ... 10^-16 + ...

S = 1/(1-0.1) = 1/0.9

### Conclusion on series

Due to approximation issues, a LOT of the parcels of the series will be ignored for they cannot be represented in such a way that they alter in any
significant way the result of the sum, thus they can be ignored.

Such a phenomena is called a Truncation Error.

Coming back to the Absolute Condition of a Function in a Point, the Truncation Error is, thus, one of the second order.

# Relative Condition of a Function in a Point 

| x.f'(x) / f(x) |

# Relative Condition and loss of correct significant digits

If the relative condition is of 10^k then there is loss of k decimal digits

# Forward Error and Backward Error
## Forward Error

 - The calculated value for data x is not the exact value of y = f(x) but actually an approximation of y -> AproxY
 - DeltaY = f(x) - AproxY
 - DeltaY is the Forward Error (*Erro Direto*)

## Backward Error

 - x + DeltaX are the distorted data that results exactly in AproxY
 - DeltaX is the Backward Error (*Erro Inverso*)

# Numerical Instability vs Conditioning

 - A great forward error does not imply Numerical Instability
 - IF the algorithm is numerically stable |DeltaX| is small 
 - IF the problem is badly conditioned |DeltaY| > |DeltaX|

## Example of NI

f(x) = sqrt(x+1) - sqrt(x)

g(x) = 1 / (sqrt(x+1) + sqrt(x)) 

Note how f(x) has a subtraction that for x = 10^12 results in subtractive cancellation due to x+1 barely
differing from x. This results in a greater relative error that is NOT propagated by division.

If for example x was 10^16 then f(x) would have a Catastrophic Cancellation that cancels ALL significant digits (the result would be 0).
Again this does not happen in the equivalent division expression

Note that f(x) is well conditioned, however it is not backwards stable because of that subtrative cancellation.
Since g(x) is defined by an equivalent expression, it is well conditioned, and since subtractive cancellation does not occur,
it is Backwards Stable.

# Upper Bound of Truncation errors
```txt
f^(k+1)(theta) (x-a)^k+1
/ (k+1)!
```
# Notes on Taylor Series

Just some notes, pretty much trivial

# Taylor Series with x-a
asda

# Solving Non Linear Equations

x such that f(x) = 0

zeroes of f or roots of the equation

# Bissection method

f in med point m = (a+b) /2

f(m) = 0 then r = m
f(m) * f(a)< 0 then b = m
f(m) * f(a) > 0 then a = m 


