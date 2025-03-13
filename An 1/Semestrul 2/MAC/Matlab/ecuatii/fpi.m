function x=fpi(g,x0,k)
x=x0;
for i=0:k
    x=g(x);
end
end
