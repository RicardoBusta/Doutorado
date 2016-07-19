clc;clear
A = [1 1.0;
     1 1.5;
     1 2.0;
     1 2.5;
     1 3.0]
b = [1.1 1.2 1.3 1.3 1.4]'

[m,n] = size(A);
[Q,R,P] = qr(A);
c = Q'*b;
y = R(1:n,1:n) \ c(1:n);
x = P*y

x = A\b;