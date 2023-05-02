module top;

  wire CLK, RESET;
  wire [7:0] DIN, DOUT;

  M m1(CLK, RESET, DIN, DOUT);
  
endmodule

module M (clk, reset, din, dout);

  input clk, reset;
  input [7:0] din;
  output reg [7:0] dout;

  always @(posedge clk or negedge reset) begin
    if (reset) dout <= 8'b0;
    else       dout <= din;
  end

endmodule
