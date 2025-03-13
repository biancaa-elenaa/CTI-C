function x=srs(A,b,x0,w,k)
x=x0;
D=diag(diag(A));
L=tril(A)-D;
U=triu(A)-D;
for i=0:k
    x=inv(w*L+D)*[(1-w)*D*x-w*U*x]+w*inv(D+w*L)*b;
end
end