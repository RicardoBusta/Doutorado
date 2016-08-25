clc;clear

%load overdetermined_data.txt
A = [1.1 1.2 1.3 1.3 1.4]';
%A = overdetermined_data(:,1);
A = [ones(numel(A),1) A]
b = [1.0 1.5 2.0 2.5 3.0]'
%b = overdetermined_data(:,2);


[m,n] = size(A);
[Q,R] = myQR(A);
c = Q'*b;
%resolver o sistema Q'*b = R*c
y = R(1:n,1:n) \ c(1:n)

%solução do matlab pro least squares
x = A\b


%daqui em diante é só pra tentar plotar os dados
[min_x,min_x_ind] = min(A(:,2));
[max_x,max_x_ind] = max(A(:,2));

min_y = A(min_x_ind,:)*y;
max_y = A(max_x_ind,:)*y;

hold on
plot(b,A(:,2),'r.','markersize',15);
plot([min_y max_y],[min_x max_x]);
hold off