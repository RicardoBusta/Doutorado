t = [1.0 1.5 2.0 2.5 3.0]
y = [1.1 1.2 1.3 1.3 1.4]

n = numel(t);
sum_t = sum(t);
sum_t2 = t*t';
sum_y = sum(y);
sum_yt = y*t';

A = [ n sum_t ; sum_t sum_t2 ]
B = [ sum_y ; sum_yt ]

X = A\B

min_x = min(t);
max_x = max(t);

min_y = [1 min_x]*X;
max_y = [1 max_x]*X;

hold on
plot(t,y,'r.','markersize',15);
plot([min_x max_x],[min_y max_y]);
hold off