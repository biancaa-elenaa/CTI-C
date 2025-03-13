function w=mijlocstep(t,w,h)
w=w+h*(ydot(t + (h/2),w+(h/2)*ydot(t,w)));
end