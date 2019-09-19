# Trabalho 1

Uma determinada reação química produz uma quantidade c de CO2 medida em ppm (parte por milhão) dada pela equação polinomial:
>f(c) = a4c^4 + a3c^3 + a2c^2 + a1c + a0

Se ξ é uma raiz de f(x) = 0 com multiplicidade p, dados xo e ε, para cada passo o método de Newton-Raphson
é dado por:
>xk+1 = xk – (pf(xk) / f ’(xk)) (k = 0,1,2...).

De forma análoga pode-se introduzir um fator p no método da Secante para
raízes múltiplas, obtendo então:
>xk+1 = xk – (pf(xk)(xk – xk-1))/(f(xk) – f(xk-1)) (k = 0,1,2,...).

Desenvolva um sistema para calcular a
quantidade c de CO2 de uma determinada reação química dada. O sistema deve atender aos seguintes requisitos dados pelos itens abaixo:
1. Implementar algoritmo para calcular c pelo método de Newton para polinômios.
2. Implementar algoritmo para calcular c pelo método de Newton para multiplicidade.
3. Implementar algoritmo para calcular c pelo método da Secante para multiplicidade.
4. Calibrar o sistema usando como padrão a4=1, a3=-5, a2=6, a1=4, a0=-8, e p=3.
5. Fornecer um quadro resposta, com quantidade calculada para cada método dado.
6.  Fornecer um quadro comparativo, com todos os dados para cada método dado.
Dados de entrada: n (número de reações), ak (k=0 a 4) e p (para cada opção) e ε (precisão).
Dados de saída: quadros resposta (com c para cada reação e método) e comparativo