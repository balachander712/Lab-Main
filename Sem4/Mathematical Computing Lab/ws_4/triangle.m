function [ area ] = triangle( a, b, c )
semi = (a+b+c)/2;
area = ((semi)*(semi-a)*(semi-b)*(semi-c))^0.5;
end

