`include "file_to_be_included.v"

module test (a, b, c);
  input a, b;
  output c;
  wire c;
 
  myand and_gate (c, a, b);
endmodule
