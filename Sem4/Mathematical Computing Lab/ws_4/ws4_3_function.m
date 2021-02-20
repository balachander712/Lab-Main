function [ output_args ] = ws4_3_function( input_args )
    output_args = (-0.2.*(input_args.^4)) + ((exp(-0.5.*input_args)) .* (input_args.^3)) + (7 .* (input_args.^2));
end

