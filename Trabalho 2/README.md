# Trabalho 2 - Sistemas de Equações

Uma determinada reação química produz uma quantidade c de CO2 medida em ppm (parte por milhão) que pode variar dependendo das condições ambientais.
Nesse caso, podem-se ter quantidades c1, c2,..., cn diferentes. Essas quantidades podem ser calculadas a partir da solução de um sistema de equações lineares Ac = d por **fatoração LU** da matriz A diretamente, usando a definição de produto de matrizes.
Esquemas desse tipo são conhecidos como compactos, e o equivalente à fatoração A=LU com L triangular inferior com diagonal unitária e U triangular superior é chamado de **redução de Doolittle**.

O processo é baseado em alguns passos:
1. primeiro multiplica-se a primeira linha de L pela j-ésima coluna de U e iguala-se a a1j, obtendo-se os elementos u1j;
1. depois multiplica-se a i-ésima linha de L pela primeira coluna de U, igualando-se a ai1 de onde se obtém os elementos li1;
1. repete-se o processo para as demais linhas e colunas até se obter os demais elementos de L e U.

Desenvolva um sistema para calcular todos as quantidades desejadas com requisitos dados a seguir:
1. Implementar algoritmo para calcular {c} pela fatoração LU, usando a pivotação;
1. Implementar algoritmo para calcular {c} pela redução de Doolittle, sem pivotação;
1. Calibrar sistema feito usando como padrão a matriz [A] e o vetor {d} dados abaixo;
1. Fornecer quadro resposta para cada método, variando os valores de [A] e os de {d}.

![Matriz e Vetor](https://github.com/navarrotheus/methods-1-CK0047/blob/master/Trabalho%202/image.png)

**Dados de entrada**: 
* n (número de quantidades);
* termos de [A]nxn;
* termos de {d}nx1.

**Dados de saída**: quadros resposta (com c para cada reação e método) e comparativo.