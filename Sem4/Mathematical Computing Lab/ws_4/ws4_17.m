years = 0:30;
account_balance = [1000];
for i = 1:30
    account_balance(end+1) = account_balance(end)+ (account_balance(end)*(2/25));
end
plot(years, account_balance)