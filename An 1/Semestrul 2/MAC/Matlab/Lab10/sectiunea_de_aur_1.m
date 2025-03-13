function x=sectiunea_de_aur_1(f,a,b,k)
g= (sqrt(5) - 1) / 2;
for i = 1 : k
    if f(a + (1 - g) * (b - a)) < f(a + g * (b - a))
        b = a + g * (b - a);
    else
        a=a + (1 - g) * (b - a);
    end
end
x=(a+b)/2;
end