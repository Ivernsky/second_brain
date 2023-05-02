module MOD;
  task tsk(output integer y, input integer x);
    begin
      integer tsk_var;
      for (int fvar = 0; fvar < 2; fvar++)
        $display("For scope");
      fork
        integer fork_var;
        $display("fork");
        fork: nf
          $display("named fork");
        join
      join
    end
  endtask

  function add_func(input int x, input int y);
    add_func = x + y;
  endfunction
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

  initial begin: init_blk
  end

endmodule
