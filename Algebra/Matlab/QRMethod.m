clear;clc
A = [-149 -50 -154; 537 180 546; -27 -9 -25];
n = numel(A(:,1));
I = eye(n,n);

M = A;

% 100 iterações para tentar triangularizar a matriz.
% Poderia ter usado um critério de parada.
for i = 1:100      
  [Q,R] = qr(M);
  M = R*Q;
  if mod(i,20)==0
   i
   Mi = M
  endif
endfor

MLeigA = eig(A)
eigM = (I.*M)*[1;1;1]

for i = 1:n
  C = A - I*eigM(i)
  D = zeros(n,1)
  X = C\D
endfor

A