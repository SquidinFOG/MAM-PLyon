function [L, U] = init_ilu(A)
    [L, U] = ilu(A, struct('type', 'ilutp', 'droptol', 1e-6));
end