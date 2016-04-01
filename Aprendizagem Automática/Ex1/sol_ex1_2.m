w = [0;0];
alpha = 0.001;
eqm = [];
numepoch = 1000;

function y = f(x,w)
  y = w(2)*x + w(1);
end

for epoch = 1:numepoch
  neqm = 0;
  for i = 1:numel(x)
    y_x = f(x(i),w);
    e = y(i)-y_x;
    w(1) += alpha*e;
    w(2) += alpha*e*x(i);
    neqm += e*e;
  endfor
  eqm = [eqm; neqm/numel(x)];
endfor

subplot(1,2,1)
hold on
axis([min(x)-1 max(x)+1 min(y)-1 max(y)+1]);
scatter(x,y);
plot([min(x)-1 max(x)+1], [f(min(x)-1,w) f(max(x)+1,w)], 'color', 'r');
hold off

subplot(1,2,2)
hold on
plot([1:numepoch],eqm,'color', 'g');
hold off