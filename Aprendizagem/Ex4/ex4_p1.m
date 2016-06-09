clear all

load ex4data1.data

treino = [ex4data1(1:30,:);ex4data1(51:80,:);ex4data1(101:130,:)];
teste = [ex4data1(31:50,:);ex4data1(81:100,:);ex4data1(131:150,:)];

% probabilidade do cara ser da classe C. cada linha do vetor eh a prob de uma classe.
probC = ones(3,1)*1/3;

% média das features de cada classe. cada linha eh uma classe.
mediaC = [[0,0,0,0];[0,0,0,0];[0,0,0,0]];
for i = 1:size(treino,1)
  mediaC(treino(i,5),:) += treino(i,1:4);
endfor
mediaC = mediaC/30;

% Cálculo da matriz de covariancia.
sigmaC = zeros(4,4,3);
for i = 1:size(treino,1)
  xi = treino(i,1:4);
  mi = mediaC(treino(i,5),:);
  di = xi - mi;
  sigmaC(:,:,treino(i,5)) += di'*di;
endfor
sigmaC = sigmaC * (1/29);

% Calculo da matriz de covariancia para o naive bayes.
sigmaNaiveC = zeros(4,4,3);
for i = 1:3
  sigmaNaiveC(:,:,i) = eye(4,4).*sigmaC(:,:,i);
endfor

% Probabilidade de ser X dado classe C 
% (e matriz de covariancia sigma)
function prob = probXdadoC(in,sigma,mi)
  x = in(1:4);
  c = in(5);
  m = numel(mi);
  r = x - mi;
  
  prob1 = (1/((det(sigma)^0.5)*((2*pi)^(m/2))));
  rm = r*inverse(sigma)*r';
  prob2 = exp(-0.5*rm);
  prob = prob1 * prob2;
endfunction

% Classificar o povo do teste
confusion = zeros(3,3);
naive_confusion = zeros(3,3);
for i = 1:size(teste,1)
  probC1X = probXdadoC(teste(i,:),sigmaC(:,:,1),mediaC(1,:));
  probC2X = probXdadoC(teste(i,:),sigmaC(:,:,2),mediaC(2,:));
  probC3X = probXdadoC(teste(i,:),sigmaC(:,:,3),mediaC(3,:));
  
  probC1Xnaive = probXdadoC(teste(i,:),sigmaNaiveC(:,:,1),mediaC(1,:));
  probC2Xnaive = probXdadoC(teste(i,:),sigmaNaiveC(:,:,2),mediaC(2,:));
  probC3Xnaive = probXdadoC(teste(i,:),sigmaNaiveC(:,:,3),mediaC(3,:));
  
  c = 0;
  if (probC1X > probC2X && probC1X > probC3X)
    c = 1;
  elseif (probC2X > probC1X && probC2X > probC3X)
    c = 2;
  else
    c = 3;
  endif
  confusion(teste(i,5),c)++;
  
  cn = 0;
  if (probC1Xnaive > probC2Xnaive && probC1Xnaive > probC3Xnaive)
    cn = 1;
  elseif (probC2Xnaive > probC1Xnaive && probC2Xnaive > probC3Xnaive)
    cn = 2;
  else
    cn = 3;
  endif
  naive_confusion(teste(i,5),cn)++;
endfor
confusion
naive_confusion