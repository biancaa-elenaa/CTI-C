module d_ff(input clk, input rst_b, input set_b, input d, output reg q);
  
  always @ (posedge clk or negedge rst_b or negedge set_b) begin
    if(set_b == 0)
      q <= 1;
    else if(rst_b == 0)
      q <= 0;
    else
      q <= d;
    end

endmodule

module lss5b(input clk, input rst_b, input d, output [4:0]q);
  
  d_ff f0(.clk(clk), .rst_b(1'b1), .set_b(rst_b), .d(q[4]), .q(q[0]));
  d_ff f1(.clk(clk), .rst_b(1'b1), .set_b(rst_b), .d(q[0]), .q(q[1]));
  d_ff f2(.clk(clk), .rst_b(1'b1), .set_b(rst_b), .d(q[1]), .q(q[2]));
  d_ff f3(.clk(clk), .rst_b(1'b1), .set_b(rst_b), .d(q[2] | q[4]), .q(q[3]));
  d_ff f4(.clk(clk), .rst_b(1'b1), .set_b(rst_b), .d(q[3] ^ q[4]), .q(q[4]));  
  
endmodule
