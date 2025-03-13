function x = gradconj(f,df,x0,k)
d = -df(x0);
r = -df(x0);
x = x0;

for i = 1:k
   alfa = fminbnd(@(alfa) f(x+alfa*d),0,1);
   x = x + alfa*d;
   r1 = r;
   r = -df(x);
   beta = (r'*r)/(r1'*r1);
   d = r + beta*d;
end
end