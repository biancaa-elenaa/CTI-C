KE = 1000;
Tp = 60;
Kp = 500;
Kc = 125;
Tc = 300;

A = [-(1/Tp) 1/Tp; Kp/(Kc*Tc) -((1+(Kp/Kc))/Tc)];
B = [KE/(Kp*Tp) 0;0 1/Tc];
C = [1 0;0 1];
D = [0 0;0 0];