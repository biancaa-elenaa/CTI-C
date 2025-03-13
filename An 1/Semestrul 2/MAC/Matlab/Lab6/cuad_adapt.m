function int=cuad_adapt(f,a,b,tol)
c=(a+b)/2;
S1=((b-a)*(f(a)+ f(b))) / 2;
S2= ((f(a) + f(c))*(c - a)) / 2 + ((f(c)+f(b))*(b-c))/2;
if abs(S1-S2) < 3*tol
    int = S2;
else
    int =cuad_adapt(f,a,c,tol/2) + cuad_adapt(f,c,b,tol/2);
end

end