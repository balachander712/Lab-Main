years = 0:30;
account_balance = [5000];
count = 0;
while account_balance(end) < 1000000
    account_balance(end+1) = account_balance(end)+ (account_balance(end)*(9/100));
    count = count+1;
end
fprintf('Number of years it takes to reach retirement is: %d\n', count)