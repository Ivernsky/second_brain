module m;
  function func1();
    return 10;
  endfunction
endmodule

module top;
  function func1( input logic f_a = 10, input logic f_b = 5 );
    func1 = f_a + f_b;
  endfunction

  function [15:0] func2 ( input [7:0] x = 10, y = 3, event z );
    func2 = x * y - 1;
  endfunction

  function func3();
    return 1;
  endfunction

  logic a;
  logic b;
  reg c;
  logic [15:0] d;
endmodule
