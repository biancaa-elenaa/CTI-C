function rez = simpson_comp(f,a,b,m)
rez = 0;
h=(b-a)/(2*m);
s1=0;
s2=0;
for i=1:m
    s1=s1+f(a+(2*i-1)*h);
end

for i=1:m-1
    s2=s2+f(a+2*i*h);
end

rez = (h / 3) * (f(a) + f(b) + 4 * s1 + 2 * s2);
end