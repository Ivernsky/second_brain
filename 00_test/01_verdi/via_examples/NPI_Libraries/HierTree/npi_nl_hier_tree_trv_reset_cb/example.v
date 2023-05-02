module top;
  wire CLK, RESET, SEL, DIN, DOUT;
  flipflop i_ff (.clk(CLK), .reset(RESET), .sel(SEL), .din(DIN), .dout(DOUT));
endmodule

module flipflop (clk, reset, sel, din, dout);
  input clk, reset, sel;
  input din;
  output reg dout;

  always @(posedge clk or negedge reset) begin
    if (!reset)
      dout <= 1'b0;
    else
      dout <= sel ? din : 1'b1;
  end
endmodule 

