module test (a, b, c);
/* line 2 is redundant */
  input a, b;
  output c;
  wire c;
 
  and and_gate (c, a, b);
endmodule
