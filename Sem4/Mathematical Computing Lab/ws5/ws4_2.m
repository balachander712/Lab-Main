syms x;
syms y;
f = cos(2*x) - x^2*exp(5*y) + 3*y^2;
g = diff(f,x)
h = diff(f,y)
i = diff(g,x)
j = diff(g,y)
