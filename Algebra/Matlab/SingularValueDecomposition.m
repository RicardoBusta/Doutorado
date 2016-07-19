clear;clc
A = rand(5,3)

ATA = A'*A
AAT = A*A'

% Resolvendo
[V,S1] = eig(ATA)
[U,S2] = eig(AAT)

% Usando solução do MatLab para comparação
[MLU,MLS,MLV] = svd(A)

S3 = MLS'*MLS