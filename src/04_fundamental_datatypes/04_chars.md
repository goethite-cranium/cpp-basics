*char* data type holds a single character (letter, num, symbol or whitespace).

Is integral, thus is stored as an integer interpreted as ASCII character (from 0-127).

# Initialize chars
1. Using character literals (preferred):
```cpp
char ch2 { 'a' };
```

2. Using integer (the char integer value)
```cpp
char ch1 { 97 }; // char 'a' 
```

Initialization with double quotes ("a") are treated as C-style strings, which is different from chars.
Avoid multicharacter literals such  as ```'ab'``` or ```'54'```;

# std::cin and char
Std::cin let you introduce multiple chars, but with char value only the first will be stored.

# Relevant symnbols
Name | Symbol | Meaning
| ----- | ----- | 
Alert | \a | Makes an alert, such as a beep
Backspace | \b | Moves the cursor back one space
Formfeed | \f | Moves the cursor to next logical page
Newline | \n | Moves cursor to next line
Carriage return | \r | Moves cursor to beginning of line
Horizontal tab | \t | Prints a horizontal tab
Vertical tab | \v | Prints a vertical tab
Single quote | \’ | Prints a single quote
Double quote | \” | Prints a double quote
Backslash | \\ | Prints a backslash.
Question mark | \? | Prints a question mark.
No longer relevant. You can use question marks unescaped.
Octal number | \(number) | Translates into char represented by octal
Hex number | \x(number) | Translates into char represented by hex number

