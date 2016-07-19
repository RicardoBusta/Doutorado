clear;clc
M = [-149 -50 -154; 537 180 546; -27 -9 -25];

A = M;

for i = 1:100      
  [Q,R] = qr(A);
  A = R*Q;
  if mod(i,20)==0
   i
   Ai = A
  endif
endfor

eigA = eig(A)
eigM = eig(M)

M