i = 1;
sgn = -1;
sum = 0;
while i <= 201
    if sgn == 1
    sum = sum + sgn * (i^3);
    else
    sum = sum + sgn * (i^5);
    end
    sgn = sgn * -1;
    i = i + 2;
end
fprintf('%d \n',sum)