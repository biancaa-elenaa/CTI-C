function w=eulerstep2(t,w,h)
w=w+h*ydot2(t,w);
end