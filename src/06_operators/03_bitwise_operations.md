# Bitwise operations
In modern archs the min size of an obj is 1 byte.
Use 8bits for a single bool is a waste, but in not memory-constrained programs this is fine.
But for constrained-memory programs, we can "pack" 8 booleans in a single byte.
For this we require bit manipulation, alongside other uses.


### Basics
**Bit flags** are the bits from an object when they are viewed as indenpendent booleans.
0 bit is off, 1 bit is set or on, and when 1->0 or 0->1 is said it has been flipped or inverted.

**Define bit flags**: we typically use unsigned int of appropiate size (8, 16, 32, 64 bits depending
on how many flags we have), **or use ```std::bitset```:
```cpp
#include <bitset> // for std::bitset

std::bitset<8> myBitset {}; // 8 bits for max 8 flags
```
**Bit manioulations is the few cases where to use unsigned int unambiguosly**

**Bit positions** are the index of the bit from right to left:
```
76543210  Bit position
00000101  Bit sequence
```


### Bit manipulation with ```std::bitset```
```std::bitset``` has important methods for bit manipulation:
* ```.test()``` to query whether a bit is 0 or 1
* ```.set()``` to turn a bit on (nothing if already on)
* ```.reset()``` to turn a bit off (nothing if already off)
* ```.flip()``` to flip a value from 0 to 1 and viceversa
* ```.to_ulong()``` to convert it to ```unsigned long```
It is not easy to make these operations with more than 1bit simultanously.


### Size of a ```std::bitset```
```std::bitset``` is optimized in terms of speed, not in memory. 
This means, a bitset is typically the number of bytes needed to hold the bits rounded up to the
nearest ```sizeof(size_t)```, which is 4 bytes oon 32-bit machines and 8 bytes in 64-bit machines.
Thus, **```std::bitset``` is most useful when we desire convenience, not memory saving**.


### Insight methods from ```std::bitset```
* ```.size()``` returns the number of bits in the biset
* ```.count()``` returns the number of bits in the biset that are set to ```true```
* ```.all()``` returns a bool telling if all bits are set to ```true```
* ```.any()``` returns a boolean indicating whether any bits are set to ```true```
* ```.none()``` returns a boolean indicating whether not bits are set to ```true```


# Bitwise operators
| Operator    | Symbol | Form     | Assignment form | Description                                                               |
| ----------- | ------ | -------- | --------------- | ------------------------------------------------------------------------- |
| left shift  | `<<`   | `x << n` | `x <<= n`       | The bits from `x` are shifted left by `n` positions; new bits are `0`.    |
| right shift | `>>`   | `x >> n` | `x >>= n`       | The bits from `x` are shifted right by `n` positions; new bits are `0`.   |
| bitwise NOT | `~`    | `~x`     | —               | Each bit from `x` is flipped.                                             |
| bitwise AND | `&`    | `x & y`  | `x &= y`        | Each bit is set when both corresponding bits in `x` and `y` are `1`.      |
| bitwise OR  | `\|`   | `x \| y` | `x \|= y`       | Each bit is set when either corresponding bit in `x` and `y` is `1`.      |
| bitwise XOR | `^`    | `x ^ y`  | `x ^= y`        | Each bit is set when the corresponding bits in `x` and `y` are different. |

**There are assignment equivalient operators**

**Bitwise operators are defined for integral types and ```std::bitset```.**
**Avoid using signed integral type since bitwise operators are compile-defined prior to cpp20**

**Initializing or assigning the result to a variable of the smaller integral type is a narrowing conversion (since converting an int or unsigned int to a smaller integral type may result in data loss)**

```cpp
std::uint8_t c { 0b00001111 };

std::cout << std::bitset<32>(~c) << '\n';     // incorrect: prints 11111111111111111111111111110000
std::cout << std::bitset<32>(c << 6) << '\n'; // incorrect: prints 0000000000000000001111000000
std::uint8_t cneg { ~c };                     // error: narrowing conversion from unsigned int to std::uint8_t
c = ~c;                                       // possible warning: narrowing conversion from unsigned int to std::uint8_t
```

If the operand(s) of a bitwise operator are an integral type smaller than an int, those operands will be promoted (converted) to int or unsigned int, and the result returned will also be an int or unsigned int. For example, if our operands are unsigned short, they will be promoted (converted) to unsigned int, and the result of the operation will be returned as an unsigned int.

### ```operator<<``` and ```operator>>```
```
0011 << 1 is 0110
0011 << 2 is 1100
0011 << 3 is 1000

1100 >> 1 is 0110
1100 >> 2 is 0011
1100 >> 3 is 0001
```
Are same operators as the ones used in ```std::cout``` and ```std::cin```, but overloaded with other behavior based
on the operands' types with stream objects.

**operator~ and operator<< are width-sensitive and may produce different results depending on the width of the operand**

### ```operator~```
```
~0011 is 1100
~0000 0011 is 1111 1100
```
Note that, when interpreted as integers, before being flipped they where the same number. After flipped, they are
completly different because of their uint length (4 bits and 8bits respectively).
**OPERATOR~ PROMOTES OPERAND TO INT, SO DEPENDING ON THE ORIGINAL WIDHT,IF YOU TRY TO OPERATE AGAINST THEM, THE COMPAILER CAN WARN**
example:
```cpp
[[maybe_unused]] constexpr std::uint8_t mask2{ 0b0000'0100 }; // represents bit 2
std::uint8_t flags{ 0b0000'0101 };

flags &= ~mask2; // turn off bit 2 MAYBE WARN because promote mask2 to int, which can be 4 bytes
```
better use:
```cpp
flags &= static_cast<std::uitn8_t>(~mask2);
```

