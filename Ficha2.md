# Ex1
 - pi   = 3.14 or 3.1416
 - 1/3  = 0.333 or 0.33333
 - 1/11 = 0.0909 or 0.090909
 - etc

# Ex2

- z = [(x+y)^2 - x^2 - 2xy] / y^2

para valores de x = 100 e y = 10^-k, para k = 0,1,...,10
Explique os erros nos resultados para os valores de k maiores.


Usando o script 
```m
x = 100; for k=0:10, y=10^(-k); z=((x+y)^2-x^2-2*x*y)
```

ocorre cancelamento subtrativo na ordem dos 6 algarismos significativos para k = 1

na medida que aumentamos o k, diminuimos o valor de y, resultando numa perda substancial de algarismos
significativos, ou seja, cancelamento subtrativo, sendo que temos uma basta diferenca em ordens de grandeza
dos operandos.

# Ex3

Sucessao de termo (1+(1/n))^n monotona crescent e convergente
O limite e o numero de nepper (numero de euler)

```m
S = inline('(1+1/n)^n')
n = 2^52; n = 2^53
```
O que reparamos e que S(2^52) resulta num valor muito proximo do numero de nepper (conforme se previa)
No entanto, quando fazemos S(2^53) temos um resultado de 1, isto ocorre devido ao epsilon e ao facto de 2^53 nao
ter representacao em F, perdendo, por isso, bits significativos.
fl(1+2^-53) = 1

## Ex3 (Extra)

P(x) = x^n

Qual e o numero de condicao relativa de P(x)?

o erro relativo incrementa em fatores de n

# Ex4

```
lim n->inf(100^n/n!)
``` 
This is done recursively
