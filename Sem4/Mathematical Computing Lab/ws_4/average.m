function [ output_args ] = average( input_args )
output_args = sum(input_args)/numel(input_args);
end

