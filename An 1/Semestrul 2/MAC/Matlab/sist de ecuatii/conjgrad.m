function x=conjgrad(A,b,x0,k)
x=x0;
d=b-A*x;
r=b-A*x;
for i=0:k-1
    if r == 0
        break;
    end
    alpha=(r'*r)/(d' * A * d);
    x=x+alpha*d;
    r0=r;
    r=r-alpha*A*d;
    beta=(r'*r)/(r0'*r0);
    d=r+beta*d;
end
end