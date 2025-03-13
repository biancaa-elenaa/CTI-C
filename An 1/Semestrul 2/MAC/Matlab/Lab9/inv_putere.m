function [lambda,u]=inv_putere(A,x,s,k)
for i=1:k
    u=x/norm(x);
    x=(A-s*eye(size(A))) \ u;
    lambda = u' * x;
end
u=x/norm(x);
lambda=1/lambda + s;
end