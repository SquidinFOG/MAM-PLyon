function [L, U, D] = init_ssor(A)
    % Pr�conditionnement SSOR
    D = diag(diag(A));
    L = tril(A, -1);
    U = triu(A, 1);
    w_opt = 1.7; % recommendation du prof. Apparement il existe une formule
    % pour obtenir une valeur approch�e de w_opt mais je ne la trouve pas
    
    L = (D + w_opt * L);
    U = (D + w_opt * U);
end