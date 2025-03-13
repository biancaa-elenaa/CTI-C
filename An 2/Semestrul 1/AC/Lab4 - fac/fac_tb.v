module fac_tb;
  reg x;
  reg y;
  reg ci;
  
  wire z;
  wire co;
  
  fac fac1(.x(x), .y(y), .ci(ci), .z(z), .co(co));
  
  integer i;
  
  initial begin
    {x,y,ci} = 0;
    
    for(i=0;i<8;i=i+1)
      #20 {x,y,ci} = i;
        
  end
  
endmodule