sum = 0;
for i = 1:50;
    if ~isprime(i)
        sum = sum + i;
    end
end
fprintf('The sum is %d\n', sum)