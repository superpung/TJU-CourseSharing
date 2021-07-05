`timescale 1ns/1ps

module fulladder(

        input   	A,
	input		B,
	input 		Cin,
	output	 	Sum,
	output 		Cout

	);

	logic [7 : 0] Y;

	_74LS138 U0(.A({A, B, Cin}), .G1(1'b1), .G2_n(1'b0), .G3_n(1'b0), .Y(Y));

	assign Sum	= ~(Y[1] & Y[2] & Y[4] & Y[7]);
	assign Cout 	= ~(Y[3] & Y[5] & Y[6] & Y[7]);


endmodule
