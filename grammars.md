# Context Free Grammars

## Syntax of `for` strcture in C

Example:
```c
for(int i = 0; i < 0; i++){
    ...
}

for(;;)
    printf("Cool!");
```

BNF:
```xml
<for> ::= 
    for (<init>; <cond>; <update>) 
        <exp> 
    | for (<init>; <cond>; <update>) {
         <expx> 
    }

<init> ::= <dataType> <var> = <value> | <var> = <value> | <lambda>

<cond> ::= 
    <exp> 
    | <lamnda>

<update> ::= 
    <var><update-op> 
    | <update-op><var>

<update-op> ::= ++ | --

<exps> ::= <exp> | <exp><exps>
```

EBNF: 
```bash
FOR ::= for '(' INIT ';' COND ';' UPDATE ')' ( EXP | '{' EXPS '}' )

INIT ::= DATATYPE VAR '=' VALUE
```


## Syntax of `if/elif/else` strcture in C

Examples:
```python
if true:
    print("Hello World")
else:
    print("Nothing")

if a < b: 
    a++
    b++
    c++

if a > 20:
    print("large")
elif a > 5:
    print("medium")
elif a > 5:
    print("small")
else:
    print("none")
```

BNF:
```xml
<cond> ::= <if> | <if><else> | <if><elifs> | <if><elifs><else>

<if> :: = if <exp>: \n \t<exps>

<elifs> ::= <elif> | <elif><elifs>

<elif> ::= elif <exp>: \n \t <exps>

<else> ::= else: \n \t <exps>

<exps> ::= <exp> | <exp><exps>
```

EBNF:
```bash
COND ::= IF [{ELIF}] [ELSE]

IF :: = 'if' EXP ':' '\n' '\t' {EXP}

ELIF ::= 'elif' EXP ':' '\n' '\t' {EXP}

ELSE ::= 'else:' '\n' '\t' {EXP}
```