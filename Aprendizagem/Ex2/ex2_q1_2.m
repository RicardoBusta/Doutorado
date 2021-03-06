treino = ex2data1(1:70,:);
teste = ex2data1(71:100,:);

w = [0;0;0];
x = [ones(70,1),treino(:,1)/100,treino(:,2)/100];
y = treino(:,3);

alpha = 0.01;
eqm = [];
numepoch = 1000;

function z = plotDecisionBoundary(theta, X, y)
  tmp1 = find(y==1);
  tmp0 = find(y==0);
  plot(X(tmp1,2),X(tmp1,3), '^');
  hold on
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

%hold on
%plot([1:numepoch],eqm,'color', 'g', 'linewidth', 2);
%hold off

plotDecisionBoundary(w',x,y);