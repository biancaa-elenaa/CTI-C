function w=trapezstep(t,w,h)
w=w+(h/2)*(ydot1(t,w)+ydot1(t+h,w+h*ydot1(t,w)));
end