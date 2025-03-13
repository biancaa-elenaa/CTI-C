function rez=trapez_comp1(f,a,b,m)
rez=0;
h=(b-a)/m;
for i=1:m-1
    rez= rez + f(a+i*h);
end
rez= (h / 2) * ( f(a) + f(b) + 2 * rez);

end

% f=@(x) x.^2.*sin(x);
% e1=integral(f,0,pi)
% e2=trapez_comp1(f,0,pi,16)
% e=e2-e1