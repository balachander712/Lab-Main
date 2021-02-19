function [ output_args ] = ws4_22( ~ )
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here
i = 1;
sum = 0;
sign = 1;
while i <= 9999 
    sum = sum + sign * (i*i);
    sign = sign * -1;
    i = i + 2; 
endwhile 

fprintf('%d',sum)

end

