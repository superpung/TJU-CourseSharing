`timescale 1ns/1ps

module dec4to16 (

	input 		[3 : 0]		A,
	input				en,
	output	logic 	[15 : 0]	Y

	);

	_74LS138 U0(.A(A[2 : 0]), .G1(1'b1), .G2_n(U0_en), .G3_n(U0_en), .Y(Y[7 : 0]));
	_74LS138 U1(.A(A[2 : 0]), .G1(U1_en), .G2_n(1'b0), .G3_n(1'b0), .Y(Y[15 : 8]));

	assign U0_en = (en)? A[3] : 1'b1;
	assign U1_en = (en)? A[3] : 1'b0;


endmodule
