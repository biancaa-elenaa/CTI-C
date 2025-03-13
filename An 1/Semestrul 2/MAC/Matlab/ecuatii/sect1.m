function xc=sect1(f,x0,x1,k)
a=x0;
b=x1;
for i=1:k
    c=(a*f(b) - b*f(a)) / (f(b) - f(a));
    a=b;
    b=c;
end
xc=c;
end