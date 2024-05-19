# Context-free grammars

Name: Remy Patgher Aguilar

## Grammar definitions

Describe the basic grammar necessary to write a valid *construction* in the language indicated.

The contents of the *construction* do not need to be specified.

Consider all the requirements for the construction according to the language. For example, the rules for the names of the constructions

### BNF Python functions

```xml
<function> ::= <standard-function> | <lambda-function> | <decorated-function>

<standard-function> ::= def <identifier> ( <parameters> ): \n \t <expressions>

<lambda-function> ::= lambda <parameters> : <expression>

<decorated-function> ::= <decorator-list> <standard-function>

<decorator-list> ::= <decorator> | <decorator> <decorator-list>

<decorator> ::= @ <identifier> <parameters> \n

<parameters> ::= <parameter> | <parameter> , <parameters> | <lambda>

<parameter> ::= <identifier> | <identifier> = <expression>

<expressions> ::= <expression> | <expression> <expressions>

<identifier> ::= <letter> | <identifier> <letter> | <identifier> <digit> | <identifier> _

<letter> ::= a | ... | z | A | ... | Z

<digit> ::= 0 | ... | 9
```

### EBNF Python functions

```bash
FUNCTION ::= ( STANDARD-FUNCTION | LAMBDA-FUNCTION | DECORATED-FUNCTION )

STANDARD-FUNCTION ::= "def" IDENTIFIER "(" {PARAMETER} ")" ":" "\n" "\t" {EXPRESSION}

LAMBDA-FUNCTION ::= "lambda" {PARAMETER} : EXPRESSION

DECORATED-FUNCTION ::= {DECORATOR}

DECORATOR ::= "@" IDENTIFIER {PARAMETER} "\n"

PARAMETER ::= IDENTIFIER ["=" EXPRESSION]

IDENTIFIER ::= {LETTER} [{DIGIT}] [{"_"}]

LETTER ::= "a" | ... | "z" | "A" | ... | "Z"

DIGIT ::= "0" | ... | "9"
```

### BNF Elixir modules

```xml
<module> ::= defmodule <identifier-module> do <module-body> end

<module-body> ::= <function> | <function> <module-body>

<expressions> ::= <expression> | <expression> <expressions>

<identifier-module> ::= <upper-letter> | <identifier-module> <letter> | <identifier-module> <digit> | <identifier> _

<upper-letter> ::= A | ... | Z

<letter> ::= a | ... | z | A | ... | Z

<digit> ::= 0 | ... | 9
```

### EBNF Elixir modules

```bash
MODULE ::= "defmodule" IDENTIFIER-MODULE "do" {FUNCTION} "end"

IDENTIFIER-MODULE ::= {UPPER-LETTER} [{LETTER}] [{DIGIT}] [{"_"}]

UPPER-LETTER ::= "A" | ... | "Z"

LETTER ::= "a" | ... | "z" | "A" | ... | "Z"

DIGIT ::= "0" | ... | "9"
```

### BNF Elixir functions

```xml
<function> ::= <visibility> <identifier> ( <parameters> ) do <expressions> end |  <visibility> <identifier> ( <parameters> ), do: <expressions> | <visibility> <identifier> ( <parameters> ) when <condition>, do: <expressions>

<visibility> ::= def | defp

<parameters> ::= <parameter> | <parameter> , <parameters> | <lambda>

<parameter> ::= <identifier> | <identifier> = <expression>

<identifier> ::= <letter> | <identifier> <letter> | <identifier> <digit> | <identifier> _

<letter> ::= a | ... | z | A | ... | Z

<digit> ::= 0 | ... | 9
```

### EBNF Elixir functions

```bash
FUNCTION ::= VISIBILITY IDENTIFIER "(" {PARAMETER} ")" ("do" {EXPRESION} "end" | ["when" CONDITION] "," "do" EXPRESION)

VISIBILITY ::= ("def" | "defp")

PARAMETER ::= IDENTIFIER ["=" EXPRESSION]

IDENTIFIER ::= {LETTER} [{DIGIT}] [{"_"}]

LETTER ::= "a" | ... | "z" | "A" | ... | "Z"

DIGIT ::= "0" | ... | "9"
```