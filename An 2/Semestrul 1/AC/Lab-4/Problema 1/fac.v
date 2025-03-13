module fac(input x,input y,input ci, output z, output co);
  
  assign z = x ^ y ^ ci;
  assign co=(x&y) | (x&ci) | (y&ci);
  
endmodule