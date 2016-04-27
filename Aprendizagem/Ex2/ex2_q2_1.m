x = [ones(numel(ex2data2(:,1)),1),ex2data2(:,1)/100,ex2data2(:,2)/100];
y = ex2data2(:,3);

ind1 = find(y==1);
ind0 = find(y==0);

x0 = x(ind0,:);
x1 = x(ind1,:);

subplot(1,1,1);
hold on
plot(x0(:,2),x0(:,3),'rv','MarkerFaceColor','auto');
plot(x1(:,2),x1(:,3),'b^','MarkerFaceColor','auto');