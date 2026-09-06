# Literals
Literals are values inserted directly into the code. They are the value itself, before the variable is created.

```
return 5;                     // 5 is an integer literal
bool myNameIsAlex { true };   // true is a boolean literal
double d { 3.4 };             // 3.4 is a double literal
std::cout << "Hello, world!"; // "Hello, world!" is a C-style string literal
```

The type of the literal is deduced,  and by default:

Literal value |	Examples |	Default literal type |	Note
| --- | --- | --- | --- |	
integer value |	5, 0, -3 |	int	 |	
boolean value |	true, false	bool |		
floating point value |	1.2, 0.0, 3.4 |	double (not float!) |	
character |	‘a’, ‘\n’ |	char |	
C-style string | “Hello, world!” |	const char[14] | see C-style string literals section below

If the default type of the literal is not desired, you can change the type of the literal by adding asuffix, though in most cases these aren't needed. Some of then are:

Data type |	Suffix | Meaning
| --- | --- | --- |
integral | u or U | unsigned int
integral | l or L | long
integral | ul, uL, Ul, UL, lu, lU, Lu, LU | unsigned long
integral | ll or LL | long long
integral | ull, uLL, Ull, ULL, llu, llU, LLu, LLU | unsigned long long
integral | z or Z | The signed version of std::size_t (C++23)
integral | uz, uZ, Uz, UZ, zu, zU, Zu, ZU | std::size_t (C++23)
floating point | f or F | float
floating point | l or L | long double
string | s | std::string
string | sv | std::string_view

Most are not case sensitive except for ```s``` and ```sv``` which must be lower-case, and ```L``` is prefered over ```l``` to avoid confusions with 1.


**Integral literals**
Generally suffixes aren't needed. They can be used without any suffix even in non int type variables, since the compiler will take that literal value and transform it into the appropiate integer type.

**Floating point literals**
It is common to enforce them to be float, since by default they are long. Prevents warning from precision loss using float suffix to intialize float, because default is double: ```float x { 4.0f };```

**String literals**
String is collection of chars to represent text. Are placed between double quotes (") while chars are between quotes ('). 
Strings are not a fundamental type in cpp, rather they have the **C-style string** or **C string** type inheritated from C.
Two non obvious things about C style string literals:
1. **They have an implicit suffix char of null terminator ('\0')**, eg., "hello" = 'h' 'l' 'l' 'o' '\0'. Thus the type of "hello" is const char[6], not const char [5]. It exists due to historical reasons.
'\0' indicates end of the string. 
2. ==Unlike most other literals, which are values, **C-string style literals are const objects that are created at the start of the program and are guaranteed to exist for the entirety of the program**.== Unlike this, ```std::string``` and ```std::string_view``` literal create temporary objects which must be used inmidiatly, as they are destroyed at the end of full expression oin which they are created

**Magic number**
Is a literal (usually number) with unclear meaning or may need to be changed later, eg., ```const int maxStudentsPerSchool { numClassrooms * 30 };``` or ```setMax(30);```.
**THESE ARE DISCORAGED**, due to clean code, since they are usually literals used as parameters and are difficult to read or deduce type, only by the context, and thye can not be easily updated, eg., 
```
const int maxStudentsPerClass { 30 };
const int totalStudents{ numClassrooms * maxStudentsPerClass }; // now obvious what this 30 means

const int maxNameLength{ 30 };
setMax(maxNameLength); // now obvious this 30 is used in a different context
```
In object and simple contexts, such as incrementals or sequential integral ids, they can be used. 

