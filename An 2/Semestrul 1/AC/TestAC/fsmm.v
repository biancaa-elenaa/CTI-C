module fsmm(input clk, input rst_b, input a, input b, output reg m, output reg n);
  
  localparam S0 = 5'b00001;
  localparam S1 = 5'b00010;
  localparam S2 = 5'b00100;
  localparam S3 = 5'b01000;
  localparam S4 = 5'b10000;
  
  reg [4:0] st;
  reg [4:0] st_nxt;
  
  always @ (posedge clk, negedge rst_b)
    if(!rst_b)
      st <= S0;
    else
      st <= st_nxt;
  
  always @(*) begin
    st_nxt = S1;
    n=0;
    m=0;
    case(st)
      S0: begin
            if(~a) 
              st_nxt = S0;
            else if(a & ~b) begin
              st_nxt = S1;
              n=1;
            end
            else if( a & b)
              st_nxt = S4;
              m=1;
          end
      S1: begin
            st_nxt = S2;
            m=1;
            n=1;
          end
      S2: begin
            if(~a) begin
              n=1;
              st_nxt=S4;
            end
            else if(a) begin
              m=1;
              st_nxt=S3;
            end
          end
      S3: begin
            if(a & ~b)
              st_nxt = S3;
            else if(~a & b) begin
              st_nxt = S3;
              m=1;
              n=1;
            end
            else if(a & b)
              st_nxt = S4;
            else if(~a & ~b) begin
              st_nxt = S0;
              m=1;
              n=1;
            end
          end
      S4: begin
            if(~b) begin
              st_nxt = S4;
              n=1;
            end
            else if(b) begin
              st_nxt = S1;
              m=1;
              n=1;
            end
          end
      
    endcase
  end
   
endmodule

module fsmm_tb();
  reg clk, rst_b, a,b;
  wire m,n;
  
  fsmm f(.clk(clk), .rst_b(rst_b), .a(a), .b(b), .m(m), .n(n));
  
  localparam CLK_P = 100;
  localparam CLK_CY = 10;

  initial begin
    clk = 0;
    repeat (CLK_CY) # CLK_P clk = ~clk;
  end
  
  initial begin
    rst_b=0;
    #50 rst_b=1;
  end
  
  //a
  initial begin
    a=0;
    #(2*CLK_P ) a=1;
    #(5*CLK_P) a=0;
  end
  
  initial begin 
    b=0;
    #(CLK_P/2) b=1;
    #(CLK_P + CLK_P/2) b=0;
    #(CLK_P + CLK_P/2) b=1;
    #(CLK_P) b=0;
    #(CLK_P) b=1;
    #(CLK_P*2) b=0;
  end
  
endmodule
            
      
      
        
        
    
      