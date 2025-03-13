function x = newton(Df,Hf,x0,k)
x = x0;

for i = 1:k
    x = x - Hf(x)\Df(x);
end
end