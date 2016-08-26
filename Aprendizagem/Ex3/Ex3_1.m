clear all
load('ex3data1.mat')

#================
#  Configuração
#================

NumTreino = 4000;
NumValid = 500;
NumTeste = 500;
[Xrow Xcol] = size(X);

I = randperm(Xrow);
X = X(I,:);

X = [-1*ones(Xrow,1) X];
Xcol = Xcol+1;


#Divide conjunto de treino e conjunto de teste
TreinoX = X(1:NumTreino,:);
ValidacaoX = X(NumTreino+1:NumTreino+NumValid,:);
TesteX = X(NumTreino+NumValid+1:end,:);
TreinoT = T(1:NumTreino,:);
ValidacaoT = T(NumTreino+1:NumTreino+NumValid,:);
TesteT = T(NumTreino+NumValid+1:end,:);


#Número de épocas
NumEpoch = 1;
#Passo da aprendizagem
Alpha = 0.01; 
#Tamanho da rede
NumNeurOcult = 20;
NumNeurSaida = 10;
DimEntrada = Xcol;

#Matriz de pesos da camada oculta
WOculta = rand(NumNeurOcult,DimEntrada);
WSaida = rand(NumNeurSaida,NumNeurOcult+1);

#Threshold function
function out = sigmoid(V)
  out = 1./(1+exp(-V));
endfunction

#Funções
function [Oo Os] = NetValue(X,Wo,Ws)
  %Camada Oculta
  Oo = sigmoid(Wo*X);
    
  %Camada de Saída
  [Oorow Oocol] = size(Oo);
  Os = sigmoid(Ws*[-1*ones(1,Oocol);Oo]);
endfunction

function Erro = GetErro(X,T,Wo,Ws)
  [Mo Ms] = NetValue(X',Wo,Ws);
  MErro = T' - Ms;
  [Xrow Xcol] = size(X);
  VErro = zeros(1,Xcol);
  for i = 1:Xcol,
    VErro(i) = MErro(:,i)'*MErro(:,i);
  endfor
  Erro = mean(VErro);
endfunction

#===============
#  Treinamento
#===============

Errors = zeros(NumEpoch,1);
VErrors = zeros(NumEpoch,1);

for epoch = 1:NumEpoch,
  #Embaralha os elementos
  Index = randperm(NumTreino);  
  
  for it = 1:NumTreino,
    #Cálculo da camada oculta
    x = TreinoX(it,:);
    y = TreinoT(it,:);
    [Oo Os] = NetValue(x',WOculta,WSaida);
    Erro = y' - Os;
  
    #Derivada da Sigmoid Saida
    DSS = Os.*(1-Os);
    GSS = Erro.*DSS;
    #Derivada da Sigmoid Oculta
    DSO = Oo.*(1-Oo);
    GSO = DSO.*(WSaida(:,2:end)'*GSS);
    
    #Ajuste dos pesos
    WOculta = WOculta + Alpha*GSO*x;
    WSaida = WSaida + Alpha*GSS*[-1;Oo]';
  endfor
  
  Errors(epoch) = GetErro(TreinoX,TreinoT,WOculta,WSaida);
  VErrors(epoch) = GetErro(ValidacaoX,ValidacaoT,WOculta,WSaida);
endfor

TErro = GetErro(TreinoX,TreinoT,WOculta,WSaida);

plot([1:NumEpoch],Errors,"g");
hold on;
plot([1:NumEpoch],VErrors,"b");
plot([1:NumEpoch],TErro*ones(NumEpoch,1),"r");
hold off;