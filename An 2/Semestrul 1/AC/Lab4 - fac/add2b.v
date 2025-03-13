module add2b(
  input [1:0]x,
  input [1:0]y,
  input ci,
  output [1:0]z,
  output co);

wire c1;

fac fac3(.x(x[0]), .y(y[0]), .ci(ci), .z(z[0]), .co(c1));
fac fac4(.x(x[1]), .y(y[1]), .ci(c1), .z(z[1]), .co(co));

endmodule