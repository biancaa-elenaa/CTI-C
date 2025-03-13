function y=dif2(f,x,n)
for i=1:n
    h = 10 ^ (-i);
    y(i)=(f(x+h) - f(x)) / h;
end
end

% f=@(x) sin(x) - cos(x);
% syms y
% fsym = sin(y) - cos(y);
% deriv = matlabFunction(diff(fsym));
% e=[dif2(f,0,12) - deriv(0)]
