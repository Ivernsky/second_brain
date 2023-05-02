module Add(a, b, c);
  input a;
  input b;
  output c;
  assign c = a+b;
endmodule

module TOP(clk,w5, w4);
  input  clk;
  wire   w1;
  wire   w2;
  wire   w3;
  output w4;
  output reg w5;
  
  assign w4 = w1;
  
  initial begin
    w5<=1'b1;
  end

  Add inst(w1,w2,w3);
  always@(posedge clk) begin
    w5<=w3;
  end

endmodule
