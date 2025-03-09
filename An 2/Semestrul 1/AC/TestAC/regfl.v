module regfl(input [63:0]d, input [2:0]s,input we, output [511:0]q);
  
  reg [63:0] reg0, reg1, reg2,reg3, reg4, reg5, reg6,reg7;
  
  wire [2:0] write_enable;
  assign write_enable = (we) ? (1 << s) : 3'b000;
  
  always @(posedge we) begin
    if(write_enable[0]) reg0 <= we;
    if(write_enable[1]) reg1 <= we;
    if(write_enable[2]) reg2 <= we;
  end
  
endmodule

module regfl_tb();
  reg [63:0]d;
  reg [2:0]s;
  reg we;
  wire [511:0]q;
  
endmodule