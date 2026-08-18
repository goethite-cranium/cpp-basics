# Boolean values and integers
true = 1
false = 0

If we use std::cin to input a boolean value, that must be in numeric form (0 or 1). If we type *true*, the std::cin will enter in failure mode, and silently drop the variable to false (0). If we want to type them in with text form, we need to activate std::boolalpha in the cin with ```std::cin >> std::boolalpha;```

