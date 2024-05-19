# Programando un DFA

#### Name:
- Remy Patgher Aguilar
- A01784177

## Descripción
Algoritmo programador en **Elixir** que recibe como argumento un string que contenga expresiones aritméticas y comentarios, este regresa una lista con cada uno de sus tokens encontrados, en el orden en que fueron encontrados e indicando de qué tipo son.

### Tipos de tokens
Las expresiones aritméticas sólo podrán contener los siguientes tipos de tokens:

- Enteros
- Flotantes (Reales)
- Exponenciales
- Operadores:
    - Asignación
    - Suma
    - Resta
    - Multiplicación
    - División
    - Potencia
- Identificadores:
- Variables
- Símbolos especiales:
    - (
    - )
- El caracter espacio
- Comentarios:
    - // seguido de caracteres hasta que se acabe el renglón

## ¿Cómo ejecutar el programa?
Se debe utilizar la función `arithmetic_lexer` del modulo `TokenList` a la cual se le debe pasar como argunto la expresión que se quiere evaluar.

#### Ejemplo:
Entrada:
```elixir
    TokenList.arithmetic_lexer("(12+14e-3)")
```
Salida:
```elixir
    [
        par_o: "(", 
        int: "12", 
        op: "+", 
        exp: "14e-3", 
        par_c: ")"
    ]
```
## Diagrama de Grafos
![alt text](<Screenshot 2024-05-19 at 12.48.45 a.m..png>)