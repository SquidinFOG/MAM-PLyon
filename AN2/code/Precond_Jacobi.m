function z = Precond_Jacobi(A, r, ~)
    n = size(A,1);
    M = diag(diag(A));
    
    for i = 1:n
        if M(i,i) == 0
            error('La matrice de pr�conditionnement est mal pos�e');
        end
    end
    
    M = sparse(M);
    M = inv(M);
    z = M \ r;
end