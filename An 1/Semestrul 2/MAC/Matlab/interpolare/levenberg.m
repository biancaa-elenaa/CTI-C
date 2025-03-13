function x=levenberg(x0,r,Dr,lambda,k)
x=x0;
for i=0:k
    A=Dr(x);
    v=(A' * A + lambda * diag(diag(A' * A))) \ (-A'*r(x));
    x=x+v;
end