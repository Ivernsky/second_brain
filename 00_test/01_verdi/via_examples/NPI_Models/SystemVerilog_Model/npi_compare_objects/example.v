module top;
 
  typedef struct packed {
    bit   [2:0] sa;
    integer     sb;
    logic [1:0] sc;
  } ps;
 
  typedef struct packed {
    bit   [1:0] a;
    logic       b;
    ps          c;
  } st;
 
  reg [1:0] regArr [1:0];
  const integer idx0 = 0;
  parameter p0 = 0;
  integer itg;
  st st1;
 
  initial begin: init_blk
    parameter p1 = 1;
    // left [1]; right [1]
    regArr[1] = regArr[1];
    regArr[idx0+1] = regArr[2'b01];
    regArr[p0+p1] = regArr[p1];
    regArr[p0+1] = regArr[p0+p1];
    // left [0][0]; right [0][0]
    regArr[0][0] = regArr[0][0];
    regArr[0][idx0] = regArr[0][idx0];
    regArr[idx0][0] = regArr[idx0][1-1];
    regArr[p0][p1*0] = regArr[p0][idx0];
    regArr[1'b0][0] = regArr[0][idx0+p0];
    // left == right
    st1.a[0] = st1[38];
    st1.b = st1[37];
    st1.c.sc[0] = st1[0];
    st1.c.sc[0] = st1.c[0];
    st1.c.sb = st1.c[33:2];
    st1.c.sb = st1.c[33-:32];
    st1.c.sb[0] = st1.c[2];
    // compare constant index for bit-select
    itg[1] = itg[2'b01];
    itg[p1] = itg['h1];
  end
 
endmodule
