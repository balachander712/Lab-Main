function [ output_args ] = getFac( num )
    if num == 1
        output_args = 1;
    else
        output_args = num*getFac(num-1);
    end
end
