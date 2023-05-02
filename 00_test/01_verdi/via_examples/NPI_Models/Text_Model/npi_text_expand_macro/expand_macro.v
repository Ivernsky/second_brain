`define TOP(a,b) a + b - 1
module main;
 
wire a, b;
initial
  $display( `TOP( `TOP(b,1), `TOP(42,a) ) );
 
endmodule
