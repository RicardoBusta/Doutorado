rows = 3;
cols = 3;
M = rand(rows,cols);

U = zeros(rows,cols);

for j = 1:cols
  U(:,j) = M(:,j);
endfor

clc
#U
M