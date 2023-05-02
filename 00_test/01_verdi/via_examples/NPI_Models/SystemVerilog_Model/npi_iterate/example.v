module Counter (input wire  clock, resetN,
                    output logic [15:0]  count);
 
    always @(posedge clock, negedge resetN) begin : B1
        if( !resetN ) count <= 0;
        else  count <= count + 1;
    end
 
endmodule
 
module TEST;
    wire [15:0] count;
    bit clock;
    bit resetN = 1;
 
    Counter dut (clock, resetN, count);
 
    always #10 clock = ~clock;
 
    initial begin
        resetN = 0;
        #2  resetN = 1;
        #1  $finish;
    end
endmodule
