function [A,x]=gauss(A,b)
n=length(A);
for j=1:n-1
    if A(j,j) == 0
        error('stop');
    end
    for i=j+1:n
        m=A(i,j)/A(j,j);
        for k=j+1:n
        A(i,k)=A(i,k)-m*A(j,k);
        end
        b(i)=b(i)-m*b(j);
    end
end
for i=n:-1:1
    for j=i+1:n
        b(i)=b(i)-A(i,j)*x(j);
    end
    x(i)=b(i)/A(i,i);
end
end

