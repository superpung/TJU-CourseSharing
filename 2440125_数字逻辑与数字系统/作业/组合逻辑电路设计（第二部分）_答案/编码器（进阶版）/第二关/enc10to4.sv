`timescale 1ns/1ps

module enc10to4 (

	input 		[9 : 0]	I,

	output	logic 	[3 : 0]	F,
	output	logic		valid

	);

	logic 		EN_148;
	logic [2 : 0]	Q;
	logic 		GS_148;
	logic 		EO_148;

	_74LS148 UDT(.I(I[7 : 0]), .EN(EN_148), .Q(Q), .GS(GS_148), .EO(EO_148));

	assign EN_148 = ~(I[9] & I[8]);
	assign valid = {I == 10'b11_1111_1111}? 1'b0 : 1'b1;
	assign F[3] = ~(I[9] & I[8]);
	assign F[2] = ~Q[2];
	assign F[1] = ~Q[1];
	assign F[0] = ~(I[9] & Q[0]);


endmodule
