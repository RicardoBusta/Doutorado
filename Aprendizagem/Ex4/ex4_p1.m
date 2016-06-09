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
mediaC = mediaC/30

sigmaC = zeros(4,4,3);
for i = 1:size(treino,1)
  xi = treino(i,1:4);
  mi = mediaC(treino(i,5),:);
  di = xi - mi;
  sigmaC(:,:,treino(i,5)) += di'*di
endfor
sigmaC = sigmaC * (1/29);

sigmaNaiveC = zeros(4,4,3);
for i = 1:3
  sigmaNaiveC(:,:,i) = eye(4,4).*sigmaC(:,:,i);
endfor

function prob = probXdadoC(in)
  x = in(1:4);
  c = in(5);
  sigma = sigmaC(:,:,c);
  mi = mediaC(c,:);
endfunction