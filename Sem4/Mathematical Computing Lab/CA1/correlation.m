function [ r ] = correlation( x, y )
    nr = 0;
    for i=1:size(x,2)
        nr = nr + (x(i)-mean(x))*(y(i)-mean(y));
    end
    dr1 = 0;
    dr2 = 0;
    for j=1:size(x,2)
        dr1 = dr1 + (x(j)-mean(x))^2;
        dr2 = dr2 + (y(j)-mean(y))^2;
    end
    r = nr/((dr1^0.5)*(dr2^0.5));
end