clear all
load('ex3data2.data')

NumTreino = 306;
NumValid = 100;
NumTeste = 100;

#ex3data2 = ex3data2./10;

function nX = normalize(X)
  nrows = size(X, 1);
  means = repmat(mean(X), nrows, 1);
  stds = repmat(std(X), nrows, 1);
  
  nX = X - means ./ stds;
endfunction
ex3data2 = normalize(ex3data2);
#Divide conjunto de treino e conjunto de teste
TreinoX = ex3data2(1:NumTreino,1:13);
ValidacaoX = ex3data2(NumTreino+1:NumTreino+NumValid,1:13);
TesteX = ex3data2(NumTreino+NumValid+1:end,1:13);
TreinoT = ex3data2(1:NumTreino,14);
ValidacaoT = ex3data2(NumTreino+1:NumTreino+NumValid,14);
TesteT = ex3data2(NumTreino+NumValid+1:end,14);

[Xrow Xcol] = size(TreinoX);

#Número de épocas
NumEpoch = 10;
#Passo da aprendizagem
Alpha = 0.001; 
#Tamanho da rede
NumNeurOcult = 5;
NumNeurSaida = 1;
DimEntrada = Xcol;

#Matriz de pesos da camada oculta
WOculta = randn(NumNeurOcult,DimEntrada);
WSaida = randn(NumNeurSaida,NumNeurOcult+1);

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
  Os = Ws*[-1*ones(1,Oocol);Oo];
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
  
    d_k = Erro;
    step_k = Alpha * d_k * Os;
    WSaida = WSaida + step_k;
    
    d_i = Oo'*(1 .- Oo)*WSaida(:, 2:end)*d_k;
    WOculta = WOculta + Alpha*d_i'*x;
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