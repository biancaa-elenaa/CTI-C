function x=gauss_newton(x0,r,Dr,k)
x=x0;
for i=0:k
    A=Dr(x);
    v=(A' * A) \ (- A' * r(x));
    x=x+v;
end
end