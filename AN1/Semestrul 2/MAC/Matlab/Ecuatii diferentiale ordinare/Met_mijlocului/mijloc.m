function [t,w]=mijloc(interval,y0,n)
t(1)=interval(1);
w(1)=y0;
h=(interval(2) - interval(1)) / n;
for i=1:n
    t(i+1)=t(i)+h;
    w(i+1)=mijlocstep(t(i),w(i),h);
end
plot(t,w)
end