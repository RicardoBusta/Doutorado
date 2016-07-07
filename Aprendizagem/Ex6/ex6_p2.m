clear all
load ex5data1.data

data = ex5data1(:,1:4);
datapos = ex5data1(:,5);

a = mean(data);

data2 = data - a;

C = cov(data2);

[V,D] = eig(C);

tot = sum(sum(D));
parc = sum(sum(D(2:4,2:4)));

res = D/tot;

V;

D;

Proj = [V(:,4) V(:,3)];

data3 = data*Proj;

hold on;
pos = find(datapos == 1);
plot(data3(pos,1),data3(pos,2),'b.','markersize',10);
pos = find(datapos == 2);
plot(data3(pos,1),data3(pos,2),'r.','markersize',10);
pos = find(datapos == 3);
plot(data3(pos,1),data3(pos,2),'g.','markersize',10);