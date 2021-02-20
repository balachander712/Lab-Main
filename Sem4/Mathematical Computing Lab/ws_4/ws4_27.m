count = 1;
array = zeros(1, 10);
while count < 11
    rand_num = randi([3 10], 1, 1);
    array(count) = rand_num;
    count = count + 1;
end
display(array);