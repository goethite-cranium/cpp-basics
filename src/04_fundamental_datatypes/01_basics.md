# Fundamental data types
Same as **primitive tyes** or **basic types**.

| Types | Category | Meaning |
| -------- | -------- | -------- |
| float | Floating Point | a number with a fractional part |
| double |  |  |
| long double |  |  |
| bool | Integral (Boolean) | true or false |
| char | Integral (Character) | a single character of text |
| wchar_t |  |  |
| char8_t (C++20) |  |  |
| char16_t (C++11) |  |  |
| char32_t (C++11) |  |  |
| short int | Integral (Integer) | positive and negative whole numbers, including 0 |
| int |  |  |
| long int |  |  |
| long long int (C++11) |  |  |
| std::nullptr_t (C++11) | Null Pointer | a null pointer |
| void | Void | no type |


* Standard integer types: *short*, *int*, *long*, *long long* and their signed and unsigned variants. Non-fundamental types (*enum*, *enum class*) are not integer types, since they are not fundamental.
* Integral types (like an integer): *bool*, the various char types, and the standard integer types.

Integral are stored in memmory as *integral types*, but only *integer types* will display as an integer when output.

**_t** suffix, such in ```std::nullptr_t```, means "type".


# Sizeof and object size
* An object must occupy at least 1 byte (at least 8 bits)
* Integral types *char*, *short*, *int*, *long* and *long long* have min size of 8, 16, 16, 32 and 64 bits respectivey.
* *char* and *char8_t* are exactly 1 byte

Assuming 1 byte is 8 bits, 32-bit or 64-bit architectures:

| Category       | Type        | Min size | Typical size |
| --------       | --------    | -------- | -------- |
| Boolean        | bool        | 1 byte   | 1 byte |
| Character      | char        | 1 byte (exactly) | 1 byte |
|                | wchar_t     | 1 byte   | 2 or 4 bytes |
|                | char8_t     | 1 byte   | 1 byte |
|                | char16_t    | 2 bytes  | 2 bytes |
|                | char32_t    | 4 bytes  | 4 bytes |
| Integral       | short       | 2 bytes  | 2 bytes |
|                | int         | 2 bytes  | 4 bytes |
|                | long        | 4 bytes  | 4 or 8 bytes |
|                | long long   | 8 bytes  | 8 bytes |
| Floating point | float       | 4 bytes  | 4 bytes |
|                | double      | 8 bytes  | 8 bytes |
|                | long double | 8 bytes  | 8, 12, or 16 bytes |
| Pointer        | std::nullptr_t | 4 bytes | 4 or 8 bytes |

==For max portability, shouldn't assume objects larger than specified min size.== 
Alternatively, if it is assumed non-min size of a type, use ```static_assert``` to have the compiler fail a build if the architecture does not use that assumption.

Smaller data types might not always be the faster options. CPUs are often optimized to process data of a certain size (eg 32 bits), so types that match that size may be processed quicker (eg 8-bit or 16-bit).

```sizeof()``` function returns the size in bytes of the object. The return type is a ```std::size_t``` type (*typedef*), which is an alias of uint with width decided by compiler.  

# Signed Integers
Sign is the positive/negative sign. Sigend integers hold negative and positive values.
All types integral types (*short*, *int*, etc) are signed by default. Keyword ```signed``` can be use to make it explicitely, though it is not recommended (```signed long sl;```).

**Range**: possible span of values a type can hold. For example, signed 8-bit has -128 to 127. (n-bit signed spans from -(2^(n-1)) to 2^(n-1)-1 ). 

**Overflow**: number is cannot be represent with the bits of the type. It results on undefined behavior.
It is undefined behaviour. In signed ints, normally the number is wrapped (if max int4 is 7, then 8 would become in -8), but as it is undefined what it might happen depends on the machine.

**Division**: the fractional part is dropped.

# Unsigned Integers
Use keyword to define them:
```
unsigned short us;
unsigned int ui;
unsigned long ul;
unsigned long long ull;
```

**Range**: from 0 to 2^n-1

**Overflow**: it won't wrap. If overlowed, it is devided by one greater than the largest number of the datatype and only the reminder kept (**Modulo wrapped**).
Example:
280 in 8bit uint (0-255) will be represented as the reminder of 280/256, thus 24.
==Unsigned ints are discoraged due to their are more easily overflow in the bottom than the top, unlike signed which are eq likely, and because negative signed ints can be silently converted to unsigned expected parameters in functions producing the overflowing silently, which is hard to prevent.==

Use uints when:
* nums when dealing bit manipulation or well defined wrap around behavior is required (encryption and random gen)
* Unavoidable cases (array indexing)
* Processor/memory limited contexts


# Fixed-width (cpp11+) integers and size_t
Integer types are the only ones with min size guarantee, but they could be larger depending on the system.

