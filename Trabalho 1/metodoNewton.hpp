//METODO DE NEWTON PARA POLINOMIOS
#include <iostream>
#include <vector>
#include<cmath>

using namespace std;

//Funcoes declaradas nesse arquivo
vector<vector<double>> methodNewtonPolynomialHorner(vector<double> polynomial, double chute, double erro, double maxIteration);
double derivateCalculatePxHorner(vector<double> polynomial, double value);
double calculatePxHorner(vector<double> polynomial, double value);
double derivateCalculatePx(vector<double> polynomial, double value);
double calculatePx(vector<double> polynomial, double value);
double calculateSecPx(vector<double> polynomial, double value1, double value2);


/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
//Metodo de Newton para polinomios Com Horner
vector<vector<double>> methodNewtonPolynomialHorner(vector<double> polynomial, double chute, double erro, double maxIteration){
  //Calcula o tempo de execucao
  clock_t start, end;
  start = clock();
  //Variaveis para armazenar os calulos
  double Px, DerivatePx, var = chute;
  Px = calculatePxHorner(polynomial, var);
  DerivatePx = derivateCalculatePxHorner(polynomial, chute);
  //Vetor que contem todos os dados do calculo do metodo utilizando Horner
  vector<vector<double>> QuadroRespostaHorner;
  //Suporte
  vector<double> Linha = {};
  //Verifica se o chute foi muito bom 
  if (abs(Px) > erro){ //Se for maior
    //Comeco dos passos ate o numero maximo de interacoes
    for(int i=0; i<maxIteration; i++){
      QuadroRespostaHorner.push_back(Linha);
      QuadroRespostaHorner[i].push_back(i);
      QuadroRespostaHorner[i].push_back(var);
      QuadroRespostaHorner[i].push_back(Px);
      QuadroRespostaHorner[i].push_back(DerivatePx);
      //Realiza o calculo do Metodo
      var = var -1*(Px/DerivatePx);
      Px = calculatePxHorner(polynomial, var);
      //Verifica a condicao de parada
      if(abs(Px) <= erro){ //Se estiver menor do que o erro
        QuadroRespostaHorner.push_back(Linha);
        //Calculo do tempo de execucao
        end = clock();
        cout << " \n" << "Tempo de execução: " << 1000*(double(end-start) / double(CLOCKS_PER_SEC)) << "\n";
        
        QuadroRespostaHorner[i+1].push_back(i+1);
        QuadroRespostaHorner[i+1].push_back(var);
        QuadroRespostaHorner[i+1].push_back(Px);
        QuadroRespostaHorner[i+1].push_back(DerivatePx);
        return QuadroRespostaHorner;
      }
      //Realiza o passo do metodo
      DerivatePx = derivateCalculatePxHorner(polynomial, var);
    }
    //Calculo do tempo de execucao
    end = clock();
    cout << " \n" << "Tempo de execução:" << 1000*(double(end-start) / double(CLOCKS_PER_SEC)) << "\n";
    //Caso atinja o maximo de passos estabelecidos e nao foi possivel atingir uma raiz com um erro aceitavel
    cout << "Não deu em nada \n";
    cout << "Raiz mais proxima: " << var << "\n";
  }
  else {
    //Calculo do tempo de execucao
    end = clock();
    cout << " \n" << "Tempo de execução:" << 1000*(double(end-start) / double(CLOCKS_PER_SEC)) << "\n";    
    //Caso o chute seja muito certeiro
    QuadroRespostaHorner.push_back(Linha);
    QuadroRespostaHorner[0].push_back(0);
    QuadroRespostaHorner[0].push_back(chute);
    QuadroRespostaHorner[0].push_back(Px);
    QuadroRespostaHorner[0].push_back(DerivatePx);
    cout << "Chutou muito bem\n";
    cout << "Raiz: " << chute << "\n";
    cout << "Valor do P(x): " << Px;
  }
  cout << "teste";
  return QuadroRespostaHorner;
}


/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
//Metodo de Newton para polinomios SEM HORNER
vector<vector<double>> methodNewtonPolynomial(vector<double> polynomial, double chute, double erro, double maxIteration){
  //Calcula o tempo de execucao
  clock_t start, end;
  start = clock();
  //Variaveis para armazenar os calulos
  double Px, DerivatePx, var = chute;
  Px = calculatePx(polynomial, var);
  //Vetor que contem todos os dados do calculo do metodo
  vector<vector<double>> QuadroResposta;
  //Suporte
  vector<double> Linha = {};
  //Verifica se o chute foi muito bom 
  if (abs(Px) > erro){ //Se for maior
    DerivatePx = derivateCalculatePx(polynomial, chute);
    //Comeco dos passos ate o numero maximo de interacoes
    for(int i=0; i<maxIteration; i++){
      QuadroResposta.push_back(Linha);
     

      QuadroResposta[i].push_back(i);
      QuadroResposta[i].push_back(var);
      QuadroResposta[i].push_back(Px);
      QuadroResposta[i].push_back(DerivatePx);

      //Realiza o calculo do Metodo
      var = var -1*(Px/DerivatePx);
      Px = calculatePx(polynomial, var);
      //Verifica a condicao de parada
      if(abs(Px) <= erro){ //Se estiver menor do que o erro
        QuadroResposta.push_back(Linha);
        //Calculo do tempo de execucao
        end = clock();
        cout << " \n" << "Tempo de execução: " << 1000*(double(end-start) / double(CLOCKS_PER_SEC)) << "\n";
       
        QuadroResposta[i+1].push_back(i+1);
        QuadroResposta[i+1].push_back(var);
        QuadroResposta[i+1].push_back(Px);
        QuadroResposta[i+1].push_back(DerivatePx);
        return QuadroResposta;
      }
      //Realiza o passo do metodo
      DerivatePx = derivateCalculatePx(polynomial, var);
    }
    //Calculo do tempo de execucao
    end = clock();
    cout << " \n" << "Tempo de execução:" << 1000*(double(end-start) / double(CLOCKS_PER_SEC)) << "\n";
    //Caso atinja o maximo de passos estabelecidos e nao foi possivel atingir uma raiz com um erro aceitavel
    cout << "Não deu em nada \n";
    cout << "Raiz mais proxima: " << var << "\n";
  }
  else {
    //Calculo do tempo de execucao
    end = clock();
    cout << " \n" << "Tempo de execução:" << 1000*(double(end-start) / double(CLOCKS_PER_SEC)) << "\n";    
      QuadroResposta.push_back(Linha);
    QuadroResposta[0].push_back(0);
    QuadroResposta[0].push_back(chute);
    QuadroResposta[0].push_back(Px);
    QuadroResposta[0].push_back(DerivatePx);
    //Caso o chute seja muito certeiro
    cout << "Chutou muito bem \n";
    cout << "Raiz: " << chute << "\n";
    cout << "Valor do P(x): " << Px;
  }
  return QuadroResposta;
}


