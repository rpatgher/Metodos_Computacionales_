# Programación paralela y concurrente

#### Name:
- Remy Patgher Aguilar
- A01784177

## Descripción
Programa en **Elixir** que calcula la suma de todos los números primos menores al número que se le pase como entrada. La suma la calcula haciendo un recorrido desde el 1 hasta el número máximo y por cada número, evalúa si es primo con el siguiente algorimo:


1. Si $n$ es menor que 2, el algoritmo termina devolviendo falso.
2. Para $i$ desde $2$ hasta $⌈\sqrt{n}⌉$, realiza lo siguiente:
    - El algoritmo termina devolviendo falso si $n$ es divisible entre $i$ de manera exacta, de otra se repite el ciclo con el siguiente valor de $i$.
3. El algoritmo termina devolviendo verdadero si el ciclo del punto anterior conluyó de manera normal.

Luego, cuando obtiene todos los números primos, procede a sumarlos e imprimir el valor de la suma total.
Para la versión paralela, hace los mismo, pero, en lugar de hacerlo desde el 1 hasta el número máximo, divide todos los números que hay entre el 1 y el máximo en $p$ rangos (siendo $p$ el número de núcleos de la computadora que está ejecutando el programa) y hace la suma de los primos en cada uno de los rangos, para después sumar ese subtotal de cada rango y finalmente obtener el total del rango principal.

## ¿Cómo ejecutar el programa?
Hay dos funciones principales que puede correr el programa de forma adecuada. La función `get_sum_primes` recibe como parámetros el número máximo, del cual se calculará la suma de los números primos menores a él; como segundo parámetro se pasa true si se quiere llevar a cabo el cálculo de manera secuencial o de manera paralela. Por otro lado, está la función `get_sum_primes_speedup` que recibe únicamente el número máximo y lleva a cabo la suma de los primos de ambas maneras, registrando el tiempo de ejecución de ambas formas y posteriormente hace el cálculo del _speedup_ con la siguiente fórmula:

$S_p = \dfrac{T_1}{T_p}$

En donde:
- $p$ es el número de procesadores (o núcleos).
- $T_1$ es el tiempo que tarda en ejecutarse la versión secuencial del programa.
- $T_p$ es el tiempo que tarda en ejecutarse la versión paralela del programa utilizando $p$ procesadores.
- $S_p$ es el _speedup_ obtenido usando $p$ procesadores.


#### Ejemplo:
Entrada:
```elixir
    Hw.Primes.get_sum_primes_speedup(5_000_000)
```

Salida:
```bash
    The sum of primes between 1 and 5000000 is 838596693108
    The total sum of primes is 838596693108
    Cores: 4
    The sum of primes between 1 and 1250000 is 57759511224
    The sum of primes between 1250001 and 2500000 is 161938196971
    The sum of primes between 2500001 and 3750000 is 261145787535
    The sum of primes between 3750001 and 5000000 is 357753197378
    The total sum of primes is 838596693108
    Time sequential: 35.884034 seconds
    Time parallel: 26.974358 seconds
    Speedup: 1.3303016887371333
```