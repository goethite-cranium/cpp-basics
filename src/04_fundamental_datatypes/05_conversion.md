# Introduction to type conversion and static_cast

In many cases cpp allow us to convert values of one primitive type to another one. 

## Implicit type conversion
**Type conversion of a value produces a new object, and does not modify the original one**.
```const_cast``` or ```reinterpret_cast``` are exceptions and do not return temporary objects, but instead reinterpret the type of an existing value.

**Implicit type conversion**: compuler does type conversion without explicitly asking. For example, *char* -> *int* preserves the value. Or *int* -> *double* is safe because only "expands" the integer value.

**Unsafe implicit conversions**: In some cases, the compiler will throw a warning, for example when *double* -> *int*, because we would likely loose data. (eg, 5.5 -> 5).
When convert fractional number to int, the fractional part is lost.
WIth brace intialization unsafe implicit conversion will throw error, thus these are preferred:
```
double d { 5 }; // OK
int x { 5.5 }; // error: not safe impicit conversion
```

## Explicit type conversion
Prevents unsafe implicit conversion errors.
We tell the compuler to convert a value from one type to another and we take full resposability. 

In most cases, we use ```static_cast``` operator.
Syntax:
```
static_cast<new_type>(expression)
```

*std::int8_t* and *std::uint8_t* will likely behave as chars instead of integers.

### Unsigned and signed explicit type conversion
* Case 1: if value can be represented in the target type conversion, nothing strange happens
```
unsigned int u1 { 5 };
int s1 { static_cast<int>(u1) };

int s2 { 5 };
unsigned int u2 { static_cast<unsigned int>(s2) };
```

* Case 2: if value cannot be represented in the target type conversion spce, then
    * If destination is unsigned, value is **modulo wrapped** (``` u = s + mod(2^N)```), eg, with 8bit and s=-1, u=-1 mod2^8=find congruent value between 0 and  255 that is congruent to -1, which is 255.
    * If destination is signed, implementation-defined prior to cpp20, **modulo wrapped** from cpp20 (```s = u - 2^N```)

