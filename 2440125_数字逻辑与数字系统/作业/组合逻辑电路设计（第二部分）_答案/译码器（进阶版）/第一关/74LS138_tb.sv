`timescale 1ns/1ps

module _74LS138_tb();

	logic	[2 : 0] A;
	logic		G1, G2_n, G3_n;
	logic	[7 : 0] Y;

	integer i;

	_74LS138 UDT(.A(A), .G1(G1), .G2_n(G2_n), .G3_n(G3_n), .Y(Y));

	initial begin
		A 	= 8'b000;
		G1 	= 1'b0;
		G2_n 	= 1'b0;
		G3_n 	= 1'b0;
		#20;
		G1 	= 1'b1;
		G2_n 	= 1'b1;
		G3_n 	= 1'b0;
		#20
		G1 	= 1'b1;
		G2_n 	= 1'b0;
		G3_n 	= 1'b1;
		#20
		G1 	= 1'b1;
		G2_n 	= 1'b0;
		G3_n 	= 1'b0;
		for (i = 0; i < 7; i = i + 1) begin
			#20;
			A = A + 1;
		end
	end

	initial begin
		$timeformat(-9, 0, "ns", 5);
		$monitor("At time %t: G1 = %b, G2_n = %b, G3_n = %b, A = %b, Y = %b", $time, G1, G2_n, G3_n, A, Y);
	end

	initial begin

		$dumpfile("74LS138.vcd");
		$dumpvars(0, _74LS138_tb);

	end

endmodule
