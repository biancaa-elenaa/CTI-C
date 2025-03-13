function xc=bisect(f,a,b,tol)
if f(a)*f(b)>=0
    error('stop');
end
while (b-a)/2>tol
    c=(a+b)/2;
    if f(c) == 0
       break;
    end
    if f(a)*f(c) < 0
        b=c;
    else
        a=c;
    end
end
xc=(a+b)/2;
end