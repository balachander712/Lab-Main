syms t;

f = 1*heaviside(t) - 1*heaviside(t-2) + (t-2)*heaviside(t-2);
subplot(2,1,1);
fplot(f);

laplace_f = laplace(f);
subplot(2,1,2);
fplot(laplace_f);