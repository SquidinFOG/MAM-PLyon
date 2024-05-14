function z = Precond_ILU(A, r, premier_passage)
    global L_ILU U_ILU
    
    if premier_passage
        % On ne veut calculer la décomposition ILU qu'une fois : lors du
        % premier passage. On stocke donc le résultat dans des variables
        % globales. On stocke L et U plutôt que M (= LU) car z = U \ (L \
        % r) est plus rapide que M \ r
        [L_ILU, U_ILU] = init_ilu(A);
    end
    z = U_ILU \ (L_ILU \ r);
end