### ```operator|```, ```operator&``` and ```operator^```
```
bitwise OR
0101 | 0110 is 0111

bitwise AND
0101 & 0110 is 0100

bitwise XOR
0110 ^ 0011 is 0101
```

# Bit manipulation with bitwise operators and bit masks
**Bitwise operators work with masks, not numbers, to identify bit positions.**
We use 0s to mask out the bits we dont care about, and 1s to denote bits we want modified.
**Masks are often symbolic constants, but they can also be literals**
```cpp
constexpr std::uint8_t mask0{ 0b0000'0001 }; // bit 0
```
Here ```maskn``` represents mask of bit in position n (eg., ```constexpr std::uint8_t mask2 { 0b0000'0100 };```)
and ```flags``` represts the bit set of flags or booleans set
* Test bit in position n: ```flags & maskn;```
* Set a bit (turn on) in position n: ```flags |= maskn;```
* Set multiple bits: ```flags |= (maskn1 | maskn2);```
* Reset a bit (turn off) in position n: ```flags &= ~maskn;``` or ```flags &= static_cast<std::uint8_t(~maskn)>;```
* Reset multiple bits: ```flags &= ~(maskn1 | maskn2);```
* Flip a bit in position n: ```flags ^= maskn```
* Flip multiple bits: ```flags ^= (maskn1 | maskn2);```

```std::bitset``` is also candidate to use masking for multiple bit set, reset and flipping, though it has individual bit member function operators.

Also, masks should be meaningful, for example:
```cpp
        // Define a bunch of physical/emotional states
	[[maybe_unused]] constexpr std::uint8_t isHungry   { 1 << 0 }; // 0000 0001
	[[maybe_unused]] constexpr std::uint8_t isSad      { 1 << 1 }; // 0000 0010
	[[maybe_unused]] constexpr std::uint8_t isMad      { 1 << 2 }; // 0000 0100
	[[maybe_unused]] constexpr std::uint8_t isHappy    { 1 << 3 }; // 0000 1000
	[[maybe_unused]] constexpr std::uint8_t isLaughing { 1 << 4 }; // 0001 0000
	[[maybe_unused]] constexpr std::uint8_t isAsleep   { 1 << 5 }; // 0010 0000
	[[maybe_unused]] constexpr std::uint8_t isDead     { 1 << 6 }; // 0100 0000
	[[maybe_unused]] constexpr std::uint8_t isCrying   { 1 << 7 }; // 1000 0000

	std::uint8_t me{}; // all flags/options turned off to start
	me |= (isHappy | isLaughing); // I am happy and laughing
	me &= ~isLaughing; // I am no longer laughing

	// Query a few states
	// (we'll use static_cast<bool> to interpret the results as a boolean value)
	std::cout << std::boolalpha; // print true or false instead of 1 or 0
	std::cout << "I am happy? " << static_cast<bool>(me & isHappy) << '\n';
	std::cout << "I am laughing? " << static_cast<bool>(me & isLaughing) << '\n';
```

**Bit flags are useful when**:
* Many identical booleans in each object. Each object with the same set of booleans can be expressed as a single particular
bitset or uint, while masks are applied to every object with same set, then reducing substantially the memory.
* **When a function has many bool options or states as arguments**. If bools where used, the amount of arguments make it way messy,
so it is better to use flags in a single variable to represent all those options.
* **Masking colors in pixels or arrays in graphic tools such as opencv**. For example, making full transparente something, 
erasing red part, etc.

example: ask the uset to enter 32-bit hexacecimal value, and then extracts the 8-bit color values for R G B A
```cpp
#include <cstdint>
#include <iostream>

int main()
{
	constexpr std::uint32_t redBits{ 0xFF000000 };
	constexpr std::uint32_t greenBits{ 0x00FF0000 };
	constexpr std::uint32_t blueBits{ 0x0000FF00 };
	constexpr std::uint32_t alphaBits{ 0x000000FF };

	std::cout << "Enter a 32-bit RGBA color value in hexadecimal (e.g. FF7F3300): ";
	std::uint32_t pixel{};
	std::cin >> std::hex >> pixel; // std::hex allows us to read in a hex value

	// use Bitwise AND to isolate the pixels for our given color,
	// then right shift the value into the lower 8 bits
	const std::uint8_t red{ static_cast<std::uint8_t>((pixel & redBits) >> 24) };
	const std::uint8_t green{ static_cast<std::uint8_t>((pixel & greenBits) >> 16) };
	const std::uint8_t blue{ static_cast<std::uint8_t>((pixel & blueBits) >> 8) };
	const std::uint8_t alpha{ static_cast<std::uint8_t>(pixel & alphaBits) };

	std::cout << "Your color contains:\n";
	std::cout << std::hex; // print the following values in hex

        // reminder: std::uint8_t will likely print as a char
        // we static_cast to int to ensure it prints as an integer
	std::cout << static_cast<int>(red)   << " red\n";
	std::cout << static_cast<int>(green) << " green\n";
	std::cout << static_cast<int>(blue)  << " blue\n";
	std::cout << static_cast<int>(alpha) << " alpha\n";

	return 0;
}
```