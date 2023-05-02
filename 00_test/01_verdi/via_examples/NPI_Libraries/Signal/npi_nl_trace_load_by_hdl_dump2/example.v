module top;
  wire signed [3:0] wout, wa, wb;
  M m1(wout, wa, wb);
endmodule

module M (out, a, b);
  output [3:0] out;
  input [3:0] a, b;
  wire signed [3:0] out, a, b;
  assign out = a | b;
endmodule
