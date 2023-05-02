
`ifdef AAA

module AAA (input ai, output ao);
  assign ao = ai;
endmodule

`elsif BBB

module BBB (input bi, output bo);
  assign bo = bi;
endmodule

`else

module CCC (input ci, output co);
  assign co = ci;
endmodule

`endif

