module bcm(input I1,input I2, input I3, output O1, output O2);
  
  assign O1 = ((I1 & ~I2) | (~I1 & ~I3));
  assign O2 = (~I2) | (~I1 & (~I3)); 
  
endmodule

module bcm_tb();
  reg I1, I2, I3;
  wire O1, O2;
  
  bcm f(.I1(I1), .I2(I2), .I3(I3), .O1(O1), .O2(O2));
  
  integer k;
  
  initial begin
    for(k=0;k<8;k=k+1)
      #20 {I1,I2,I3} = k;
  end
    
endmodule
  