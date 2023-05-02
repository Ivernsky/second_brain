module Add(a, b, c);
  input a;
  input b;
  output c;
  assign c = a+b;
endmodule

module TOP(clk, w4);
  input  clk;
  wire   w1;
  wire   w2;
  reg    w3;
  output w4;
  reg w5,w6;
  reg [1:0] w7;

  assign {w5,w6} = w7;

  assign w4 = w1*w2;
  assign w7[0] = w1 ? 1'bz : w1;

  initial begin
    w3<=1'b1;
  end

  Add inst(w1,w2,w3);

  always@(posedge clk) begin
    w7[1]<=w3;
  end
endmodule
