#apenas para matriz 3x3
function [Q,R] = QRHouseHolder( A )
  %Gera matriz de householder
  u = A(:,1);
  u(1) = u(1)-(1-2*(u(1)<0))*norm(u);
  u = u/norm(u);
  u(~isfinite(u)) = sqrt(3)/3;
  Q = -2*(u*u');
  Q([1 5 9]) = Q([1 5 9])+1;

  u = Q(2:3,:)*A(:,2);
  u(1) = u(1)-(1-2*(u(1)<0))*norm(u);
  u = u/norm(u);
  u(~isfinite(u)) = sqrt(2)/2;
  Q(:,2:3) = Q(:,2:3)*[1-2*u(1)^2 -2*u(1)*u(2);
                     -2*u(1)*u(2) 1-2*u(2)^2];
  %remove elementos abaixo da diagonal                     
  R = triu(Q'*A);
%function [U,R] = householder(A)
%  [m, n] = size(A);
%  R = A;
%  for k = 1:n,
%    x = R(k:m,k);
%    e = zeros(length(x),1); e(1) = 1;
%    u = sign(x(1))*norm(x)*e + x;
%    u = u./norm(u);
%    R(k:m, k:n) = R(k:m, k:n) -2*u*u'*R(k:m, k:n);
%    Q(k:m,k) = u;
%  endfor

%nq = size(A,1);
%Q = eye(nq);
%for k = 1:nq-1
%	v = ones(nq+1-k,1);
%	v(2:nq+1-k) = A(k+1:nq,k);
%	Qk = eye(nq);
%	Qk(k:nq,k:nq) = eye(nq+1-k) - (2/(v'*v))*(v*v');
%	Q = Qk*Q;
%end

%[n,m] = size(A);
%for k = 1:min(n-1,m)
%  a = A(k:n,k);
%  n = length(a);
%  vo = a;
%  if (a(1) >= 0) beta = a(1) + norm(a);
%    else beta = a(1) - norm(a);
%  end
%  vo(2:n) = 1/beta * vo(2:n);
%  vo(1) = 1;
%	v(k:n,1) = vo;
%  beta2 = -2/(v'*v);
%  A1 = A(k:n,k:m);
%  v1 = v(k:n,1);
%  w2 = v1'*A1;          % w is a line vector
%  A2 = A + beta2*v1*w2;
%	A(k:n,k:m) = A2;
%	A(k+1:n,k) = v(k+1:n,1);
%end
%R = A;
endfunction 