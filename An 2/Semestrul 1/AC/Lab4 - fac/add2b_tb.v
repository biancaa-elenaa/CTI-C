module add2b_tb;
  reg [1:0]x;
  reg [1:0]y;
  reg ci;
  
  wire [1:0]z;
  wire co;
  
  
  add2b f(.x(x), .y(y), .ci(ci), .z(z), .co(co));
  integer i;
  initial begin
  for(i=1;i<32;i=i+1)
  begin
    #30 {x,y,ci}=i;
  end
  end
  
endmodule