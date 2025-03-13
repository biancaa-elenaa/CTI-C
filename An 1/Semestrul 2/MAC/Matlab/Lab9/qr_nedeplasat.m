function lambda=qr_nedeplasat(A,k)
[m,n]=size(A);
Q=eye(m,m);
R=A;
for i=1:k
    [Q,R]=qr(R*Q);
end
lambda = diag(R*Q);
end