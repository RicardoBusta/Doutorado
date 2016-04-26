treino = ex2data1(1:70,:);
teste = ex2data1(71:100,:);

w = [0;0;0];
x = [ones(70,1),treino(:,1),treino(:,2)];
y = treino(:,3);

alpha = 0.001;
eqm = [];
numepoch = 1000;

function y = f(x,w)
x
w
  r = x*w
  y = 1 / (1 + exp(-r));
end

for epoch = 1:numepoch
  neqm = 0;
  index = randperm(numel(y));
  for i = 1:numel(y)
    y_x = f(x(index(i),:),w);
    e = y(index(i))-y_x;
    w += alpha*e*x(index(i),:)';
    %w(2) += alpha*e*x(index(i));
    neqm += e*e;
  endfor
  eqm = [eqm; neqm/numel(y)];
endfor

hold on
plot([1:numepoch],eqm,'color', 'g', 'linewidth', 2);
hold off