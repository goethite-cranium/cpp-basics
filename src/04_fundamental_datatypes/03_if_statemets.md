# Basic Statements

Conditions are expressions that evaluates to boolean value.
==If they are not evaluated to boolean, then they are implicetly dropped to it, where non-zero values get converted to *true*, and zero-values get converted to *false*.== 

1. Simple if
```
if (condition) true_statement;
```
or
```
if (condition)
    true_statement;
```
or 
```
if (condition)
{
    true_statements;
}
```

2. If-else
```
if (condition)
    true_statement;
else
    false_statement;
```
or
```
if (condition)
{
    true_statement;
}
else
{
    false_statement;
}
```

3. Chainig if statements
```
if (condition)
{
    true_statements;
}
else if (condition)
{
    true_stements;
}
...
else
{
    false_statements;
}
```

4. Ternary operator
```
condition ? expression_if_true : expression_if_false;
```


### Early returns
Use early returns to avoid execute the rest of the code
```
if (condition)
{
    true_statements;
}
else if (condition)
{
    true_stements;
    return;
}
...
else
{
    false_statements;
}
```