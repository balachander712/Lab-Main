function [ output_args ] = eval( input_args )
    output_args = ((input_args.^4) .* ((3.*input_args) + 5).^0.5)./((input_args.^2 + 1).^2);
end

