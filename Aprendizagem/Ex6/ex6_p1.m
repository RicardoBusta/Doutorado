clear all
load ex5data1.data

data = ex5data1;

for k = 2:5
% Sortear k centroides iniciais
  index = randperm(150);
  cores = data(index(1:k),:);
% Vetor que dira a classe que cada cara pertence
  classes = zeros(150,1);
  
% Calcular a menor distancia 
  for i = 1:150
    for c = 1:k
      % Cálculo da distancia
      dif = cores(c,:) - data(i,:);
      dist = dif*dif';
    endfor
  endfor
  
endfor
