# Evidencia: Resaltador de Sintaxis de C++ en Elixir

#### Name:
- Remy Patgher Aguilar
- A01784177

## Descripción
Programa resaltador de sintáxis del lenguaje de programación C++ hecho en elixir con programación funcional. El programa recibe como entrada la referencia de un archivo de texto con formato cpp (ejemplo.cpp), procesa el texto identifica los diferentes tipos de tokens de dicho lenguaje y posteriormente lo convierte a HTML con etiquetas span y clases del tipo de token identificado, los escibre en un archivo para que, de esta forma, se muestre del color correspondiente en el HTML.

### Tipos de tokens
- Palabras Reservadas (if, else, for, etc)
- Comentarios (// Hola mundo)
- Null
- String ("Hola mundo")
- Especificadores (\<iostream>)
- Operadores (+, -, *)
- Números
- Funciones (read_file())
- Identificadores
- Caractéres ('p')
- Delimitadores ({})
- Directivas (#)
- Espacios

## ¿Cómo ejecutar el programa?
Para ejecutar el programa se debe utilizar el compilador de elixir en la terminal, pasando como primer parámetro el archivo de elixir ejecutable y como segundo parámetro la ruta del archivo de C++ que se busca procesar.

#### Ejemplo:
```bash
elixir lexer_cpp.exs file/linked_list.cpp
```

## Descripción técnica general del programa
El programa cuenta con 9 funciones:
- __read_file__: Esta función recibe como parámetros el nombre del archivo de entrada y el de salida. Sirve básicamente para abrir el archivo del código a procesar, así como el archivo donde se va a escribir el HTML. Una vez que lee el archivo de C++, procede a pasar línea por línea a la función *validate_line*.

- __validate_line__: Esta función recibe cada línea a procesar, así como el archivo donde va a escribir todo (esto para pasar la referencia del archivo para cuando se necesite escribir la línea procesada). Esta función genera las regex y las pasa a otra llamada *process_line* para que dicha función itere recursivamente las regex y detecte los diferentes tipos de tokens en cada línea.

- __process_line__: Está función busca coincidencias de las regex y si encuentra una en el medio, parte la línea y cada parte la vuelve a procesar (conviertíendola a HTML) por separado (recursivamente). Finalmente cuando, ya no queda más por procesar, procede a concatenar cada token ya formateado para general una nueva línea pero convertida a HTML.

- __split_at_match__: Esta función recibe una cadena (una línea o parte de una línea) y la parte devolviendo la parte anterior a la coincidencia y la parte posterior.

- __white_line__: Esta función recibe cada línea y la escribe en el archivo de HTML ya formateada.

- __to_html__: Esta función recibe tipo de token y un token, y lo covierte a HTML con su respectiva clase (tipo de token).

- __write_head__: Esta función simplemente esribe el head HTML en su archivo para que el archivo final pueda mostar un HTML con el código estilizado.

- __write_foot__: Esta función simplemente esribe el foot HTML en su archivo para que el archivo final pueda mostar un HTML con el código estilizado.

- __measure__: Finalmente, esta función ejecuta todo el programa, pero guardando registro del tiempo que tarda en ejecurtarse.

## Complejidad
El programa tiene una complejidad potencialmente alta debido a su uso intensivo de expresiones regulares y recursividad en __process_text__. Esto puede llevar a tiempos de ejecución elevados, especialmente con archivos grandes y/o con muchas coincidencias para las expresiones regulares.

Para la función __read_file__, la complejidad es _O(n)_.

Para la función __validate_line__, cada expresión regular se ejecuta sobre la línea, cuya longitud promedio es l. El peor caso de una expresión regular es 𝑂(𝑙<sup>2</sup>), aunque muchas veces puede ser 𝑂(𝑙) dependiendo de la complejidad de la expresión.

Finalmente, para la función __process_text__, por cada llamada, podría potencialmente revisar todas las m expresiones regulares. Por lo tanto, la complejidad en el peor caso aquí es 𝑂(𝑙×𝑚×𝑙) O(l×m×l)=O(m×l<sup>2</sup>).