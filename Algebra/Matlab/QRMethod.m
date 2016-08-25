clear;clc
A = [-149 -50 -154; 537 180 546; -27 -9 -25];
n = numel(A(:,1));
I = eye(n,n);

E = eye(n,n);

M = A;

% 100 iterações para tentar triangularizar a matriz.
% Poderia ter usado um critério de parada.
for i = 1:100      
  [Q,R] = myQR(M);
  M = R*Q;
  E = Q*E;
  if mod(i,20)==0
   i
   Mi = M
  endif
endfor

[MLvec,MLval] = eig(A)
myEig = (I.*M)*[1;1;1]

%for i = 1:n;
%  C = A - I*eigM(i);
%  D = zeros(n,1);
%  C\D;
%endfor;

A
E