function [  ] = printFib( sequence, num )
    if numel(sequence) ~= num
        printFib([sequence sequence(end)+sequence(end-1)], num)
    else
        sequence
    end
end
