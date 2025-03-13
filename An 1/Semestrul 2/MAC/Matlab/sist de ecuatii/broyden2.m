function x=broyden2(F,x0,k)
n=length(x0);
B=eye(n);
for i=0:k
    x=x0-B*F(x0);
    gama=x-x0;
    delta=F(x)-F(x0);
    B=B+(gama-B*delta)*gama'*B/(gama'*B*delta);
    x0=x;
end
end