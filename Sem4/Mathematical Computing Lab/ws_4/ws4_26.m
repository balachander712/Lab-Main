flag = 0;
while flag == 0
    rand_num = randi([3 10], 1, 1);
    if rand_num == 5
        fprintf('5 Occured !!\n')
        flag = 1;
    else
        fprintf('%d occured but not 5\n', rand_num)
    end
end