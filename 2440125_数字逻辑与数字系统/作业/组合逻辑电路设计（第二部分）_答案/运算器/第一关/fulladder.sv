`timescale 1ns/1ps

module fulladder(

        input   	A,
	input		B,
	input 		Cin,
	output	 	S,
	output 		Cout

	);

	assign S	= A ^ B ^ Cin;
	assign Cout	= (A & B) | ((A ^ B) & Cin);

endmodule
