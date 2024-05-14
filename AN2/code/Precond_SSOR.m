function z = Precond_SSOR(A, r, premier_passage)
    global L_SSOR U_SSOR D
    
    if premier_passage
        % On ne veut calculer la d�composition ILU qu'une fois : lors du
        % premier passage. On stocke donc le r�sultat dans des variables
        % globales. On stocke L et U plut�t que M (= LU) car z = U \ (L \
        % r) est plus rapide que M \ r
        [L_SSOR, U_SSOR, D] = init_ssor(A);
    end
    z = U_SSOR \ (D * (L_SSOR \ r));
end