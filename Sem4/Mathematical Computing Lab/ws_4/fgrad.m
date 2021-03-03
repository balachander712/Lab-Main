function [ g ] = fgrad( R )
    g = zeros(size(R, 1), 1);
    for r = 1:size(R,1)
        hw_grades = R(r, 1:6);
        drop = min(hw_grades);
        drop_index = find(hw_grades == drop);
        drop_index = drop_index(1);
        hw_grades = hw_grades([1:drop_index-1 drop_index+1:end]);
        hw_avg = average(hw_grades);
        midterm_avg = average(R(r, 7:9));
        final = R(r, 10);
        if midterm_avg > final
            g(r, 1) = 0.85*midterm_avg + 0.15*hw_avg;
        else
            g(r, 1) = 0.15*R(r, 7) + 0.15*R(r, 8) + 0.15*R(r, 9) + 0.15*midterm_avg + 0.15*hw_avg;
        end
    end
end