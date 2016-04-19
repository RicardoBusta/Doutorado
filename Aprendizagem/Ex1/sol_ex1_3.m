#questão 3: regressão linear múltipla estocástica

data = load("./ex1data2.txt");

x = [ones(numel(data(:,1)),1),data(:,1),data(:,2)];
y = data(:,3);
w = [1,1,1];

alpha = 0.01;
eqm = [];
numepoch = 100;

for epoch = 1:numepoch
  neqm = 0;
  index = randperm(numel(y));
  for i = 1:numel(y)
    y_x = x(index(i),:)*w';
    e = y(index(i))-y_x;
    w += alpha*e*x(index(i),:);
    %w(2) += alpha*e*x(index(i));
    neqm += e*e;
  endfor
  eqm = [eqm; neqm/numel(y)];
endfor

%subplot(1,2,1)
%axis([min(x)-1 max(x)+1 min(y)-1 max(y)+1]);
%hold on
%scatter(x,y);
%plot([min(x)-1 max(x)+1], [f(min(x)-1,w) f(max(x)+1,w)], 'color', 'r', 'linewidth', 2);
%hold off

%subplot(1,2,2)
hold on
plot([1:numepoch],eqm,'color', 'g', 'linewidth', 2);
hold off