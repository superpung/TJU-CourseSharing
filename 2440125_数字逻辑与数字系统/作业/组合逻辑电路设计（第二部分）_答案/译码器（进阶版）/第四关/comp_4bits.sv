`timescale 1ns/1ps

module comp_4bits (

	input 		[3 : 0]	A,
	input 		[3 : 0]	B,

	output	logic 		EQ

	);

	logic	[7 : 0]	Y0, Y1;
	logic 		F0, F1;
	logic 		F0_n, F1_n;

	_74LS138 U0(.A(A[2 : 0]), .G1(1'b1), .G2_n(A[3]), .G3_n(1'b0), .Y(Y0));
	_74LS138 U1(.A(A[2 : 0]), .G1(A[3]), .G2_n(1'b0), .G3_n(1'b0), .Y(Y1));

	_74LS151 U2(.sel(B[2 : 0]), .D(Y0), .G_n(B[3]), .F(F0), .F_n(F0_n));
	_74LS151 U3(.sel(B[2 : 0]), .D(Y1), .G_n(~B[3]), .F(F1), .F_n(F1_n));

	assign EQ = F0_n & F1_n;


endmodule