**Why we could needfixed-width ints?** 
* If we assume an *int* is 32-bits, but the program runs in a machine where int is 16-bit, numbers can overflow. 
* If we assume an *int* is 16-bits, but the program runs in a machine where int is 32-bit, 2 memory bytes are wasted. Specially important if the allocation is of millions of numbers that are persistant.

Fixed-width integers are guarantee to have the same size in all systems:


| Name | Fixed Size | Fixed Range | Notes |
| ------ | ------ | ------ | ------ |
| std::int8_t   | 1 byte signed | -128 to 127 | Treated like a signed char on many systems.  |
| std::uint8_t   | 1 byte unsigned | 0 to 255 | Treated like a usigned char on many systems.  |
| std::int16_t  | 2 byte signed | -32,768 to 32,767 |  |
| std::uint16_t | 2 byte unsigned | 0 to 65,535 |  |
| std::int32_t  | 4 byte signed | 	-2,147,483,648 to 2,147,483,647 |  |
| std::uint32_t | 4 byte unsigned | 0 to 4,294,967,295 |  |
| std::int64_t  | 8 byte signed | -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807 |  |
| std::uint64_t | 8 byte unsigned | 0 to 18,446,744,073,709,551,615 |  |

==**Warning**==: ```std::int8_t``` and ```std::uint8_t``` typically behave like chars (same as ```unsigned char``` and ```signed char```) in modern systems.

Downsides:
* Not all systems are guaranteed to have defined all fixed-size integers (fail to compile)
* Might be slower than other wider types on some architectures

These has a solution: fast guaranteed existant integers collection of *<cstdint>*. Chooses the existant signed or unsigned integer that runs faster with the minimum width told:
```std::int_fast8_t```, ```std::uint_fast8_t```, etc.
Although they have downsides:
* They might be bigger than needed, wating memory resorces
* Programs might produce diferent results if they choose different sizes on different machhines.

==Avoid least and fast integral types==


---
#### Consensus: 
* Prefer int when the size of the integer doesn’t matter (e.g. the number will always fit within the range of a 2-byte signed integer). For example, if you’re asking the user to enter their age, or counting from 1 to 10, it doesn’t matter whether int is 16-bits or 32-bits (the numbers will fit either way). This will cover the vast majority of the cases you’re likely to run across.
* Prefer std::int#_t when storing a quantity that needs a guaranteed range.
* Prefer std::uint#_t when doing bit manipulation or well-defined wrap-around behavior is required (e.g. for cryptography or random number generation).

Avoid the following:
* short and long integers (prefer a fixed-width integer type instead).
* The fast and least integral types (prefer a fixed-width integer type instead).
* Unsigned types for holding quantities (prefer a signed integer type instead).
* The 8-bit fixed-width integer types (prefer a 16-bit fixed-width integer type instead).
* Any compiler-specific fixed-width integers (for example, Visual Studio defines __int8, __int16, etc…)
---


# Scientific notation
**Type double (long)**. 
Write as *significant x 10^exponent* (3.14e0).
If the precision of the number is of three digits, but that part is zero for a reason, then we need to mark it as relevant with **trailing zeros** (just as clearance, since it has no mathematical repercusion):
87.0=8.70e1 (relevan until first digit)
87.000g=8.7000e1 (relevant until third digit)

**Float type can be forced with f suffix** (3.14f or 3.14e0f)
**Long double can be forced with L suffix** (3.14L)


# Floating point numbers
Store numbers with fractional component. 
Always signed.
Types can be 
* *float*: single precision (normally 4 bytes)
6-9 significant digits.
* *double*: double precision (normally 8 bytes)
15-18 significant digits.
* *long double*: extended precision (not convenetion, avoid it)

Alwais introduce decimal parts during floating point var creation:
```
int a { 5 };
float b { 5.0f };
double c { 5.0 };
```

The floating points have a gigantic range, BUT the greater the number the less the precision. Since we have the 6 digits guarantee for float, 5.0e5f will be precisely depicted, but 5.0e6f will lost the control on the last digit, in 5.07f the two last digits, and that can be applied to all numbers in terms of digits.
For decimal values, it is only limited by the exponent size, so we represent infinitesimal number without lost precision if the relevant digits are less than 7.

Also since the number is represented as power of 2, then the decimal part can have lacky of precision. 0.5=1/2=2⁻1, or 0.25=1/4=2^-2, but 0.1=1/10 so it is periodic in base 2, then that number is not going to be represented precisely.

The rounding error makes comparison tricky, for example 1.0 is not the same as 10*0.1. **THIS IS THE NORM**. **NEVER ASSUME THE FLOATING POINT NUMBERS ARE EXACT**.


# NaN and Inf
* Inf can be +Inf or -Inf
* Handling for signed 0
Avoid division by 0.0 even if compiler supports it