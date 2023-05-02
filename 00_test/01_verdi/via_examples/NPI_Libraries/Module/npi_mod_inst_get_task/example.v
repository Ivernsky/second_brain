module MOD;
  task tsk(output integer y, input integer x, ref reg [7:0][1:0] ref_data);
    assign x = x + 1;
    deassign x;
    x = x + 1;
    y <= x + 2;
  endtask
endmodule

module TOP;
  MOD inst();
endmodule
