function x=newton(F,DF,x0,k)
x=x0;
for i=0:k
    x=x-inv(DF(x))*F(x);
end
end
