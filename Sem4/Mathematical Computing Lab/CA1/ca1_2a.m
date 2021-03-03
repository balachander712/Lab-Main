x = linspace(0,9,40);
f1x = 1/((2*pi).^0.5) .* (exp((-1/2).*((x - 4.5).^2)));
f2x = 0.5 .* exp(-0.5 .* x);
f3x = repelem( 0.4 , numel(x));

ln = plot(x, f1x, 'g--o');
ln.LineWidth = 2;
ln.MarkerEdgeColor = 'r';
ln.MarkerFaceColor = 'r';
ln.MarkerSize = 5;

hold on
plot(x, f2x, ':');

ln1 = plot(x, f3x, 'c-.',...
    'color','k');
ln1.LineWidth = 1;
axis([0 9 0 0.6]);
legend('Location', 'none', 'Location', 'northeast','Normal', 'Exponential', 'Uniform');
title('Probability Density Functions')