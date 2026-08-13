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
* Integral types *char*, *long*, *int*, *long* and *long long* have min size of 8, 16, 16, 32 and 64 respectivey.
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

# Signed Integers
Sign is the positive/negative sign. Sigend integers hold negative and positive values.
All types integral types (*short*, *int*, etc) are signed by default. Keyword ```signed``` can be use to make it explicitely, though it is not recommended (```signed long sl;```).

**Range**: possible span of values a type can hold. For example, signed 8-bit has -128 to 127. (n-bit signed spans from -(2^(n-1)) to 2^(n-1)-1 ). 

**Overflow**: number is cannot be represent with the bits of the type. It results on undefined behavior.