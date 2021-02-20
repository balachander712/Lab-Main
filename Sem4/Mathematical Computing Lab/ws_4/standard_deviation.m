function [ output_args ] = standard_deviation( input_args )
    avg = average(input_args);
    output_args = 0;
    for i = 1:numel(input_args)
       output_args = output_args + ((input_args(i)-avg)^2);
    end
    output_args = output_args/(numel(input_args));
    output_args = output_args^0.5;
end
