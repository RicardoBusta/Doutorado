#batch
data = load("./ex1data2.txt");

x = [ones(numel(data(:,1)),1),data(:,1),data(:,2)];
y = data(:,3);
w = [0,0,0]

w = inv(x'*x)*x'*y