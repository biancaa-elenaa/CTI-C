function y=dif3(f,x,n)

for i=1:n
    h=10^(-i);
    y(i)=(f(x+h) - f(x-h)) / (2*h);
end
end
% f=@(x) sin(x) - cos(x);
% syms y
% fsym = sin(y) - cos(y);
% deriv = matlabFunction(diff(fsym));
% e=[dif3(f,0,12) - deriv(0)]

