clear;clc
rows = 3;
cols = 3;
#M = rand(rows,cols);
M = [12 -51 4; 6 167 -68;-4 24 -41];

U = zeros(rows,cols);
Q = zeros(rows,cols);
R = zeros(rows,cols);

function p = proj(a,e)
  p = (dot(e,a)*e)/dot(e,e);
endfunction

% U é a matriz das bases ortogonais

% Usando Gram-Schmidt para calcular a decomposição QR

% Cálculo do Q
for j = 1:cols
  U(:,j) = M(:,j);
  for k = 1:j-1
    U(:,j) -= proj( M(:,j) , U(:,k) );
  endfor
  norm_uj = sqrt(U(:,j)'*U(:,j));
  Q(:,j) = U(:,j)/(norm_uj);
endfor

% Cálculo do R
for i = 1:rows
  for j = i:cols
    R(i,j) = Q(:,i)' * M(:,j);
  endfor 
endfor

M
Q
R
QR = Q*R

[MLQ,MLR] = qr(M)