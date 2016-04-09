data = load("./ex1data3.txt");

x = [ones(30,1),data(1:30,1),data(1:30,2),data(1:30,3),data(1:30,4),data(1:30,5)];
y = data(1:30,6);
xc = [ones(47-30,1),data(31:47,1),data(31:47,2),data(31:47,3),data(31:47,4),data(31:47,5)];
yc = data(31:47,6);

w = [0,0,0,0,0,0];

lambda = [0,1,2,3,4,5];
eqm_tr = [0,0,0,0,0,0];
eqm_te = [0,0,0,0,0,0];

for l = lambda
  I = eye(6,6);
  I(1,1) = 0;
  w = inv((x'*x)+(l*I))*x'*y;
  eqm_tr(l+1) = 0;
  for d = 1:30
    fx = x(d,:)*w;
    eqm_tr(l+1) += (y(d)-fx)^2;
  endfor
  eqm_tr(l+1) /= 30;
  
  eqm_te(l+1) = 0;
  for d = 1:17
    fx = xc(d,:)*w;
    eqm_te(l+1) += (yc(d)-fx)^2;
  endfor
  eqm_te(l+1) /= 17;
endfor

hold on
plot(lambda,eqm_tr,'color', 'r', 'linewidth', 2);
plot(lambda,eqm_te,'color', 'b', 'linewidth', 2);
hold off