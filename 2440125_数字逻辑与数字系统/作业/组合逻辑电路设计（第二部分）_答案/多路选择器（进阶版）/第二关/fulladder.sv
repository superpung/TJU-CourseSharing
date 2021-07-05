`timescale 1ns/1ps

module fulladder(

        input   	A,
	input		B,
	input 		Cin,
	output	 	Sum,
	output 		Cout

	);

	_74LS253 U0(.D1({Cin, ~Cin, ~Cin, Cin}), .D2({1'b1, Cin, Cin, 1'b0}), .S0(A), .S1(B), .G1_n(1'b0), .G2_n(1'b0), .Y1(Sum), .Y2(Cout));


endmodule
