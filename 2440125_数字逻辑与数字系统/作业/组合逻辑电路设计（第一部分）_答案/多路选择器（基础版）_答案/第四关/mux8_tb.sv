`timescale 1ns/1ps
module mux8_tb();

	logic [7 : 0] D;
	logic [2 : 0] sel;
	logic Y;

	integer i;

	mux8 UDT(.D(D), .sel(sel), .Y(Y));

	initial begin

		D = 8'b10110101;
		for(i = 0; i < 8; i = i+1) begin
			sel = i;
			#20;
		end

	end

        initial begin
		$timeformat(-9, 0, "ns", 5);
		$monitor("At time %t: D = %b, sel = %b, Y = %d", $time, D, sel, Y);
	end

	initial begin
		
		$dumpfile("mux8.vcd");
		$dumpvars(0, mux8_tb);

	end

endmodule
