function rez=trapez_comp(f,a,b,m)
rez=0;
h=(b-a)/m;
for i=1:m+1
    y(i)=f(a+(i-1)*h);
    if i==1 || i==m+1
        rez = rez + y(i);
    else
        rez = rez + 2 * y(i);
    end
end
rez= (h / 2) * rez;

end

% f=@(x) x./sqrt(x.^2 + 9);
% e1=integral(f,0,4) - integrala calculata
% e2=trapez_comp(f,0,4,16)
% e = e2-e1 - eroarea