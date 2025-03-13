function rez=mij_comp(f,a,b,m)
rez=0;
h=(b-a)/m;
for i=1:m
    rez = rez + f(a+((2*i - 1)*h)/2);
end
rez = h * rez;
end