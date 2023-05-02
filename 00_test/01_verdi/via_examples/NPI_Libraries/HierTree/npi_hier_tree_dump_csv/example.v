module MOD;
  task tsk(output integer y, input integer x);
  endtask
endmodule

module TOP;
  wire a, b;

  and and1[1:0] (a, b);

  generate
    genvar i;
    for(i=0; i<2; i=i+1) begin: gen
      MOD inst();
    end
  endgenerate

  MOD inst2 [1:0] ();
  MOD inst1();
endmodule
