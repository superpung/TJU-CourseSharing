`timescale 1ns/1ps

module mux8(

	input		[7 : 0] 	D,
    input   	[2 : 0] 	sel,
	output   				Y

	);
	
	logic mux0_out, mux1_out;

	mux4 U0(.D(D[3:0]), .sel(sel[1:0]), .Y(mux0_out));
	mux4 U1(.D(D[7:4]), .sel(sel[1:0]), .Y(mux1_out));
	         
	mux2 U2(.D({mux1_out, mux0_out}), .sel(sel[2]), .Y(Y));


endmodule
