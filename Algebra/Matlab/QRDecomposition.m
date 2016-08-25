clear;clc

#A = rand(rows,cols);
A = [12 -51 4; 6 167 -68;-4 24 -41];

function p = proj(a,e)
  p = (dot(e,a)*e)/dot(e,e);
endfunction

function [Q,R] = myQR(A)
  rows = numel(A(:,1));
  cols = numel(A(1,:));
  U = zeros(rows,rows);
  Q = zeros(rows,rows);
  R = zeros(rows,cols);
  % U é a matriz das bases ortogonais

  % Usando Gram-Schmidt para calcular a decomposição QR

  % Cálculo do Q
  for j = 1:cols
    U(:,j) = A(:,j);
    for k = 1:j-1
      U(:,j) -= proj( A(:,j) , U(:,k) );
    endfor
    norm_uj = sqrt(U(:,j)'*U(:,j));
    Q(:,j) = U(:,j)/(norm_uj);
  endfor

  % Cálculo do R
  for i = 1:rows
    for j = i:cols
      R(i,j) = Q(:,i)' * A(:,j);
    endfor 
  endfor
endfunction

A
[Q,R] = myQR(A)

[QH,RH] = QRHouseHolder(A)

QR = Q*R

[MLQ,MLR] = qr(A)