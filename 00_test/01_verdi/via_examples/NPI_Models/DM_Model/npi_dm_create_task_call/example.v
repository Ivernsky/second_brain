module m;
  task task1 ();
  endtask
endmodule

module top;

  task task1( input logic f_a = 10, input logic f_b = 5 );
  endtask

  task task2 ( input [7:0] x = 10, y = 3, event z );
  endtask

  task task3 ();
  endtask

  logic a;
  logic b;
endmodule
