module MOD;
endmodule

module TOP;
  generate
    genvar i;
    for(i=0; i<2; i=i+1) begin: gen
      MOD inst();
      MOD inst2 [3:0] ();
    end
  endgenerate
endmodule
