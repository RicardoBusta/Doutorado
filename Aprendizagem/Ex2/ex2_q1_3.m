fold1 = ex2data1(1:50,:);
fold2 = ex2data1(51:100,:);

w1 = [0;0;0];
w2 = [0;0;0];
x1 = [ones(50,1),fold1(:,1)/100,fold1(:,2)/100];
y1 = fold1(:,3);
x2 = [ones(50,1),fold2(:,1)/100,fold2(:,2)/100];
y2 = fold2(:,3);

alpha = 0.01;
eqm1 = [];
eqm2 = [];
numepoch = 1000;

function z = plotDecisionBoundary(theta, X, y)
  tmp1 = find(y==1);
  tmp0 = find(y==0);
  plot(X(tmp1,2),X(tmp1,3), '^');
  plot(X(tmp0,2),X(tmp0,3), 'rv');
  if size(X, 2) <= 3 
    % Only need 2 points to define a line, so choose two endpoints
    plot_x = [min(X(:,2))-0.1,  max(X(:,2))+0.1];
    % Calculate the decision boundary line
    plot_y = (-1./theta(3)).*(theta(2).*plot_x + theta(1));
    % Plot, and adjust axes for better viewing
    plot(plot_x, plot_y)
    % Legend, specific for the exercise
    legend('Admitted', 'Not admitted', 'Decision Boundary')
    axis([0.2,1.1, 0.2, 1.1])
  else
    % Here is the grid range
    u = linspace(-1, 1.5, 50);
    v = linspace(-1, 1.5, 50);
    z = zeros(length(u), length(v));
    % Evaluate z = theta*x over the grid
    for i = 1:length(u)
      for j = 1:length(v)
        z(i,j) = mapFeature(u(i), v(j))*theta;
      end
    end
    z = z'; % important to transpose z before calling contour
    % Plot z = 0
    % Notice you need to specify the range [0, 0]
    contour(u, v, z, [0, 0], 'LineWidth', 2)
  end
  hold off
end

function y = f(x,w)
  r = x*w;
  y = 1 / (1 + exp(-r));
end

for epoch = 1:numepoch
  neqm1 = 0;
  neqm2 = 0;
  index1 = randperm(numel(y1));
  index2 = randperm(numel(y1));
  for i = 1:numel(y1)
    y_x1 = f(x1(index1(i),:),w1);
    e1 = y1(index1(i))-y_x1;
    w1 += alpha*e1*x1(index1(i),:)';
    neqm1 += e1*e1;
    
    y_x2 = f(x2(index2(i),:),w2);
    e2 = y2(index2(i))-y_x2;
    w2 += alpha*e2*x2(index2(i),:)';
    neqm2 += e2*e2;
  endfor
  eqm1 = [eqm1; neqm1/numel(y1)];
  eqm2 = [eqm2; neqm2/numel(y2)];
endfor

%hold on
%plot([1:numepoch],eqm,'color', 'g', 'linewidth', 2);
%hold off
%hold on
subplot(2,2,1);
hold on
plotDecisionBoundary(w1',x1,y1);
hold off

subplot(2,2,2);
hold on
plotDecisionBoundary(w2',x2,y2);
hold off

wm = (w1 + w2) * 0.5;

subplot(2,2,3);
hold on
tmp11 = find(y1==1);
tmp01 = find(y1==0);
plot(x1(tmp11,2),x1(tmp11,3), 'b^');
plot(x1(tmp01,2),x1(tmp01,3), 'rv');
tmp12 = find(y2==1);
tmp02 = find(y2==0);
plot(x2(tmp12,2),x2(tmp12,3), 'g^');
plot(x2(tmp02,2),x2(tmp02,3), 'mv');
axis([0.2,1.1, 0.2, 1.1])
plot_x = [min([x1;x2](:,2))-0.1,  max([x1;x2](:,2))+0.1];
plot_y = (-1./wm(3)).*(wm(2).*plot_x + wm(1));
plot(plot_x, plot_y)
hold off