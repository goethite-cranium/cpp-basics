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