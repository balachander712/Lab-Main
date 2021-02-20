num_1 = input('Please enter the number 1: ');
num_2 = input('Please enter the number 2: ');
choice = input('Please enter the choice: ');

switch(choice)
    case 1
       fprintf('Addition: %d\n', num_1+num_2);
    case 2
       fprintf('Subtraction: %d\n', num_1-num_2);
    case 3
       fprintf('Multiplication: %d\n', num_1*num_2);
    case 4
       fprintf('Division: %d\n', num_1/num_2);
    otherwise
        fprintf('The choice made is invalid')
end