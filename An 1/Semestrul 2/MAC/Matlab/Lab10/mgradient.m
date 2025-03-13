function x = mgradient(f,Df,x0,k)
x = x0;

for i = 1:k
    v = Df(x);
    s = fminbnd(@(s) f(x-s*v),0,1);
    x = x - s*v;
end
end