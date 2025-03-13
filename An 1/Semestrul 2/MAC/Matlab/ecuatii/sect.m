function xc=sect(f,x0,x1,k)
a=x0;
b=x1;
for i=2:k
  c= (f(b)*a - f(a)*b)/(f(b)-f(a));
  a=b;
  b=c;
end
xc=c;
end
