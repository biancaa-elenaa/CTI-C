function x = broyden(F, x0, k)

n = length(x0);

A = eye(n,n); 
% asta face 1 pe diagonala principala


for i = 1 : k
    x = x0 - inv(A) * F(x0);
    
    gama = x - x0;

    delta = F(x) - F(x0);

    A = A + ((delta - A * gama) * gama') / (gama' * gama);

    x0 = x;
end