/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
//Metodo de Newton para polinomios SEM HORNER
vector<vector<double>> methodNewtonSecant(vector<double> polynomial, double chute1, double chute2, double erro, double maxIteration){
  //Calcula o tempo de execucao
  clock_t start, end;
  start = clock();
  //Variaveis para armazenar os calulos
  double Px, DerivatePx, var = chute1, varAnt = chute2, aux;
  Px = calculatePx(polynomial, var);
  //Vetor que contem todos os dados do calculo do metodo
  vector<vector<double>> QuadroResposta;
  //Suporte
  vector<double> Linha = {};
  //Verifica se o chute foi muito bom 
  if (abs(Px) > erro){ //Se for maior
    //Comeco dos passos ate o numero maximo de interacoes
    cout << "teste";
    for(int i=0; i<maxIteration; i++){
      QuadroResposta.push_back(Linha);
      QuadroResposta[i].push_back(i);
      QuadroResposta[i].push_back(var);
      QuadroResposta[i].push_back(Px);
      QuadroResposta[i].push_back(calculateSecPx(polynomial, var, varAnt));

      //Realiza o calculo do Metodo
      aux = var;
      var = var - (Px)/calculateSecPx(polynomial, var, varAnt);
      varAnt = aux;
      Px = calculatePx(polynomial, var);
      //Verifica a condicao de parada
      if(abs(Px) <= erro){ //Se estiver menor do que o erro
        QuadroResposta.push_back(Linha);
        //Calculo do tempo de execucao
        end = clock();
        cout << " \n" << "Tempo de execução: " << 1000*(double(end-start) / double(CLOCKS_PER_SEC)) << "\n";
       
        QuadroResposta[i+1].push_back(i+1);
        QuadroResposta[i+1].push_back(var);
        QuadroResposta[i+1].push_back(Px);
        QuadroResposta[i+1].push_back(DerivatePx);
        return QuadroResposta;
      }
      Px = calculatePx(polynomial, var);
    }
    //Calculo do tempo de execucao
    end = clock();
    cout << " \n" << "Tempo de execução:" << 1000*(double(end-start) / double(CLOCKS_PER_SEC)) << "\n";
    //Caso atinja o maximo de passos estabelecidos e nao foi possivel atingir uma raiz com um erro aceitavel
    cout << "Não deu em nada \n";
    cout << "Raiz mais proxima: " << var << "\n";
  }
  else {
    //Calculo do tempo de execucao
    end = clock();
    cout << " \n" << "Tempo de execução:" << 1000*(double(end-start) / double(CLOCKS_PER_SEC)) << "\n";    
    QuadroResposta.push_back(Linha);
    QuadroResposta[0].push_back(0);
    QuadroResposta[0].push_back(chute1);
    QuadroResposta[0].push_back(Px);
    QuadroResposta[0].push_back(DerivatePx);
    //Caso o chute seja muito certeiro
    cout << "Chutou muito bem \n";
   // cout << "Raiz: " << chute << "\n";
    cout << "Valor do P(x): " << Px;
  }
  return QuadroResposta;
}


/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
//Utiliza o metodo de Horner para estruturar as multiplicacoes
double calculatePxHorner(vector<double> polynomial, double value){
  return ( ( (polynomial[8]*value + polynomial[6])*value + polynomial[4])*value + polynomial[2])*value + polynomial[0];
}
//Utiliza o metodo de Horner para estruturar as multiplicacoes
double derivateCalculatePxHorner(vector<double> polynomial, double value){
  return ( ( (polynomial[7]*value+polynomial[5])*value + polynomial[3])*value + polynomial[1]);
}

//Metodo de calculo normal (Mais lento), não utiliza Horner
double derivateCalculatePx(vector<double> polynomial, double value){
  double res = 0, powteste = 0;
  for(int i=1; i<9;i=i + 2){
    res += polynomial[i]*pow(value, powteste);
    powteste += 1; 
  }
  return res;
}
//Metodo de calculo normal (Mais lento), não utiliza Horner
double calculatePx(vector<double> polynomial, double value){
  double res;
  for(int i=0; i<5;i++){
    res += polynomial[i*2]*pow(value, i);
  }
  return res;
}
//Metodo de calculo normal (Mais lento), não utiliza Horner
double calculateSecPx(vector<double> polynomial, double value1, double value2){
  return (calculatePx(polynomial, value1) - calculatePx(polynomial, value2))/(value1 - value2);
}
