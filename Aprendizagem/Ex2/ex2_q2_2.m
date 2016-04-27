x = [ones(numel(ex2data2(:,1)),1),ex2data2(:,1),ex2data2(:,2)];
y = ex2data2(:,3);

ind1 = find(y==1);
ind0 = find(y==0);

x0 = x(ind0,:);
x1 = x(ind1,:);

w = zeros(1,496);

mfx = mapFeature(x(:,2),x(:,3));

subplot(1,1,1);
hold on
plot(x0(:,2),x0(:,3),'rv','MarkerFaceColor','auto');
plot(x1(:,2),x1(:,3),'b^','MarkerFaceColor','auto');

alpha = 0.01;
eqm = [];
numepoch = 1000;

function y = f(x,w)
  r = x*w;
  y = 1 / (1 + exp(-r));
end

lambda = 0.25

for epoch = 1:numepoch
  neqm = 0;
  index = randperm(numel(y));
  for i = 1:numel(y)
    y_x = f(mfx(index(i),:),w');
    e = y(index(i))-y_x;
    w += alpha*(e*mfx(index(i),:) - lambda*w);
    %w(2) += alpha*e*x(index(i));
    neqm += e*e;
  endfor
  eqm = [eqm; neqm/numel(y)];
endfor

subplot(2,1,1);
hold on
plotDecisionBoundary(w',mfx,y);
hold off
subplot(2,1,2);
hold on
plot([1:numepoch],eqm,'color', 'g', 'linewidth', 2);
hold off