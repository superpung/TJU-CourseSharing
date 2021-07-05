`timescale 1ns/1ps

module hex7seg_tb( );

	logic [3 : 0] x;
	logic [6 : 0] a_to_g;

	integer i;

	hex7seg UDT(.x(x), .a_to_g(a_to_g));

	initial begin

		for(i = 0; i < 16; i = i + 1) begin
			x = i;
			#20;
		end

	end

	initial begin
		$timeformat(-9, 0, "ns", 5);
		$monitor("At time %t: x = %b, a_to_g = %b", $time, x, a_to_g);
	end

	initial begin
		
		$dumpfile("hex7seg.vcd");
		$dumpvars(0, hex7seg_tb);

	end

endmodule
