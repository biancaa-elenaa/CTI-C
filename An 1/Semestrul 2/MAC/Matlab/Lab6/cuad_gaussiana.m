function int=cuad_gaussiana(f,x,c,n)
int=0;
for i=1:n
    int=int+c(i)*f(x(i));
end